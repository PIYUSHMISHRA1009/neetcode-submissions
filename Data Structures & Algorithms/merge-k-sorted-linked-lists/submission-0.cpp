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
    ListNode* mergeTwoSortedList(ListNode* l1,ListNode* l2){
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                ListNode* newNode=new ListNode(temp1->val);
                temp->next=newNode;
                temp=newNode;
                temp1=temp1->next;
            }
            else if(temp2->val<=temp1->val){
                ListNode* newNode=new ListNode(temp2->val);
                temp->next=newNode;
                temp=newNode;
                temp2=temp2->next;
            }
        }
        while(temp1){
            ListNode* newNode=new ListNode(temp1->val);
            temp->next=newNode;
            temp=newNode;
            temp1=temp1->next;
        }
        while(temp2){
            ListNode* newNode=new ListNode(temp2->val);
            temp->next=newNode;
            temp=newNode;
            temp2=temp2->next;
        }
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        for(int i=1;i<lists.size();i++){
            lists[0]=mergeTwoSortedList(lists[0],lists[i]);
        }
        return lists[0];
    }
};
