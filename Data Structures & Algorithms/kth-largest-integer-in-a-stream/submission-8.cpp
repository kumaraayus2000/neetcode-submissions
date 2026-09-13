class KthLargest {
private:
    // Min-heap to store the k largest elements seen so far
    // The smallest among them (heap.top()) = kth largest overall
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k; // which kth largest we want

public:
    // Constructor: initialize with nums
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minheap.push(num);           // add element
            if (minheap.size() > k) {    // keep only k elements
                minheap.pop();           // remove smallest if size exceeds k
            }
        }
    }
    
    // Add a new value and return the kth largest
    int add(int val) {
        minheap.push(val);               // insert new number
        if (minheap.size() > k) {        // if more than k elements
            minheap.pop();               // remove smallest
        }
        return minheap.top();            // top is kth largest
    }
};
