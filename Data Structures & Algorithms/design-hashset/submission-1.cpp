class MyHashSet {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode *head;

public:
    MyHashSet() {
        head = nullptr;
    }
    
    void add(int key) {
        if (!head) {
            head = new ListNode(key);
            return;
        }

        if(contains(key)) return;

        ListNode *ptr = head;
        while(ptr && ptr->next) ptr = ptr->next;
        ListNode *newNode = new ListNode(key);
        ptr->next= newNode;
    }
    
    void remove(int key) {
        if (!head) return;

        if (head->val == key) {
            head = head->next;
            return;
        }
        
        ListNode *ptr1 = head, *ptr2 = head;
        while(ptr1 && ptr2) {
            if(ptr2->val == key) ptr1->next = ptr2->next;
            ptr1 = ptr2;
            ptr2 = ptr1->next;
        }
    }
    
    bool contains(int key) {
        ListNode *ptr = head;
        while(ptr) {
            if(ptr->val == key) return true;
            ptr = ptr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */