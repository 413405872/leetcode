class Solution {
public:
    bool search(vector<vector<char> > &board, string &word, vector<vector<bool> > &mask, int idx, int x, int y) {
         if (word[idx] == board[x][y])
         {
             ++idx;
             if (idx == word.length())return true;
         } 
         else return false;
         mask[x][y] = false;
         bool flag1, flag2, flag3, flag4;
         flag1 = flag2 = flag3 = flag4 = false;
         if (y + 1 < board[0].size() && mask[x][y+1] && board[x][y+1] == word[idx]) {
             if (search(board, word, mask, idx, x, y + 1))
                 return true;
         }
         if (x + 1 < board.size() && mask[x+1][y] && board[x+1][y] == word[idx]) {
             if (search(board, word, mask, idx, x + 1, y))
                 return true;
         }
         if (x - 1 >= 0 && mask[x-1][y] && board[x-1][y] == word[idx]) {
            if (search(board, word, mask, idx, x - 1, y))
                 return true;
         }
         if (y - 1 >= 0 && mask[x][y-1] && board[x][y-1] == word[idx]) {
            if (search(board, word, mask, idx, x, y - 1))
                return true;
         }
         mask[x][y] = true;
         return false;
     }
     
     bool exist(vector<vector<char> > &board, string word) {
         vector<vector<bool> > mask(board.size(), vector<bool>(board[0].size(), true));
         if (board.size() < 1) return false;
         for (int i = 0; i <board.size(); ++i) {
             for (int j = 0; j < board[0].size(); ++j) {
                 if (board[i][j] == word[0] && search(board, word, mask, 0, i, j)) {
                     return true;
                 }
             }
         }
         return false;
     }
};