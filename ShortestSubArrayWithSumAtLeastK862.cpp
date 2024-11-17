class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>deq;
        int minLen=INT_MAX;
        vector<long long>cumulativeSum(n+1,0);
         int i=0;
       
        while(i<n){

            if(i==0)
            cumulativeSum[i]=nums[i];
            else
        cumulativeSum[i]=nums[i]+cumulativeSum[i-1];

        if(cumulativeSum[i]>=k){
            minLen=min(minLen,i+1);
        }

        while(!deq.empty()&&cumulativeSum[i]-cumulativeSum[deq.front()]>=k){
            minLen=min(minLen,i-deq.front());
            deq.pop_front();
        }
        while(!deq.empty()&&cumulativeSum[i]<=cumulativeSum[deq.back()]){
            deq.pop_back();
        }
         deq.push_back(i);
        i++;
        }
      return minLen==INT_MAX?-1:minLen;
    }
};