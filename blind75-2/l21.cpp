// 21. Merge Two Sorted Lists

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == NULL)
    return list2;
  else if (list2 == NULL)
    return list1;

  ListNode* head;
  ListNode* tmp;
  if (list1->val < list2->val) {
    head = list1;
    list1 = list1->next;
  }
  else {
    head = list2;
    list2 = list2->next;
  }
  
  tmp = head;
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
  if (list1) tmp->next = list1;
  else if (list2) tmp->next = list2;
  return head;
}

// dummy node
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == NULL)
    return list2;
  else if (list2 == NULL)
    return list1;

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
  if (list1) tmp->next = list1;
  else if (list2) tmp->next = list2;
  return dummy.next;
}
