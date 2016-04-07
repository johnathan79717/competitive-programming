public class Solution {
    boolean[][] used;
    char[][] board;
    String word;
    public boolean exist(char[][] board, String word) {
        if(word.length() == 0) return true;
        used = new boolean[board.length][board[0].length];
        this.board = board;
        this.word = word;
        for(int i = 0; i < board.length; i++)
            for(int j = 0; j < board[i].length; j++)
                if(search(0, i, j))
                    return true;
        return false;
    }
    public boolean search(int n, int i, int j) {
        if(n == word.length())
            return true;
        if(i < 0 || i >= board.length || j < 0 || j >= board[i].length || used[i][j] || board[i][j] != word.charAt(n))
            return false;
        used[i][j] = true;
        if(search(n + 1, i + 1, j) || search(n + 1, i, j + 1) || search(n + 1, i - 1, j) || search(n + 1, i, j - 1))
            return true;
        used[i][j] = false;
        return false;
    }
}