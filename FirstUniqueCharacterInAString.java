import java.util.HashMap;

class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        
        
        for (char ch:s.toCharArray()){
            mp.put(ch,mp.getOrDefault(ch, 0) + 1);
        }
        
        
        for (int i=0; i<s.length();i++){
            if (mp.get(s.charAt(i))==1){
                return i;
            }
        }
        
       
        return -1;
    }
}
