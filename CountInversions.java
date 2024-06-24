
class Solution {
    static long inversionCount(long arr[], int n) {
           return mergeSortAndCount(arr, 0, n - 1);
    }

    private static long mergeSortAndCount(long arr[], int low, int high) {
        long count = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            count += mergeSortAndCount(arr, low, mid);
            count += mergeSortAndCount(arr, mid + 1, high);
            count += mergeAndCount(arr, low, mid, high);
        }
        return count;
    }

    
    private static long mergeAndCount(long arr[], int low, int mid, int high) {
      
        long[] temp = new long[high - low + 1];
        int i = low;      
        int j = mid + 1;  
        int k = 0;        
        long count = 0;   

        while (i<=mid&&j<=high){
            if (arr[i] <= arr[j]){
                temp[k++]=arr[i++];
            } else {
                
                temp[k++]=arr[j++];
                count+=(mid - i + 1);
            }
        }

       
        while(i<=mid) {
            temp[k++]=arr[i++];
        }

        
        while (j<=high) {
            temp[k++]=arr[j++];
        }

       
        for(i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }

        return count;
    }
}
