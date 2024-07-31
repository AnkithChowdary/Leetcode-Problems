 string od;
class Solution {
public:
   

    static bool mycmp(char &a,char &b){
        return (od.find(a)<od.find(b));
    }
    string customSortString(string order, string s) {
          od=order;
        sort(s.begin(),s.end(),mycmp);
      
        return s;
    }
};