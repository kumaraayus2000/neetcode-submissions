class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char,int>mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
    vector<int>v1;
        int i=0,j=0;
        while(i<s.length()){
            int end = mp[s[i]];
            j=i;
            while(j<end){
                end = max(end,mp[s[j]]);
                j++;
            }
        v1.push_back(j-i+1);
        i=j+1;

        }
        return v1;

    }
};
