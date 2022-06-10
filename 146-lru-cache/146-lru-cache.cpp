struct Node{
    int key, val;
    Node *prev, *next;
    Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node *left, *right;
    
    void remove(Node *node){
        Node *pre = node->prev;
        
        pre->next = node->next;
        node->next->prev = pre;
    }
    
    void insert(Node *node){
        Node *pre = right->prev;
        
        pre->next = node;
        node->prev = pre;
        
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if(cache.size() > cap){
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */