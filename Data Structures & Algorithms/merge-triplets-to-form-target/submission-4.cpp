class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>v1(3,0);
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1]
            && triplets[i][2] <= target[2]){
                v1[0]=(max(v1[0],triplets[i][0]));
                v1[1]=(max(v1[1],triplets[i][1]));
                v1[2]=(max(v1[2],triplets[i][2]));
            }
        }
        return v1==target;
    }
};
