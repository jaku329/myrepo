// 206. Reverse Linked List

// iterator
ListNode* reverseList(ListNode* head) {
  ListNode* pre = NULL;
  ListNode* cur = head;
  while (cur) {
    ListNode* tmp = cur->next;
	cur->next = pre;
	pre = cur;
	cur = tmp;
  }
  return pre;
}

// recursive
ListNode* reverseList(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;
  
  ListNode* newHead = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  
  return newHead;
}
