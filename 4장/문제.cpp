10번

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 6

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
	}
	else s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void) {
	int num, value;
	StackType* s= (StackType*)malloc(sizeof(StackType));
	init_stack(s);

	printf("정수 배열의 크기: ");
	scanf("%d", &num);

	printf("정수 입력: ");
	for (int i = 0; i < num; i++) {
		scanf("%d", &value);
		push(s, value);
	}

	printf("반전된 정수 배열: ");
	while (!is_empty(s))
	printf("%d ", pop(s));
}
