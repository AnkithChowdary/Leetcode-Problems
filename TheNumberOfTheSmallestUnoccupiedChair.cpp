class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        int targetTime=times[targetFriend][0];
        vector<int>t(n,-1);
        sort(times.begin(),times.end());
        for(vector<int>time:times){
            int arrival=time[0];
            int depart=time[1];
            for(int i=0;i<n;i++){
                if(t[i]<=arrival){
                    t[i]=depart;
                    if(targetTime==arrival)
                    return i;
                    break;
                }
            }
        }
        return 0;
    }
};