// 61. Rotate List

ListNode* rotateList(ListNode* head, int k) {
  if (head == NULL || head->next == NULL) return head;
  int size = 1;
  ListNode* tmp = head;
  while (tmp->next) { 
    size++;
    tmp = tmp->next;
  }
  k %= size;
  if (k == 0) return head;
  tmp->next = head;
  k = size - k;
  while (--k > 0)
    head = head->next;
  tmp = head->next;
  head->next = NULL;
  return tmp;
}
