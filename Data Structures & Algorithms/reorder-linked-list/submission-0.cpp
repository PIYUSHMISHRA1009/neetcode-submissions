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
    ListNode* reverseList(ListNode* node){
        if(node==nullptr || node->next==nullptr){
            return node;
        }
        ListNode* front=reverseList(node->next);
        node->next->next=node;
        node->next=nullptr;
        return front;
    }
    ListNode* middleofLL(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1|| temp2){
            if(temp1){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
                temp->next=nullptr;
            }
            if(temp2){
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
                temp->next=nullptr;
            }
        }
        return dummyNode->next;
    }
    void reorderList(ListNode* head) {
        //break the list from the middle ..then reverse and merge
        ListNode* middleLL=middleofLL(head);
        ListNode* newHead=middleLL->next;
        newHead=reverseList(newHead);
        middleLL->next=nullptr;
        ListNode* newH=merge(head,newHead);
    }
};
