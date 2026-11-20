
class MyHashMap {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode(int x, int y): key(x), val(y), next(nullptr) {}
    };
    ListNode* head;

public:
    MyHashMap() {
        head = nullptr;
    }
    
    void put(int key, int value) {
        if (!head) {
            head = new ListNode(key, value);
            return;
        }

        ListNode* ptr = head;
        while(ptr) {
            if(ptr->key == key) {
                ptr->val = value;
                return;
            }
            ptr = ptr->next;
        }

        ptr = head;
        while(ptr && ptr->next) ptr = ptr->next;
        ListNode *newNode = new ListNode(key, value);
        ptr->next = newNode;
    }
    
    int get(int key) {
        if(!head) return -1;

        ListNode* ptr = head;
        while(ptr) {
            if(ptr->key == key) return ptr->val;
            ptr = ptr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        if(!head) return;
        
        if(head->key == key) {
            head = head->next;
            return;
        }

        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;
        while(ptr2) {
            if(ptr2->key == key) {
                ptr1->next = ptr2->next;
                return;
            }

            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */