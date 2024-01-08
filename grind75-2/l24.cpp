// 24. Swap Nodes in Pairs

// iterate
ListNode* swapPairs(ListNode* head) {
  ListNode dummy;
  dummy.next = head;
  ListNode* pre = &dummy;
  ListNode* cur = head;
  ListNode* tmp;
  while (cur && cur->next) {
    tmp = cur->next;
    cur->next = cur->next->next;
    tmp->next = cur;
    pre->next = tmp;
    pre = cur;
    cur = cur->next;
  }
  return dummy.next;
}

// recursive
ListNode* swapPairs(ListNode* head) {
  if (head == NULL || head->next == NULL)
  return head;

  ListNode* tmp = head->next;
  head->next = swapPairs(head->next->next);
  tmp->next = head;
  return tmp;
}
