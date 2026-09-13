class KthLargest {

private:
priority_queue<int,vector<int>,greater<int>>minheap;
int k;
public:

    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums){
            minheap.push(num);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k){
            minheap.pop();
        }
        return minheap.top();
    }
};
