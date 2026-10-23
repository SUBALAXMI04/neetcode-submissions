class LRUCache {
public:
    class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k,int v){
            this->key = k;
            this->value = v;
            next = NULL;
            prev = NULL;
        }
    };

    int size;
    Node *head,*tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity){
        size = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFirst(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    int get(int key){
        if(!mp.count(key)) return -1;
        Node* node = mp[key];
        remove(node);
        insertFirst(node);
        return node->value;
    }
    
    void put(int key,int value){
        if(size == 0) return;
        if(mp.count(key)){
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insertFirst(node);
            return;
        }
        Node* node = new Node(key,value);
        insertFirst(node);
        mp[key] = node;
        if(mp.size() > size){
            Node* del = tail->prev;
            remove(del);
            mp.erase(del->key);
            delete del;
        }
    }
};
