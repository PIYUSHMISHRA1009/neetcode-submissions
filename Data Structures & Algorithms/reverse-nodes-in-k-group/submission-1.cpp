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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        while(curr!=nullptr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* prevGroup = dummyNode;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* startNode=temp;
            int cnt=1;
            while(cnt!=k && temp!=nullptr){
                temp=temp->next;
                cnt++;
            }
            if(temp==nullptr){
                break;
            }
            ListNode* nextGroup=temp->next;
            temp->next=nullptr;
            ListNode* newHead=reverseLL(startNode);
            prevGroup->next=newHead;
            startNode->next=nextGroup;
            prevGroup=startNode;
            temp=nextGroup;
        }
        return dummyNode->next;
    }
};
