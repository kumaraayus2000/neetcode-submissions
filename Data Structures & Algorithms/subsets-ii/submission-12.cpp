class Solution {
public:
    vector<vector<int>> res; // stores all unique subsets
    vector<int> v1;           // current subset being formed

    // Backtracking function to generate subsets
    void b1(vector<int>& nums, int x) {
        res.push_back(v1); // add the current subset to the result

        for(int i = x; i < nums.size(); i++) {
            // Skip duplicates: if the current element is same as previous and not at the starting index
            if(i > x && nums[i] == nums[i-1]) {
                continue;
            }

            v1.push_back(nums[i]);   // include nums[i] in current subset
            b1(nums, i+1);           // recursively build further subsets
            v1.pop_back();           // backtrack: remove last element to try next possibility
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort nums to easily handle duplicates
        b1(nums, 0);                     // start backtracking from index 0
        return res;                      // return all unique subsets
    }
};
