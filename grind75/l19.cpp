// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == NULL) return NULL;
  
  ListNode* p = head;
  ListNode dummy;
  dummy.next = head;
  ListNode* q = &dummy;
  q->next = head;
  while (n-- > 0 && p) p = p->next;
  if (n > 0) return head;

  while (p) {
    p = p->next;
    q = q->next;
  }

  p = q->next;
  q->next = q->next->next;
  delete(p);
  return dummy.next;
}
