#include <string>
class Solution {
public:
    string add(string num1, int n1, string num2, int n2, int carry){
       if(n1<0&&n2<0){
        if(carry!=0){
            return string(1,carry+'0');
        }
        
            return "";
        

       }
       int a=((n1>=0)?num1[n1]:'0')-'0';
       int b=((n2>=0)?num2[n2]:'0')-'0';

       int sum=a+b+carry;
       int digit=sum%10;
       carry=sum/10;
       string ans="";
       ans.push_back(digit+'0'); 
       ans+=add(num1,n1-1,num2,n2-1,carry);
       return ans;


    }
    string addStrings(string num1, string num2) {
        string ans=add(num1,num1.size()-1,num2,num2.size()-1,0);
        reverse(ans.begin(),ans.end());
        return ans;
            }
};