class Solution {
public:

    string encode(vector<string>& strs) {
        string s1="";
        for(int i=0;i<strs.size();i++){
        s1=s1+strs[i] + "|";
        }
        return s1;

    }

    vector<string> decode(string s) {
        vector<string>s1;
        string s2="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
                s1.push_back(s2);
                s2="";
            }else{
                s2=s2+s[i];
            }
        }
    return s1;
    }
};
