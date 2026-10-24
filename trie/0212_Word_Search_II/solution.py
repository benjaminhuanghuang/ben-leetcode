class Trie:
    def __init__(self):
        self.children = {}
        self.flag = False
        self.hasWord = False

    def put(self, key):
        if key == '':
            self.flag = True
            self.hasWord = True
            return

        if key[0] not in self.children:
            self.children[key[0]] = Trie()
        self.children[key[0]].put(key[1:])
        self.hasWord = True

    def pop(self, key):
        if key == '':
            self.flag = False
            self.hasWord = False
            return
        if key[0] not in self.children:
            return
        self.children[key[0]].pop(key[1:])
        # if any child.hasWord is true
        self.hasWord = any([child.hasWord for child in self.children.values()])

    def has(self, key):
        if key == '':
            return self.flag

        if not self.hasWord:
            return False
        if key[0] not in self.children:
            return False
        return self.children[key[0]].has(key[1:])


class Solution(object):
    DIRECT_X = [1, 0, 0, -1]
    DIRECT_Y = [0, 1, -1, 0]

    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        trie = Trie()
        for word in words:
            trie.put(word)

        self.results = {}
        for row in range(len(board)):
            for col in range(len(board[0])):
                self.search(trie, trie, board, row, col, [])
        return self.results.keys()

    def search(self, root, trie, board, x, y, chars):
        char = board[x][y]
        if char not in trie.children:
            return
        chars.append(char)
        trie = trie.children[char]
        if trie.flag:
            self.results[''.join(chars)] = True
            root.pop(''.join(chars))

        board[x][y] = '.'
        for i in range(4):
            r = x + self.DIRECT_X[i]
            c = y + self.DIRECT_Y[i]
            if r < 0 or r == len(board) or c < 0 or c == len(board[0]):
                continue
            self.search(root, trie, board, r, c, chars)
        board[x][y] = char
        chars.pop()
