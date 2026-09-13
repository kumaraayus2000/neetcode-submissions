class Solution {
public:
    void sortColors(vector<int>& nums) {
       int l0=0,l1=0,l2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                l0++;
            }
            if(nums[i]==1){
                l1++;
            }
            if(nums[i]==2){
                l2++;
            }
        }
        int i=0;
        while(l0--){
        nums[i]=0;
        i++;
        }
        while(l1--){
            nums[i]=1;
            i++;
        }
        while(l2--){
            nums[i]=2;
            i++;
        }
    }
};