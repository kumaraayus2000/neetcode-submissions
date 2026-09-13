class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.empty())
       {
        return 0;
       } 
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]=1;
    }

    int longest=1;
    int curr_streak=1;
    auto prev = mp.begin();
    auto it = prev;
    ++it;

    while(it!=mp.end()){
        if(it->first==prev->first+1){
            curr_streak++;
        }else{
            curr_streak=1;
        }
    longest = max(longest,curr_streak);
    prev=it;
    ++it;

    }
    return longest;

    }
};
