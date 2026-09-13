class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>mp(26,0);

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]-'A']++;
        }

        priority_queue<int>pq;

        for(int i=0;i<26;i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }
 
        int time =0;
        while(!pq.empty()){
            vector<int>temp;

            for(int i=1;i<=n+1;i++){
                if(pq.size()>0){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
            }

            if(temp.size()>0){
            for(int i=0;i<temp.size();i++){
            if(temp[i]>0){
            pq.push(temp[i]);
            }
            }
            
            }

            if(pq.size()==0){
                time +=temp.size();
            }else{
                time +=n+1;
            }
        }
        return time;
    }
};