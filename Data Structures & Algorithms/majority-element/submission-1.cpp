class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n1 = nums.size()/2;

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int l1=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second>=n1){
                l1= it->first;
            }
        }
        return l1;
    }
};