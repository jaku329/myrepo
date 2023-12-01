// https://leetcode.com/problems/swap-nodes-in-pairs/

ListNode* swapPairs(ListNode* head) {
  ListNode dummy;
  dummy.next = head;
  head = &dummy;
  ListNode* tmp;
  while (head->next && head->next->next) {
    tmp = head->next->next;
    head->next->next = tmp->next;
    tmp->next = head->next;
    head->next = tmp;
    head = head->next->next; // or tmp->next
  }

  return dummy.next;
}
