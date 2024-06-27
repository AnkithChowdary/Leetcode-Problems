class Solution {
  public static ListNode merge(ListNode left, ListNode right){
      ListNode head=new ListNode(0);
      ListNode temp=head;
      while(left!=null && right!=null){
          if(left.val<right.val){
              temp.next=left;
              left=left.next;
          }else{
              temp.next=right;
              right=right.next;
          }
          temp=temp.next;
      }
      if(left!=null){
          temp.next=left;
      }
      if(right!=null){
          temp.next=right;
      }
      return head.next;
  }
  public static ListNode findMid(ListNode head){
      ListNode fast=head;
      ListNode slow=head;
     
      fast=fast.next;
      while(fast!=null&&fast.next!=null){
          slow=slow.next;
          fast=fast.next.next;
      }
      ListNode mid=slow.next;
      slow.next=null;
      return mid;
  }
  public ListNode sortList(ListNode head) {
      if(head==null||head.next==null){
          return head;
      }
     
      
      ListNode mid=findMid(head);
      ListNode left=sortList(head);
      ListNode right=sortList(mid);

      
      ListNode newHead =merge(left,right);
      return newHead;
  }
}