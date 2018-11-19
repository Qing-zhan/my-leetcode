// 这道题有简单的做法，即递归，但是一般来讲递归的效率要低，所以用循环的方法做，发现跟别人用递归的方法做相比反而时间更长。。。
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode* head;
	ListNode* curr;
	if (l1->val <= l2->val) {
		head = l1;
		curr = head;
		l1 = l1->next;
	}
	else {
		head = l2;
		curr = head;
		l2 = l2->next;
	}

	while (l1 && l2) {
		if (l1->val <= l2->val) {
			curr->next = l1;
			l1 = l1->next;
			curr = curr->next;
		}
		else {
			curr->next = l2;
			l2 = l2->next;
			curr = curr->next;
		}
	}

	curr->next = l1 == NULL ? l2 : l1;

	return head;

}

