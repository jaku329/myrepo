// 19. Remove Nth Node From End of List

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy;
  dummy.next = head;
  ListNode* slow = &dummy;
  ListNode* fast = head;
  while (n-- > 0)
    fast = fast->next;
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  ListNode* tmp = slow->next;
  slow->next = slow->next->next;
  delete(tmp);
  return dummy.next;
}
