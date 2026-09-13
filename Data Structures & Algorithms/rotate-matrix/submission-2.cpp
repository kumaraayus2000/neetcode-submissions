class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> res1;
      for(int i=0;i<matrix.size();i++){
        vector<int>v1;
        for(int j=0;j<matrix[0].size();j++){
            v1.push_back(matrix[j][i]);
        }
        reverse(v1.begin(),v1.end());
        res1.push_back(v1);
      }
    matrix = res1;
    }
};
