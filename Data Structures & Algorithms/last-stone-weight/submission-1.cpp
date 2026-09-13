class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int>pq;
int k=2;

for(int i=0;i<stones.size();i++){
    pq.push(stones[i]);
}
while(pq.size()!=1){
int x1 = pq.top();
pq.pop();
int x2 = pq.top();
pq.pop();
pq.push(abs(x1-x2));

}
return pq.top();

    }
};
