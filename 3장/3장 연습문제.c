///*********************************
///3장 연습문제 4번

#include <stdio.h>
#include <math.h>
int main(void) {
	int two[10];
	int i = 0;
	for (i = 0; i < 10; i++) {
		two[i] = pow(2, i);
		printf("%d\n", two[i]);
	}
	return 0;
}

///**********************************
/// 3장 연습문제 5번

#include <stdio.h>
typedef struct {
	char name[10];
	int age;
	float pay;
} PERSON;

///************************************
///3장 연습문제 6번

#include <stdio.h>
typedef struct {
	float real;
	float imaginary;
} COMPLEX;
int main(void) {
	COMPLEX c1;
	COMPLEX c2;
}

///****************************************
///3장 연습문제 7번
///  
#pragma warning(disable : 4996)
#include <stdio.h>

typedef struct {
    double real, imag;
} complex;

complex add(complex a, complex b) {
    complex temp = { a.real + b.real, a.imag + b.imag };
    return temp;
}

int main(void) {
    complex a, b, result;

    // 첫 번째 복소수 입력
    printf("첫 번째 복소수 (실수 허수): ");
    scanf("%lf %lf", &a.real, &a.imag);

    // 두 번째 복소수 입력
    printf("두 번째 복소수 (실수 허수): ");
    scanf("%lf %lf", &b.real, &b.imag);

    // 덧셈
    result = add(a, b);

    // 결과 출력
    printf("결과: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}


///10번 문제
#include <stdio.h>
#define MAX_SIZE 100

int items = 0; 

void deleteElement(int array[], int loc) {
    for (int i = loc; i < items - 1; i++) {
        array[i] = array[i + 1];
    }

    array[items - 1] = 0; 
    items--;
}

void printArray(int array[]) {
    for (int i = 0; i < items; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE] = { 10, 20, 30, 40, 50 };
    items = 5;

    printf("삭제 전: ");
    printArray(arr);

    deleteElement(arr, 2);  

    printf("삭제 후: ");
    printArray(arr);

    return 0;
}

////12번
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test {
    int x;
    char s[20];
} test;

int main() {
    test* p;
    p = (test*)malloc(sizeof(test));

    if (p == NULL) {
        exit(1);
    }

    p->x = 100;
    strcpy(p->s, "just testing");

    printf("x = %d\n", p->x);
    printf("s = %s\n", p->s);

    free(p);
    return 0;
}
