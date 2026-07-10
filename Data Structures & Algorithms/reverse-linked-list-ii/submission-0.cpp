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
class Solution {
private:
    ListNode* reverse(ListNode* head, int remove) {
        if(!head || !head->next) return head;
        ListNode *prev = NULL, *curr = head, *nxt = head->next;
        while(remove > 1 && nxt != NULL) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = curr->next;
            remove--;
        }
        curr->next = prev;
        head->next = nxt;
        return curr;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr = head;
        for(int i = 1; i < left - 1; i++) ptr = ptr->next;
        if(left == 1) head = reverse(ptr, right - left + 1);
        else ptr->next = reverse(ptr->next, right - left + 1);
        return head;
    }
};