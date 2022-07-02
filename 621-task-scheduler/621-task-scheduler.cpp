class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        vector<int> counts(26,0);
        for(char c: tasks)  counts[c-'A']++;
        
        for(int c: counts)  {
            if(c)   pq.push(c);
        }
        
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int task = pq.top() - 1; pq.pop();
                if(task)    q.push({task, time+n});
            }
            if(!q.empty() && q.front().second==time){
                auto i = q.front(); q.pop();
                pq.push(i.first);
            }
        }
        return time;
    }
};