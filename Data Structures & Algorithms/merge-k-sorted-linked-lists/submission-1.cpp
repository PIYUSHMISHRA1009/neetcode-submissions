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
    ListNode* createLL(vector<int> &arr){
        ListNode* head=new ListNode(arr[0]);
        ListNode* temp=head;
        for(int i=1;i<arr.size();i++){
            ListNode* newNode=new ListNode(arr[i]);
            temp->next=newNode;
            temp=newNode;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        vector<int> arr;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=nullptr){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head=createLL(arr);
        return head;

    }
};
