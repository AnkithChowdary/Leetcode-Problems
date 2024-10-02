class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>s(arr.begin(),arr.end());
        int r=1;  // Rank starts from 1
        for(int n:s){
            mp[n]=r;
            r++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};