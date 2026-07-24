class LRUCache {
private: 
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
        ListNode(int k, int x) : key(k), val(x), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, ListNode*> mp;
    int n, curr;
    ListNode *left, *right;

    // Remove Node
    void remove(ListNode* ptr) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    // Insert node at last
    void insert(ListNode* ptr) {
        ptr->next = right;
        ptr->prev = right->prev;
        right->prev->next = ptr;
        right->prev = ptr;
    }

public:
    LRUCache(int capacity) {
        n = capacity;
        curr = 0;
        left = new ListNode();
        right = new ListNode();
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        // key does not exist
        if(mp.find(key) == mp.end()) return -1;

        // move the accessed node to right
        ListNode* ptr = mp[key];
        remove(ptr);
        insert(ptr);

        return ptr->val;
    }
    
    void put(int key, int value) {
        // If key is not present, create a new node
        if(mp.find(key) == mp.end()) {
            ListNode* newNode = new ListNode(key, value);
            insert(newNode);
            mp[key] = newNode;
            
            // If cache exceeds capacity, remove LRU node
            if(curr == n) {
                ListNode* ptr = left->next;
                mp.erase(ptr->key);
                remove(ptr);
                delete ptr;
            } 
            else curr++;
        } else {
            // if key already exists, update value and send to right
            ListNode* ptr = mp[key];
            ptr->val = value;

            remove(ptr);
            insert(ptr);
        }
    }
};
