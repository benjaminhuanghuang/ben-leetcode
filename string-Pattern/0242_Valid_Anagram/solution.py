def is_anagram(s, t):
    return sorted(s) == sorted(t)


def isAnagram(self, s, t):
  """
  :type s: str
  :type t: str
  :rtype: bool
  """
  if len(s) != len(t):
      return False

  alpha = [0] * 26
  for c in s:
      alpha[ord(c) - 97] += 1
  for c in t:
      alpha[ord(c) - 97] -= 1
      if alpha[ord(c) - 97] < 0:
          return False
  return True

def isAnagram_unicode( s, t):
    if len(s) != len(t):
        return False

    alpha = {}
    beta = {}
    for c in s:
      alpha[c] = alpha.get(c, 0) + 1
    for c in t:
      beta[c] = beta.get(c, 0) + 1
    return alpha == beta
