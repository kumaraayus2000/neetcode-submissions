class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int>cnt(26,0);
        int r=0,l=0,maxfreq=0,maxlen=0;

        while(r<s.size()){

            cnt[s[r]-'A']++;
            maxfreq= max(maxfreq,cnt[s[r]-'A']);
            while((r-l+1) - maxfreq >k){
                cnt[s[l]-'A']--;
                l++;
            }
    maxlen = max(maxlen,r-l+1);
    r++;
        }
return maxlen;
    }
};
