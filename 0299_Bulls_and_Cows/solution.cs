/*
299. Bulls and Cows

*/

public class Solution299 {
    public string GetHint(string secret, string guess) {
        if (secret == null || guess == null || secret.Length != guess.Length) {
            return "";
        }
        
        int countA = 0;
        int countB = 0;
        int[] count = new int[10];
        
        for (int i = 0; i < secret.Length; i++) {
            if (secret[i] == guess[i]) {
                countA++;
            } 
            else 
            {
                count[secret[i] - '0']++;
                if (count[secret[i] - '0'] <= 0) {
                    countB++;
                }
                count[guess[i]- '0']--;
                if (count[guess[i]- '0'] >= 0) {
                    countB++;
                }
            }
        }
        
         return countA.ToString() + "A" + countB.ToString() + "B";
    }
}