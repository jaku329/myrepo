// https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};
