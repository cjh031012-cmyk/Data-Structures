///문제 3번
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
	if (head == NULL) return;
	ListNode* p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

void free_list(ListNode* head) {
	if (head == NULL) return;
	for (ListNode* p = head->link, *temp; p != head; free(temp))
		temp = p, p = p->link;
	free(head);
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* search(ListNode* L, element data) {
	ListNode* p = L;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != L);
	return NULL;
}

int main(void) {
	ListNode* head = NULL;
	ListNode* result = NULL;

	head = insert_first(head, 10);
	head = insert_first(head, 20);

	result = search(head, 20);

	if (result != NULL)
		printf("찾음: %d\n", result->data);
	else
		printf("못찾음\n");

	free_list(head);
	return 0;
}


/// 4번 문제
int get_size(ListNode* L) {
	ListNode* p = L;
	int count = 0;
	do {
		count++;
		p = p->link;
	} while (p != L);
	return count;
}

int main(void) {
	ListNode* head = NULL;
	ListNode* result = NULL;

	int size = 0;

	head = insert_first(head, 10);
	head = insert_first(head, 20);

	print_list(head);
	printf("\n");

	result = search(head, 20);
	if (result != NULL)
		printf("찾음: %d\n", result->data);
	else
		printf("못찾음\n");

	size = get_size(head);
	printf("데이터 개수는: %d\n", size);

	free_list(head);
	return 0;
}
