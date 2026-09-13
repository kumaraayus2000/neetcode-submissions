class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Using sets to track seen numbers for rows, columns, and 3x3 boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        // Iterate over all cells in the 9x9 board
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];

                // Skip empty cells
                if(c == '.') continue;

                // Check if number already exists in the current row
                if(rows[i].count(c)){
                    return false; // Invalid Sudoku
                }
                rows[i].insert(c); // Mark number as seen in the row

                // Check if number already exists in the current column
                if(cols[j].count(c)){
                    return false; // Invalid Sudoku
                }
                cols[j].insert(c); // Mark number as seen in the column

                // Compute the index of the 3x3 box
                // (i/3)*3 gives row block index, j/3 gives column block index
                int boxIndex = (i / 3) * 3 + j / 3;

                // Check if number already exists in the current 3x3 box
                if(boxes[boxIndex].count(c)){
                    return false; // Invalid Sudoku
                }
                boxes[boxIndex].insert(c); // Mark number as seen in the box
            }
        }

        return true; // All checks passed, Sudoku is valid
    }
};
