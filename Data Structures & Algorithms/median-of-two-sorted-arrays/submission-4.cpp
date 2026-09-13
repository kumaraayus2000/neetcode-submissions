class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int>nums3 = nums1;
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());

        int n = nums3.size();
        if(n%2==0){
            int mid=n/2-1;
            int mid1 = n/2;
            return (nums3[mid]+ nums3[mid1])/2.0; 
        }else{
            return nums3[n/2];
        }
        return -1;
    }
};
