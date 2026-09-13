class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Step 1: Create sets to store the indices of rows and columns that contain a 0
        unordered_set<int> row;
        unordered_set<int> col;

        // Step 2: Traverse the matrix to find all positions where the value is 0
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i); // Mark row for zeroing
                    col.insert(j); // Mark column for zeroing
                }
            }
        }

        // Step 3: Set all cells in the marked rows to 0
        for (int r : row) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[r][j] = 0;
            }
        }

        // Step 4: Set all cells in the marked columns to 0
        for (int c : col) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][c] = 0;
            }
        }
    }
};
