class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax[n]={0};
        int rightmax[n]={0};
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(height[i],ans);
            leftmax[i]=ans;
        }
        int ans1=INT_MIN;
        for(int j=n-1;j>=0;j--){
            ans1 = max(height[j],ans1);
            rightmax[j]= ans1;
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            sum = sum + min(leftmax[i],rightmax[i])-height[i];

        }
    return sum;
    }
};
