class MyCircularQueue {
private: 
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : val(-1), next(nullptr), prev(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    };

    int n, curr;
    ListNode *left, *right;

public:
    MyCircularQueue(int k) {
        n = k;
        curr = 0;
        left = new ListNode();
        right = new ListNode();
        left->next = right;
        right->prev = left;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        ListNode* newNode = new ListNode(value);
        newNode->prev = right->prev;
        newNode->next = right;
        right->prev->next = newNode;
        right->prev = newNode;
        curr++;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        left->next = left->next->next;
        left->next->prev = left;
        curr--;

        return true;
    }
    
    int Front() {
        return left->next->val;
    }
    
    int Rear() {
        return right->prev->val;
    }
    
    bool isEmpty() {
        if(left->next == right) return true;
        return false;
    }
    
    bool isFull() {
        if(curr == n) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */