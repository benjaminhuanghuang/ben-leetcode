import os
import re

# third-party
from bs4 import BeautifulSoup
import requests

# CHANGE TO YOUR OWN ACCOUNT INFO
NAME = 'admin'
PASSWORD = 'admin'

DIR_NAME = 'Leetcode-archive'
client = requests.session()

suffix = {'cpp': 'cpp', 'cplusplus': 'cpp', 'c++': 'cpp', 'c': 'c',
          'java': 'java', 'python': 'py', 'py': 'py', 'c#': 'cs',
          'csharp': 'cs', 'javascript': 'js', 'js': 'js', 'ruby': 'rb',
          'rb': 'rb', 'go': 'go', 'golang': 'go', 'swift': 'swift'}

#       DEBUG       #
DEBUG = False
n = 1
#       DEBUG       #


def login(name=None, pwd=None):
    login_url = 'https://leetcode.com/accounts/login/'

    if name is not None and pwd is not None:
        client.get(login_url)
        csrftoken = client.cookies['csrftoken']

        data = dict(
            login=NAME,
            password=PASSWORD,
            csrfmiddlewaretoken=csrftoken)
        headers = dict(Referer=login_url)

        login_response = client.post(login_url, data=data, headers=headers)
        if login_response.status_code == 200:
            print('Login success.')
            return 200
    print('Login failed.')
    return None


def get_problems_info():
    url = 'https://leetcode.com/api/problems/algorithms/'
    response = client.get(url)
    response.raise_for_status()
    return response.json()


def get_ac_problems_info():
    ac_problems = []
    url_base = 'https://leetcode.com/'

    # get problems info first
    d = get_problems_info()

    global n    # for debug

    for p in d['stat_status_pairs']:
        #       DEBUG       #
        if DEBUG:
            if n <= 0:
                break
            n -= 1
        #       DEBUG       #

        # construct problem submission url
        url = '{}problems/{}/submissions/'.format(
            url_base, p['stat']['question__title_slug'])

        response = client.get(url)
        response.raise_for_status()

        # find accepted answer
        soup = BeautifulSoup(response.text.encode('utf-8'), 'html.parser')
        submissions = soup.find_all('strong', text='Accepted')

        if len(submissions) > 0:
            p_info = {
                "url": url_base + submissions[0].parent['href'],
                "id": p['stat']['question_id'],
                "title": p['stat']['question__title_slug']
            }
            ac_problems.append(p_info)
        else:
            print('No Accepted codes found for "{}"'.format(
                p['stat']['question__title']))

    return ac_problems


def suffix_conversion(suff='cpp'):
    if suff in suffix:
        return suffix[suff]


def get_ac_code():
    '''
    get accepted codes for all problems, then dump info file
    '''
    ac_problems = get_ac_problems_info()
    n_writes = 0

    # prepare directory to write
    if not os.path.exists(DIR_NAME):
        os.mkdir(DIR_NAME)
    os.chdir(DIR_NAME)

    for info in ac_problems:
        # fire request
        response = client.get(info['url'])
        response.raise_for_status()

        soup = BeautifulSoup(response.text.encode('utf-8'), 'html.parser')
        script = soup.find('script', text=re.compile('submissionCode:'))

        c = re.findall(
            "submissionCode:\s*'(.+)'",
            script.string)[0].decode('unicode-escape')
        suff = suffix_conversion(re.findall("getLangDisplay:\s*'(.+)'",
                                            script.string)[0])

        f = open('{}.{}'.format(info['title'], suff), 'w')
        f.write(c)
        f.close()
        n_writes += 1
        print('"{}"" downloaded'.format(info['title']))

    print('---------------\n{} file{} downloaded.'.format(
        n_writes, 's' if n_writes > 1 else ''))


if __name__ == '__main__':
    if login(NAME, PASSWORD) is not None:
        get_ac_code()