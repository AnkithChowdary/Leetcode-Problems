class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       unordered_set<string>s;
       for(auto obs:obstacles){
        string key=to_string(obs[0])+"/"+to_string(obs[1]);
        s.insert(key);
       }
       int x=0;
       int y=0;
       int mdis=0;
       pair<int,int>direction={0,1};   // North direction

       for(int num:commands){
        if(num==-1){
            direction={direction.second,-direction.first};
        }else if(num==-2){
            direction={-direction.second,direction.first};
        }else{
            for(int i=0;i<num;i++){
                int nx=x+direction.first;
                int ny=y+direction.second;
            string nextKey=to_string(nx)+"/"+to_string(ny);
            if(s.find(nextKey)!=s.end()){
                break;
            }
            x=nx;
            y=ny;
            }
        }
        mdis=max(mdis,x*x+y*y);
       }
       return mdis;
    }
};