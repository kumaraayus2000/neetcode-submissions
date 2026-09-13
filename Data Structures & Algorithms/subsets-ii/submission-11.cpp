class Solution {
public:
 vector<vector<int>>res;
 vector<int>v1;
  void b1(vector<int>& nums,int x){
    // if(x==nums.size()-1){
    //     res.push_back(v1);
    //     return;
    // }
     res.push_back(v1);

    for(int i=x;i<nums.size();i++){
       if(i>x && nums[i]==nums[i-1]){
        continue;
       }
        v1.push_back(nums[i]);
        b1(nums,i+1);
        v1.pop_back();
    }
  }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        b1(nums,0);
        return res;
    }
};
