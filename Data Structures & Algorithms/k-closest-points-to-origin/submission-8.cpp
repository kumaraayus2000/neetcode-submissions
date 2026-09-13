class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
    vector<vector<int>>v1;
        while(!pq.empty()){
            auto p1 = pq.top().second;
            int x1 = p1.first;
            int y1 = p1.second;
            v1.push_back({x1,y1});
            pq.pop();
        }
        return v1;
    }
};
