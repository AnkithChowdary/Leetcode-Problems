class Solution {
public:
    int minAddToMakeValid(string s) {
        int a=0;
        int b=0;  // To be added
        for(char ch:s){
            if(ch=='(')
            a++;
            else
            {
                if(a>0){
                    a--; //  balance out
                }else{
                     b++;
                }
            }
        }
        return a+b;

    }
};