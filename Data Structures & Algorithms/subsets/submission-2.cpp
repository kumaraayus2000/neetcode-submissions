class Solution {
public:
    vector<vector<int>>v1;
    vector<int>v2;
    void subs1(vector<int>& nums,int index){
        if(index==nums.size()){
            v1.push_back(v2);
            return;
        }

        v2.push_back(nums[index]);
        subs1(nums,index+1);

        v2.pop_back();
        subs1(nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subs1(nums,0);
        return v1;
    }
};
