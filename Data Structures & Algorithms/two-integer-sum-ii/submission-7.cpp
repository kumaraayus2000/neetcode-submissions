class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int i=0,j=nums.size()-1;
        vector<int>v1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                v1.push_back(i+1);
                v1.push_back(j+1);
                return v1;
            }else if(nums[i] + nums[j]< target){
                i++;
            }else
            {
                j--;
            }
        }
        return v1;
 
    }
};
