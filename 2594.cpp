class Solution {
  public:
      bool canRepair(vector<int>& ranks,long long time,int &cars){
          long long carsCount=0;
          for(int rank:ranks){
              carsCount+=sqrt(time/rank);
              if(carsCount>=cars)return true;
          }
          return carsCount>=cars;
      }
      long long repairCars(vector<int>& ranks, int cars) {
          int n=ranks.size();
  
          sort(ranks.begin(),ranks.end());
          long long left=1;
          long long right=1LL*ranks[0]*cars*cars;
          while(left<right){
              long long mid=left+(right-left)/2;
              if(canRepair(ranks,mid,cars))
              right=mid;
              else
              left=mid+1;
          }
          return left;
      }
  };