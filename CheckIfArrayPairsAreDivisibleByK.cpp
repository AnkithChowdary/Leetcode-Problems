// Using Map
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int n:arr){
            int remainder=(n%k+k)%k;
            mp[remainder]++;
        }

        if(mp[0]%2!=0)
        return false;

        for(auto it:mp){
            int remainder=it.first;
            int c=it.second;
            if(remainder==0)
            continue;

            int secondPair=k-remainder;
            if(mp[secondPair]!=mp[remainder])
            return false;
        }
        return true;
    }
};

// Using Vector
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
      vector<int>mp(k,0);   // Because remainder will be from 0 to k-1
      for(int n:arr){
        int remainder=(n%k+k)%k;  // Negative number normally we write n%k
        mp[remainder]++;
      }

      if(mp[0]%2!=0){
        return false;
      }

        for(int r=1;r<=k/2;r++){
        int secondPair=k-r;
        if(mp[r]!=mp[secondPair]){
            return false;
        }
      }
      return true;

    }
};