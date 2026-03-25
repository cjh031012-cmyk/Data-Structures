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
