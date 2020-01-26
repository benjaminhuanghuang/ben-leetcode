// https://leetcode.com/problems/defanging-an-ip-address
package leetcode1108
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input string
		ans   string
	}{
		{
			"1.1.1.1",
			"1[.]1[.]1[.]1",
		},
		{
			"255.100.50.0",
			"255[.]100[.]50[.]0",
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, defangIPaddr(tc.input), tc.ans)
	}
}
