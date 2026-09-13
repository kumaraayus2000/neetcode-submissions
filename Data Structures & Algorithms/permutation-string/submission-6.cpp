class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        if(n>m){
            return false;
        }

        for(int i=0;i<n;i++){
            v1[s1[i]-'a']++;
        }

        for(int i=0;i<n;i++){
            v2[s2[i]-'a']++;
        }

        if(v1==v2){
            return true;
        }
    //    int n = s1.size();
        for(int i=n;i<s2.size();i++){
            v2[s2[i]-'a']++;
            v2[s2[i-n]-'a']--;
            if(v1==v2){
                return true;
            }
        }
        return false;

    }
};
