
//Two Pointer approach
class Solution {
  public:
      vector<int> pivotArray(vector<int>& nums, int pivot) {
          vector<int>result(nums.size());
          int less=0,equal=0;
          for(int num:nums){
              if(num<pivot)
              less++;
              else if(num==pivot)
              equal++;
          }
  
          int lessI=0;
          int equalI=less;
          int greaterI=less+equal;
          for(int num:nums){
              if(num<pivot)
              {
                  result[lessI]=num;
                  lessI++;
              }else if(num>pivot)
              {
                  result[greaterI]=num;
                  greaterI++;
              }else{
                  result[equalI]=num;
                  equalI++;
              }
          }
          return result;
      }
  };

  // Using Three more vectors

  class Solution {
    public:
        vector<int> partition(vector<int> &arr,int &pivot){
        vector<int>left,middle,right;
        for(int num:arr){
            if(num<pivot){
                left.push_back(num);
            }
            if(num==pivot)
            middle.push_back(num);
            if(num>pivot){
                right.push_back(num);
            }
           
    
        }
        left.insert(left.end(),middle.begin(),middle.end());
           left.insert(left.end(),right.begin(),right.end());
        return left;
    }
    
        vector<int> pivotArray(vector<int>& nums, int pivot) {
         
         
            return partition(nums,pivot);
        
           
        }
    };