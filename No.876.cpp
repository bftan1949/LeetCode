//双指针法
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        while (right != NULL && right->next != NULL) {
            left = left->next;
            right = right->next->next;
        }
        return left;
    }
};

//单指针法
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        int i = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        while (i < length / 2 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        return temp;
    }
};
