// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
package leetcode1275
/*
	
 */

 func tictactoe(moves [][]int) string {
	/*
	score of tow players, score[0] for 'A', score[1] for 'B'
	every player has 8 scores, 3 rows, 3 cols and 2 cross
	*/
	score := make([][]int, 2)
	for i := 0; i < 2; i++ {
		score[i] = make([]int, 8)
	}
	player := 0
	for _, move :=range moves {
		score[player][move[0]]++
		score[player][move[1] + 3]++
		// 
		score[player][6] += btoi(move[0] == move[1])
		score[player][7] += btoi(move[0] + move[1] == 2)
		for _, x := range score[player] {
			if x == 3 {
				if player == 0 {
						return "A"
				} else {
						return "B"
				}
			}
		}
    player ^= 1
	}
	if len(moves) == 9 {
		return "Draw"
	}
	return "Pending"
}
func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}