class Solution {
  public int countConsistentStrings(String allowed, String[] words) {
   
      Set<Character> as = new HashSet<>();
      for (char ch : allowed.toCharArray()) {
          as.add(ch);
      }

      int c=0;
      for (String word : words) {
          boolean flag=true;
          for (char ch : word.toCharArray()){
              if(!as.contains(ch)){
                  flag=false;
                  break;
              }
          }
          if (flag){
              c++;
          }
      }

      return c;
  }
}
