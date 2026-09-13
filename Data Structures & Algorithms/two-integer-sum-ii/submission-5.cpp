class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
             int i = 0, j = numbers.size() - 1;
        while (i < j) {
        //    int sum = numbers[i] + numbers[j];
            if (numbers[i] + numbers[j] == target) {
                // ✅ Return 1-based indices as required by LeetCode 167
                return {i + 1, j + 1};
            } else if (numbers[i] + numbers[j] < target) {
                i++; // Need a larger sum
            } else {
                j--; // Need a smaller sum
            }
        }
        return {}; 

    }
};
