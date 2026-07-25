class LFUCache {
private: 
    // store key, val, freq
    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode *next;
        ListNode *prev;
        ListNode() : key(-1), val(-1), freq(1), next(nullptr), prev(nullptr) {}
        ListNode(int k, int x, int f) : key(k), val(x), freq(f), next(nullptr), prev(nullptr) {}
    };

    struct DLL {
        ListNode *left;
        ListNode *right;

        DLL() {
            left = new ListNode();
            right = new ListNode();

            left->next = right;
            right->prev = left;
        }
    };

    // Remove node from its current frequency list
    void remove(ListNode* ptr) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    // Insert node at the end of a frequency list
    void insert(DLL* dll, ListNode* ptr) {
        ptr->next = dll->right;
        ptr->prev = dll->right->prev;

        dll->right->prev->next = ptr;
        dll->right->prev = ptr;
    }

    unordered_map<int, ListNode*> mp; // unordered_map<key, ListNode*> mp;
    map<int, DLL*> freq; // map<freq, list_of_ListNode> freq;
    int n, curr;

public:
    LFUCache(int capacity) {
        n = capacity;
        curr = 0;
    }
    
    int get(int key) {
        // Key does not exist
        if(mp.find(key) == mp.end()) return -1;

        // key exists
        ListNode* ptr = mp[key];

        // Remove from current frequency list
        remove(ptr);

        // check and remove old frequency list
        if(freq[ptr->freq]->left->next == freq[ptr->freq]->right) freq.erase(ptr->freq);

        // Increase frequency
        ptr->freq++;

        // Create frequency list if it doesn't exist
        if(freq.find(ptr->freq) == freq.end()) freq[ptr->freq] = new DLL();

        // Insert into new frequency list
        insert(freq[ptr->freq], ptr);

        return ptr->val;
    }
    
    void put(int key, int value) {
        // If key is not present, create a new node
        if(mp.find(key) == mp.end()) {
            // capacity is full
            if(curr == n) {
                // Get minimum frequency list
                int minFreq = freq.begin()->first;

                DLL* dll = freq[minFreq];

                // Remove LRU node from that frequency
                ListNode* ptr = dll->left->next;

                mp.erase(ptr->key);

                remove(ptr);
                delete ptr;

                // Remove empty frequency list
                if(dll->left->next == dll->right) {
                    delete dll;
                    freq.erase(minFreq);
                }

            } else  curr++;

            // Create new node with frequency 1
            ListNode* newNode = new ListNode(key, value, 1);

            mp[key] = newNode;

            // Create frequency 1 list if needed
            if(freq.find(1) == freq.end()) freq[1] = new DLL();

            // Insert into frequency 1 list
            insert(freq[1], newNode);
        } else {
            // if key already exists, update value and send to right
            ListNode* ptr = mp[key];
            ptr->val = value;

            // Remove from current frequency list
            remove(ptr);

            // check and remove old frequency list
            if(freq[ptr->freq]->left->next == freq[ptr->freq]->right) freq.erase(ptr->freq);
            
            // Increase frequency
            ptr->freq++;

            // Create frequency list if it doesn't exist
            if(freq.find(ptr->freq) == freq.end()) freq[ptr->freq] = new DLL();

            // Insert into new frequency list
            insert(freq[ptr->freq], ptr);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */