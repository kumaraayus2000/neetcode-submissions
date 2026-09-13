class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        auto it = mp.begin();
        auto prev = it;
        it++;
        int longest=1;
        int streak=1;
        while(it!=mp.end()){
            if(it->first==prev->first+1){
            streak++;
            }else{
               // longest=max(longest,streak);
                streak=1;
            }
            longest=max(longest,streak);
            prev=it;
        it++;
        }
        return longest;

    }
};
