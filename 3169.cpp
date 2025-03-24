class Solution {
  public:
      int countDays(int days, vector<vector<int>>& meetings) {
          int meetingCount=0,prev=0;
          sort(meetings.begin(),meetings.end());
          for(auto p:meetings){
              int s=p[0];
              int e=p[1];
              // If there is no overlap
              if(s>prev+1){
                  meetingCount+=e-s+1;
              }else{
                  // Overlap
                  meetingCount+=max(0,e-prev);
              }
              prev=max(prev,e);
  
  
          }
          return days-meetingCount;
      }
  };