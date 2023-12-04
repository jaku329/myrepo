// https://leetcode.com/problems/odd-even-linked-list/

ListNode* oddEvenList(ListNode* head) {
  if (head == NULL) return NULL;
  ListNode* oddHead = head;
  ListNode* evenHead = head->next;
  ListNode* odd = head;
  ListNode* even = head->next;
  while (even && even->next) {
    odd->next = even->next;
    odd = even->next;
    even->next = odd->next;
    even = odd->next;
  }
  odd->next = evenHead;
  return oddHead; 
}
