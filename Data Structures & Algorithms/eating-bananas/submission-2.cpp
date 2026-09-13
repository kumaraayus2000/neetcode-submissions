class Solution {
public:

    // Helper function to check if Koko can eat all bananas at speed 'mid' in 'h' hours
    bool caneatall(vector<int>& piles, int mid, int h){
        int actualhours = 0;  // total hours needed to eat all piles

        for(int i = 0; i < piles.size(); i++){
            actualhours += piles[i] / mid;   // hours if pile divides evenly
            if(piles[i] % mid != 0){         // if remainder exists, add 1 more hour
                actualhours++;
            }
        }

        return actualhours <= h;  // true if she can finish all bananas in 'h' hours
    }

    // Main function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;  // minimum possible speed
        int r = *max_element(begin(piles), end(piles));  // maximum possible speed = largest pile

        // Binary search to find the minimum speed at which Koko can finish all bananas
        while(l < r){
            int mid = l + (r - l) / 2;  // current speed to test

            if(caneatall(piles, mid, h)){
                r = mid;  // if feasible, try slower speed
            } else {
                l = mid + 1;  // if not feasible, try faster speed
            }
        }

        return l;  // minimum speed where Koko can finish all bananas
    }
};
