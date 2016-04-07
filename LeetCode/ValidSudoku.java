public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                for(int k = 0; k < 9; k++)
                    if((k != j && board[i][k] == board[i][j]) || (k != i && board[k][j] == board[i][j]))
                        return false;
                for(int a = 0; a < 3; a++)
                    for(int b = 0; b < 3; b++)
                        if((a != i % 3 || b != j % 3) && board[i-i%3+a][j-j%3+b] == board[i][j])
                            return false;
            }
        return true;
    }
}