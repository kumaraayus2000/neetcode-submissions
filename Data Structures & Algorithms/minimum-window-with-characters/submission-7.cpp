class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int>v1(128,0);
        vector<int>v2(128,0);
        for(int i=0;i<t.size();i++){
            v2[t[i]]++;
        }


        int i=0,j=0,minlen=INT_MAX,count=0;
        string s1="";
        while(j<s.length()){

            if(v2[s[j]]>0){
                v1[s[j]]++;
                if(v1[s[j]]<=v2[s[j]]){
                count++;
                }
            }

            while(t.size()==count){

                if(minlen > j-i+1)
                {
                    minlen=j-i+1;
                    s1=s.substr(i,j-i+1);
                }
                if(v2[s[i]]>0){
                    v1[s[i]]--;
                    if(v1[s[i]]<v2[s[i]]){
                        count--;
                    }
                }
                i++;
            }
        j++;
        }
        return s1;
    }
};
