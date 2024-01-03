// 19. Remove Nth Node From End of List

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == NULL) return NULL;

  ListNode dummy;
  dummy.next = head;
  ListNode* fast = head;
  ListNode* slow = &dummy;
  while (n-- > 0 && fast) fast = fast->next;

  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  
  return dummy.next;
}
