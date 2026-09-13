class MedianFinder {
public:
    // Max-heap to store the smaller half of numbers
    priority_queue<int> left;

    // Min-heap to store the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        // Constructor doesn't need explicit initialization
    }
    
    void addNum(int num) {
        // Step 1: Add number to max-heap (left)
        left.push(num);

        // Step 2: Move the largest number from left to right
        // This ensures all numbers in left <= all numbers in right
        right.push(left.top());
        left.pop();

        // Step 3: Balance the heaps
        // left can have equal or 1 more element than right
        if(left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        // If total size is odd → median is top of left (max-heap)
        if(left.size() > right.size()) {
            return left.top();
        } 
        // If total size is even → median is average of tops of both heaps
        else {
            return (left.top() + right.top()) / 2.0;
        }
    }
};
