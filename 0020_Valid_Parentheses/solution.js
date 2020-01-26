var isValid = function (s) {
  var pairs = {
    "(": ")",
    "{": "}",
    "[": "]"
  }
  var stack = []
  for (var i = 0; i < s.length; i++) {
    if (s[i] in pairs) {
      stack.push(s[i])
    }
    else {
      var current = stack.pop()
      if (pairs[current] !== s[i]) {
        return false
      }
    }
  }
  return stack.length === 0
};