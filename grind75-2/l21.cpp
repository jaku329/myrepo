// 21. Merge Two Sorted Lists

// O(n), O(1)
ListNode* merge(ListNode* list1, ListNode* list2) {
  ListNode dummy;
  ListNode* tmp = &dummy;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      tmp->next = list1;
      list1 = list1->next;
    }
    else {
      tmp->next = list2;
      list2 = list2->next;
    }
    tmp = tmp->next;
  }

  if (list1)
    tmp->next = list1;
  else if (list2)
    tmp->next = list2;

  return dummy.next;
}
