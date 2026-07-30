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
    int LengthofLL(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=LengthofLL(head);
        int k=len-n;
        if(k==0){
            ListNode* newHead=head->next;
            head->next=nullptr;
            return newHead;
        }
        int cnt=1;
        ListNode* temp=head;
        while(cnt!=k){
            temp=temp->next;
            cnt++;
        }
        ListNode* nthnode=temp->next;
        temp->next=nthnode->next;
        delete(nthnode);
        return head;
    }
};
