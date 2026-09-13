class Solution {
public:
    vector<vector<int>> result;
    vector<int>temp;
    void solve(int x,vector<int>& nums){

        if(x>=nums.size()){
            result.push_back(temp);
            return;  //u failed bcoz u didnt break the function
            // function is broken only when there is return
        }

      //  for(int i=x;i<nums.size();i++){

        temp.push_back(nums[x]);
        solve(x+1,nums);
        temp.pop_back();
        solve(x+1,nums);
     //   }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return result;
    }
};
