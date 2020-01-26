// https://leetcode.com/problems/defanging-an-ip-address
package leetcode1108

import (
	"strings"
)

/*

 */
func defangIPaddr(address string) string {
	// return strings.Replace(address, ".", "[.]", -1)

	return replace(address, ".", "[.]")
}

func replace(s string, old, new string) string {
	if old == new {
		return s
	}

	// Compute number of replacements.
	m := strings.Count(s, old)
	if m == 0 {
		return s
	}

	// Apply replacements to buffer.
	t := make([]byte, len(s)+m*(len(new)-len(old)))

	w := 0
	start := 0
	for i := 0; i < m; i++ {
		j := start
		j += strings.Index(s[start:], old)

		w += copy(t[w:], s[start:j])
		w += copy(t[w:], new)
		start = j + len(old)
	}
	w += copy(t[w:], s[start:])
	return string(t[0:w])
}
