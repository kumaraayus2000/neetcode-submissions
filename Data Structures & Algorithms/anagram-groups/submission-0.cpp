class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

       map<string,vector<string>>mp;

       for(int i=0;i<strs.size();i++){
        string s1 = strs[i];
        sort(s1.begin(),s1.end());
        if(mp.find(s1)!=mp.end()){
            mp[s1].push_back(strs[i]);
        }else{
            mp[s1].push_back(strs[i]);
        }
       }
       vector<vector<string>>v1;
       for(auto it=mp.begin();it!=mp.end();it++){
        v1.push_back(it->second);
       }
        return v1;
    }
};
