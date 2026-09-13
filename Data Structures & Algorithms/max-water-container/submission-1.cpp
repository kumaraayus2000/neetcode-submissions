class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int i=0,j=heights.size()-1;
        int area =1,marea=INT_MIN;
        while(i<j){
            area = min(heights[i],heights[j]) * (j-i);
            marea = max(marea,area);

            if(heights[i]>heights[j]){
                j--;
            }else {
                i++;
            }

        }
        return marea;
    }
};
