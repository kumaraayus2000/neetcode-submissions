class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int sum=1;
    int n = nums.size();
    vector<int>v1(n,1);
    int prefix=1;
    for(int i=0;i<n;i++){
        v1[i] = prefix;
        prefix *= nums[i];
    }

    int postfix=1;
    for(int i=n-1;i>=0;i--){
        v1[i]*=postfix;
        postfix*=nums[i];
    }
    return v1;
    }
};
