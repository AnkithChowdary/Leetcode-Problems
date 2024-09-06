/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s(nums.begin(),nums.end());
        ListNode *temp=new ListNode(-1);
        ListNode *curr=temp;
        while(head!=nullptr){
            if(s.find(head->val)==s.end()){
                ListNode* k=new ListNode(head->val);
                curr->next=k;
                curr=curr->next;
            }
            head=head->next;
        }
        curr->next=nullptr;
   return temp->next;
    }
};