class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane algo
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        int sum = 0;
        int max1 = INT_MIN;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
            max1= max(max1,sum);
            if(sum<0){ // if sum is -ve then gone 
            // so update max before only 
                sum = 0;
            }
        }
        return max1;
    }
};
