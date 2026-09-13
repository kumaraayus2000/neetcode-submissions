class Solution {
public:
    int findMin(vector<int> &nums) {
        int l1=INT_MAX;
        for(int i=0;i<nums.size();i++){
            l1= min(l1,nums[i]);
        }
        return l1;
    }
};
