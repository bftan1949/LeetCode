### 解题思路
首先要考虑格式问题, LeetCode要考虑空指针的问题,所以很坑,要想清楚每一个指针是否存在空指针的情况

其次是**快慢指针**的思想,双指针中一个很重要的应用就是快慢指针,一个指针稍慢在后,一个指针快在前,快指针先出发,拉开n距离,然后二者再同时出发,从而实现找到倒数第n个位置

### 代码

```cpp
//快慢指针
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 首先要创建一个空头结点
        ListNode* first = new ListNode(0, head);
        ListNode* left = first;
        ListNode* right = head;
        for (int i = 0; i < n; i++)
            right = right->next;
        while (right != NULL) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return first->next;
    }
};

//用栈
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //首先创建一个栈
        stack<ListNode*> s;
        // 首先要创建一个空头结点
        ListNode* first = new ListNode(0, head);
        ListNode* ptr = first;
        while (ptr) {
            s.push(ptr);
            ptr = ptr->next;
        }
        //出栈,找到第n个结点的前驱结点
        ListNode* temp;
        while (n >= 0) {
            temp = s.top();
            s.pop();
            n--;
        }
        temp->next = temp->next->next;
        return first->next;
    }
};
```
