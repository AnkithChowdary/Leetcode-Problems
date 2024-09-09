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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int left=0,right=n-1,top=0,bottom=m-1;
        while(head&&top<=bottom&&left<=right){
        // Left to right
        for(int i=left;i<=right&&head;i++){
            ans[top][i]=head->val;
            head=head->next;
        }
        top++;
        // Top to bottom
        for(int j=top;j<=bottom&&head;j++){
            ans[j][right]=head->val;
            head=head->next;
        }
        right--;
        // Right to left
        for(int k=right;k>=left&&head;k--){
            ans[bottom][k]=head->val;
            head=head->next;
        }
        bottom--;
        // Bottom to top
        for(int l=bottom;l>=top&&head;l--){
            ans[l][left]=(head->val);
            head=head->next;
        }
        left++;
        }
        return ans;
    }
};