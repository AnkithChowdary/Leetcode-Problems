class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>num;
        for(int n:nums)
        num.push_back(to_string(n));

        sort(num.begin(),num.end(),[](string &a,string &b)
        {return a+b>b+a;});
        if(num[0]=="0")
        return "0";

        string biggest;
        for(string s:num)
        biggest+=s;

        return biggest;
    }
};