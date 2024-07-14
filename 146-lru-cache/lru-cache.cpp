class Node{
    public:
        int value;
        int key;
        Node* prev;
        Node* next;

        Node(int k,int val){
            value=val;
            key=k;
            prev=NULL;
            next=NULL;
        }
};

class LRUCache {
public:
    int cap;
    map<int,Node*>list;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* node){
        // cout<<node->key<<" "<<endl;
        Node* temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }

    void remove(Node* node){
        Node* temp=node->prev;
        // cout<<node->key<<" b"<<node->next->value<<endl;
        Node* temp2=node->next;
        temp->next=temp2;
        temp2->prev=temp;
        node=NULL;
    }

    int get(int key) {
        if(list.find(key)==list.end()){
            return -1;
        }
        remove(list[key]);
        add(list[key]);
        return list[key]->value;
    }
    
    void put(int key, int value) {
       
        if(list.find(key)!=list.end()){
            remove(list[key]);
            Node* n=new Node(key,value);
            list[key]=n;
            add(list[key]);
        }else if(cap>0){
             Node* n=new Node(key,value);
              list[key]=n;
            add(n);
            cap--;
        }else{
            
            list.erase(tail->prev->key);
            remove(tail->prev);
            Node* n=new Node(key,value);
            list[key]=n;
            
            add(n);
        }
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */