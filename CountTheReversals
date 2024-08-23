class Solution {
public:
    string fractionAddition(string exp) {
        int nu=0;
        int de=1;
        int n=exp.length();
        int i=0;
        while(i<n){
            int currnu=0;
            int currde=0;
             bool isNe=(exp[i]=='-');
            if(exp[i]=='-'||exp[i]=='+'){
                i++;
            }
            while(i<n&&isdigit(exp[i])){
                int val=(exp[i]-'0');
                currnu=(currnu*10)+val;
                i++;
            }
            i++;
           
            if(isNe==true){
                currnu=currnu*-1;
            }
            while(i<n&&isdigit(exp[i])){
                int val=(exp[i]-'0');
                currde=(currde*10)+val;
                i++;
            }
            nu=nu*currde+de*currnu;
            de=de*currde;
        }
        int gcd=abs(__gcd(nu,de));
        nu/=gcd;
        de/=gcd;
        return to_string(nu)+'/'+to_string(de);
    }
};