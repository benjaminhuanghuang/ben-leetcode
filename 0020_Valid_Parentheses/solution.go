// https://leetcode.com/problems/valid-parentheses
package leetcode0020

/*

 */
func isValid(s string) bool {
	stack := make([]rune, len(s))
	top := 0

	for _, c := range s {
		switch c {
		case '(':
			stack[top] = ')'
			top++
		case '{':
			stack[top] = '}'
			top++
		case '[':
			stack[top] = ']'
			top++
		default: // ')', '}' , ']'
			if top == 0 || stack[top-1] != c {
				return false
			}
			top--
		}
	}

	return top == 0
}

func isValid2(s string) bool {
	// 空字符串直接返回 true
	if len(s) == 0 {
		return true
	}
	stack := make([]rune, 0)
	pairs := map[rune]rune{']': '[', '}': '{', ')': '('}
	for _, v := range s {
		if (v == '[') || (v == '(') || (v == '{') {
			stack = append(stack, v)
		} else if (v == ']') && len(stack) > 0 && stack[len(stack)-1] != pairs[v] {
			return false
		} else {

			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}
