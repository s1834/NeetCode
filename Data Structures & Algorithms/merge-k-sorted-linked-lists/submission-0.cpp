/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
struct CompareListNode {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        int n = lists.size();
        if(n == 0) return NULL;
        for(int i = 0; i < n; i++) {
            ListNode* ptr = lists[i];
            while(ptr) {
                pq.push(ptr);
                ptr = ptr->next;
            }
        }

        if(pq.size() == 0) return NULL;

        ListNode* ans = new ListNode(pq.top()->val);
        ListNode* head = ans;
        pq.pop();
        while(!pq.empty()) {
            ListNode* temp = new ListNode(pq.top()->val);
            ans->next = temp;
            ans = temp;
            pq.pop();
        }
        
        return head;
    }
};