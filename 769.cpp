class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       
        stack<int>s;
        int n=arr.size();
     

        for(int i=0;i<n;i++){
           if(s.empty()||s.top()<=arr[i])
           s.push(arr[i]);
           else{
            int maxi=s.top();
            s.pop();
            while(!s.empty()&&s.top()>arr[i])
            s.pop();
          
           s.push(maxi);
           }

        }
        return s.size();
    }
};