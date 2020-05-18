class Solution {
    int m = 3;

   public:
    bool valid(vector<char> vec) {
        vector<int> cnt(m * m, 0);
        for (char c : vec)
            if (isdigit(c))
                cnt[c - '1']++;
        for (int c : cnt)
            if (c > 1) return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                vector<char> tmp;
                for (int r = 0; r < m; r++)
                    for (int s = 0; s < m; s++)
                        tmp.emplace_back(board[m * i + r][m * j + s]);
                if (!valid(tmp)) return false;
            }
        }
        for (int i = 0; i < m * m; i++) {
            vector<char> tmp = board[i];
            if (!valid(tmp)) return false;
        }
        for (int i = 0; i < m * m; i++) {
            vector<char> tmp;
            for (int j = 0; j < m * m; j++)
                tmp.emplace_back(board[j][i]);
            if (!valid(tmp)) return false;
        }
        return true;
    }
};