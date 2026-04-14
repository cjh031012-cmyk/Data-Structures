///8번

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d)  :  ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_Count(QueueType* q) {
	if (q->front <= q->rear)
		return q->rear - q->front;
	else
		return MAX_QUEUE_SIZE - (q->front - q->rear);
}

int main(void)
{
	QueueType queue;
	int element;
	int count = 0;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
		count = get_Count(&queue);
		printf("원형큐에 존재하는 요소의 개수: %d\n", count);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("-- 데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수:%d \n", element);
		queue_print(&queue);
		count = get_Count(&queue);
		printf("원형큐에 존재하는 요소의 개수: %d\n", count);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}


///9번


int main(void) {
	StackType st1, st2;
	int i = 0;
	init_stack(&st1);
	init_stack(&st2);

	push(&st1, 10);
	push(&st1, 20);
	push(&st1, 30);

	for (i = 0; i < 3; i++) {
		if (is_empty(&st2)) {
			while (!is_empty(&st1)) {
				push(&st2, pop(&st1));
			}
		}
		printf("%d\n", pop(&st2)); 
	}
	return 0;
}
