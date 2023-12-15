// 876. Middle of the Linked List

ListNode* middleNode(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}
