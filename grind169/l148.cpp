// 148. Sort List

ListNode* findMid(ListNode* head) {
  if (head == NULL) return NULL;

  ListNode* fast = head;
  ListNode* slow = head;
  fast = fast->next;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {
  if (left == NULL && right == NULL) return NULL;
  else if (left == NULL) return right;
  else if (right == NULL) return left;

  ListNode* head;
  if (left->val < right->val) {
    head = left;
    left = left->next;
  }
  else {
    head = right;
    right = right->next;
  }
  ListNode* tmp = head;
  while (left && right) {
    if (left->val < right->val) {
      tmp->next = left;
      left = left->next;
    }
    else {
      tmp->next = right;
      right = right->next;
    }
    tmp = tmp->next;
  }
  if (left)
    tmp->next = left;
  else if (right)
    tmp->next = right;
  return head;
}

ListNode* sortList(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;

  ListNode* lList = findMid(head);
  ListNode* rList = lList->next;
  lList->next = NULL;
  lList = sortList(head);
  rList = sortList(rList);
  return merge(lList, rList);
}
