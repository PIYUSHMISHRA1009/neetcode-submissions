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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* slow=dummyNode;
        ListNode* fast=dummyNode;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* node=slow->next;
        slow->next=node->next;
        delete node;
        ListNode* newHead=dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};
