class Solution {
public:

     vector<vector<int>> res;
     vector<int>v1;

     void backtrack(vector<int>& candidates, int target,int index,int sum){
        if(sum>target){
            return;
        }
        if(sum==target){
            res.push_back(v1);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            v1.push_back(candidates[i]);
            backtrack(candidates,target,i+1,sum + candidates[i]);
            v1.pop_back();
        }
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,0);
        return res;
    }
};
