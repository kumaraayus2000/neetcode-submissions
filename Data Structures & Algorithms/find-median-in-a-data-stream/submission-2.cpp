class MedianFinder {
public:
vector<int>a;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        a.push_back(num);
        sort(a.begin(),a.end());
    }
    
    double findMedian() {
       int n = a.size();
       if(n%2!=0){
        return a[n/2];
       }else{
       return (a[n/2] + a[(n/2)-1])/2.0;
       }


    }
};
