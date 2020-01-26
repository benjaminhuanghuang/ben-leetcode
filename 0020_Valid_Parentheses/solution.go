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
			top ++
		case '{':
			stack[top] = '}'
			top ++
		case '[':
			stack[top] = ']'
			top ++
		default: // ')', '}' , ']'
			if top == 0 || stack[top-1] != c {
				return false
			}
			top --
		}
	}

	return top == 0
}