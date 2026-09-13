class Solution {
public:
    int majorityElement(vector<int>& nums) {

   // Initialize the candidate (potential majority element)
        int candidate = nums[0];
        // Count of the candidate
        int count = 0;

        // Iterate over each number in the array
        for(int i = 0; i < nums.size(); i++) {

            // If count drops to 0, pick the current number as new candidate
            if(count == 0) {
                candidate = nums[i];
            }

            // If current number matches candidate, increment count
            if(nums[i] == candidate) {
                count = count + 1;
            } 
            // If current number does NOT match candidate, decrement count
            else {
                count = count - 1;
            }
        }

        // At the end, candidate holds the majority element
        return candidate;    
    }
};