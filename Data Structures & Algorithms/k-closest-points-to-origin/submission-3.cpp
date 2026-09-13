class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
           // Max heap to store k closest points by distance
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distSq = x * x + y * y;

            pq.push({distSq, {x, y}});
            if (pq.size() > k) {
                pq.pop();  // remove farthest point
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            auto point = pq.top().second;
            result.push_back({point.first, point.second});
            pq.pop();
        }

        return result;
    }
};
