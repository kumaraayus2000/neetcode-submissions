class Solution {
public:
vector<vector<int>> res;
    vector<int> v1;

    void backtrack(vector<int>& nums, int target,int index,int currentsum){
        if(currentsum > target){
            return;
        }
        if(currentsum==target){
        res.push_back(v1);
        return;            
        }
        
        for(int i=index;i<nums.size();i++){
            v1.push_back(nums[i]);
            backtrack(nums,target,i,nums[i]+ currentsum);
            v1.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return res;
    }
};
