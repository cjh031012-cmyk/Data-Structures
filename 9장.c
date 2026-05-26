#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char list[30];
    int priority;
} element;

typedef struct {
    element heap[51]; // 1번 인덱스부터 사용
    int heap_size;
} HeapType;

// 힙 생성
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

// 힙 초기화
void init(HeapType* h)
{
    h->heap_size = 0;
}

// 최소 힙 삽입
void insert_heap(HeapType* h, element item)
{
    int i = ++(h->heap_size);

    while ((i != 1) &&
        (item.priority < h->heap[i / 2].priority))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

// 최소 힙 삭제
element delete_heap(HeapType* h)
{
    int parent, child;
    element item, temp, empty;

    // 힙이 비었을 때
    if (h->heap_size == 0) {
        printf("삭제할 일이 없습니다.\n");

        strcpy(empty.list, "");
        empty.priority = -1;
        return empty;
    }

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];

    parent = 1;
    child = 2;

    while (child <= h->heap_size) {

        // 더 작은 자식 선택
        if ((child < h->heap_size) &&
            (h->heap[child].priority >
                h->heap[child + 1].priority))
        {
            child++;
        }

        if (temp.priority <= h->heap[child].priority)
            break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return item;
}

void help()
{
    printf("\n삽입(i), 삭제(d), 종료(q): ");
}

int main(void)
{
    HeapType* heap = create();
    init(heap);

    element e;
    char command = '\0';

    while (command != 'q') {

        help();

        scanf(" %c", &command);

        switch (command) {

        case 'i':
            printf("할일: ");
            scanf(" %[^\n]", e.list);

            printf("우선순위: ");
            scanf("%d", &e.priority);

            insert_heap(heap, e);

            printf("추가 완료!\n");
            break;

        case 'd':
            e = delete_heap(heap);

            if (e.priority != -1) {
                printf("제일 우선순위가 높은 일은 \"%s\"\n",
                    e.list);
            }
            break;

        case 'q':
            printf("프로그램 종료\n");
            break;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }

    free(heap);

    return 0;
}


/////



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
    int i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

void print_heap(HeapType* h)
{
    printf("Heap : ");
    for (int i = 1; i <= h->heap_size; i++)
    {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int delete_random_heap(HeapType* h, int key)
{
    int p = -1, c;
    element temp;

    // 삭제할 값 찾기
    for (int i = 1; i <= h->heap_size; i++)
    {
        if (h->heap[i].key == key)
        {
            p = i;
            break;
        }
    }

    // 값 없을 때
    if (p == -1)
    {
        printf("%d 없음\n", key);
        return -1;
    }

    int item = h->heap[p].key;

    temp = h->heap[(h->heap_size)--];

    c = 2 * p;

    while (c <= h->heap_size)
    {
        if ((c < h->heap_size) &&
            (h->heap[c].key < h->heap[c + 1].key))
            c++;

        if (temp.key >= h->heap[c].key)
            break;

        h->heap[p] = h->heap[c];
        p = c;
        c *= 2;
    }

    h->heap[p] = temp;

    return item;
}

int main()
{
    HeapType* h = create();
    init(h);

    element e;

    int arr[] = { 10, 30, 50, 20, 80, 40, 60 };

    for (int i = 0; i < 7; i++)
    {
        e.key = arr[i];
        insert_max_heap(h, e);
    }

    printf("삭제 전\n");
    print_heap(h);

    int deleted = delete_random_heap(h, 50);

    if (deleted != -1)
        printf("%d 삭제됨\n", deleted);

    printf("삭제 후\n");
    print_heap(h);

    free(h);

    return 0;
}
