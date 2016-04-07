public class Solution {
    public void solveSudoku(char[][] board) {
        dfs(board);
    }
    public boolean dfs(char[][] board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        board[i][j] = c;
                        if(isValidSudoku(board, i, j) && dfs(board))
                            return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board, int i, int j) {
        for(int k = 0; k < 9; k++)
            if(k != i && board[k][j] == board[i][j] || k != j && board[i][k] == board[i][j])
                return false;
        for(int a = 0; a < 3; a++)
            for(int b = 0; b < 3; b++)
                if(a != i % 3 && b != j % 3 && board[i-i%3+a][j-j%3+b] == board[i][j])
                    return false;
        return true;
    }
}