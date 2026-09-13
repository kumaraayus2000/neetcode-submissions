class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n1= nums.size();
       int res=n1;

       for(int i=0;i<nums.size();i++){
        res=res ^i;
        res = res ^ nums[i];
       }
        return res;
    }
};
