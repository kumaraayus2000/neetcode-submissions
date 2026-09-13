class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    void backtrack(vector<int>& nums, int index) {
        res.push_back(subset);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates at the same level
            if (i > index && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            backtrack(nums, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // ✅ Required to handle duplicates
        backtrack(nums, 0);
        return res;
    }
};
