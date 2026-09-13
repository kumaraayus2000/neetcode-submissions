class Solution {
public:

    int countbits(int x){

        int count=0;
        for(int i=31;i>=0;i--){
            if(((x>>i)&1)==1){
                count++;
            }
        }
        return count;
    }
    vector<int> countBits(int n) {
        
        vector<int>v1;

        for(int i=0;i<=n;i++){
            v1.push_back(countbits(i));

        }
    return v1;
    }
};
