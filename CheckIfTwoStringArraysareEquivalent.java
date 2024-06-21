class Solution {
  public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
      StringBuilder a=new StringBuilder();
      StringBuilder b=new StringBuilder();
      for(String x:word1){
          a.append(x);
      }
      for(String y:word2){
          b.append(y);
      }

      return a.compareTo(b)==0;
  }
}