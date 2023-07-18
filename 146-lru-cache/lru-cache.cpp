class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    int cap;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
     unordered_map<int,node*>m;

   void addnode(node*newnode ){
       node* temp=head->next;
       newnode->next=temp;
       temp->prev=newnode;
       head->next=newnode;
       newnode->prev=head;
   }
   void deletenode(node* delnode){
       node* delprev=delnode->prev;
       node* delnext=delnode->next;
       delprev->next=delnext;
       delnext->prev=delprev;
   }
    LRUCache(int capacity) {
        cap= capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* getnode=m[key];
            int getval=getnode->val;
            m.erase(key);
            deletenode(getnode);
            addnode(getnode);
            m[key]=getnode;
            return getval;
        }else
         return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* existnode=m[key];
            m.erase(key);
            deletenode(existnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */