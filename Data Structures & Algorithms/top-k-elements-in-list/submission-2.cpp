class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

      priority_queue<pair<int,int>>pq;
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
      }  
      for(auto it=mp.begin();it!=mp.end();it++){
        pq.push({it->second,it->first});
      }
      vector<int>v1;
    for(int i=0;i<k;i++){
        v1.push_back(pq.top().second);
        pq.pop();
    }
    return v1;

    }
};
