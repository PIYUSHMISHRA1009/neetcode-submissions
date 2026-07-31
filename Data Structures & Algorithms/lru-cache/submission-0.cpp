class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int key,int val){
                this->key=key;
                this->val=val;
                this->next=nullptr;
                this->prev=nullptr;
            }
    };
    unordered_map<int,Node*> mpp;
    Node* head;
    Node* tail;
    int capacity;
    void deleteNode(Node* node){
        Node* nprev=node->prev;
        Node* nnode=node->next;
        nprev->next=nnode;
        nnode->prev=nprev;
        node->next=nullptr;
        node->prev=nullptr;
    }
    void insertAfterHead(Node* node){
        Node* headnext=head->next;
        node->prev=head;
        node->next=headnext;
        head->next=node;
        headnext->prev=node;
    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            mpp[key]=node;
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            deleteNode(node);
            node->val=value;
            insertAfterHead(node);
            return ;
        }
        if(mpp.size()==capacity){
            Node* node=tail->prev;
            deleteNode(node);
            mpp.erase(node->key);
            delete node;
        }
        
        Node* newNode=new Node(key,value);
        insertAfterHead(newNode);
        mpp[key]=newNode;
    }
};
