/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //copy next pointer first then copy random pointer
        unordered_map<Node*,Node*> mpp;
        //creating the 1->1' mapping
        Node* temp=head;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        //creating the next pointer and random pointer mapping
        temp=head;
        while(temp!=nullptr){
            if(temp->next){
                mpp[temp]->next=mpp[temp->next];
            }
            if(temp->random){
                mpp[temp]->random=mpp[temp->random];
            }
            temp=temp->next;
        }
        return mpp[head];

    }
};
