// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
package leetcode1309
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
			"10#11#12",
			"jkab",
		},
		{
			"1326#",
			"acz",
		},
		{
			"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#",
			"abcdefghijklmnopqrstuvwxyz",
		},
		{
			"25#",
			"y",
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, freqAlphabets(tc.input), tc.ans)
	}
}
