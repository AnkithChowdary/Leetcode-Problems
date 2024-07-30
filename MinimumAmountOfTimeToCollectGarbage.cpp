class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //Picking times of Garbage ,Paper , Metal trucks
        int pickingG=0;
        int pickingP=0;
        int pickingM=0;
        int lastG=-1,lastP=-1,lastM=-1;
        for(int i=0;i<garbage.size();i++){
            string currentHouse=garbage[i];
            for(int j=0;j<currentHouse.length();j++){
                char type=currentHouse[j];
                if(type=='M'){
                    pickingM++;
                    lastM=i;
                }
                if(type=='P'){
                    pickingP++;
                    lastP=i;
                }
                if(type=='G'){
                    pickingG++;
                    lastG=i;
                }
            }
        }
        int tg=0;
        for(int i=0;i<lastG;i++){
            tg+=travel[i];
        }
        int tp=0;
        for(int j=0;j<lastP;j++){
           tp+=travel[j];
        }
        int tm=0;
        for(int k=0;k<lastM;k++){
          tm+=travel[k];
        }
        int totalPicking=pickingM+pickingP+pickingG;
        int totalTravel=tg+tm+tp;
        int ans=totalPicking+totalTravel;
        return ans;
    }
};