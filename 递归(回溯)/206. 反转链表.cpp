class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head && head->next) {
            ListNode* node;
            node = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return node;
        }
        return head;
    }
};
