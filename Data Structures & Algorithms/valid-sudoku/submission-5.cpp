class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> rows(9),cols(9),boxes(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                 if(c == '.') continue;
                if(rows[i].count(c)){
                    return false;
                }
                rows[i].insert(c);

                if(cols[j].count(c)){
                    return false;
                }
                cols[j].insert(c);

                int boxindex = (i/3) * 3 + j/3;

                if(boxes[boxindex].count(c)){
                    return false;
                }
                boxes[boxindex].insert(c);

            }
        }
        return true;
    }
};
