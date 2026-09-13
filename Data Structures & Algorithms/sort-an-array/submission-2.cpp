class Solution {
public:

    // Merge two sorted halves of the array nums[s..mid] and nums[mid+1..e]
    void merge(int s, int mid, int e, vector<int>& nums){
        int n1 = mid - s + 1; // size of left half
        int n2 = e - mid;     // size of right half

        vector<int> left(n1), right(n2); // temporary arrays

        // Copy elements to left half
        for(int i = 0; i < n1; i++){
            left[i] = nums[s + i];
        }
        // Copy elements to right half
        for(int i = 0; i < n2; i++){
            right[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = s; // pointers for left, right, and original array

        // Merge the two halves back into nums
        while(i < n1 && j < n2){
            if(left[i] <= right[j]){ // pick smaller element
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements from left, if any
        while(i < n1){
            nums[k++] = left[i++];
        }
        // Copy remaining elements from right, if any
        while(j < n2){
            nums[k++] = right[j++];
        }
    }

    // Recursive merge sort function
    void mergesort(int s, int e, vector<int>& nums){
        if(s < e){
            int mid = s + (e - s) / 2; // find middle index
            mergesort(s, mid, nums);       // sort left half
            mergesort(mid + 1, e, nums);   // sort right half
            merge(s, mid, e, nums);        // merge sorted halves
        }
    }

    // Main function to sort array
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0, nums.size() - 1, nums); // call recursive merge sort
        return nums;                          // return sorted array
    }
};
