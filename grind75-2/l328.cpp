// 328. Odd Even Linked List

ListNode* oddEvenList(ListNode* head) {
  if (head == NULL) return head;

  ListNode dummy; // even head
  dummy.next = head->next;
  ListNode* odd = head;
  ListNode* even = head->next;
  while (even && even->next) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = dummy.next;
  
  return head;
}
