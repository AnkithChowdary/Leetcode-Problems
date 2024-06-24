import java.util.*;
class Solution {
  public String truncateSentence(String s, int k) {
      StringTokenizer st = new StringTokenizer(s);
      StringBuilder result = new StringBuilder();
      
      while (st.hasMoreTokens() && k > 0) {
          result.append(st.nextToken());
          k--;
          if (k > 0) {
              result.append(" ");
          }
      }
      
      return result.toString();
  }
}