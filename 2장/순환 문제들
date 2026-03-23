///08번
#include<stdio.h>
int recirsive(int n);
int main(void) {
	int i = recirsive(5);
	printf("반환값 : %d", i);
	return 0;
}
int recirsive(int n) {
	printf("%d\n", n);
	if (n < 1) return 2;
	else return(2 * recirsive(n - 1));
}


///09번
#include<stdio.h>
int recursive(int n);
int main(void) {
	int i = recursive(10);
	printf("반환값: %d", i);
	return 0;
}
int recursive(int n) {
	printf("%d\n", n);
	if (n < 1)return -1;
	else return(recursive(n - 3) + 1);
}


///10번
#include<stdio.h>
int recursive(int n);
int main(void) {
	int i = recursive(5);
	return 0;
}
int recursive(int n) {
	if (n != 1) recursive(n - 1);
	printf("%d\n", n);
}


///11번
#include <stdio.h>
void asterisk(int i);
int main(void) {
	asterisk(5);
}
void asterisk(int i) {
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*");
}


///12번
#include <stdio.h>
void unknown() {
    int ch;
    if ((ch = getchar()) != '\n') {
        unknown();
    }
    putchar(ch);
}

int main(void) {
    printf("문자열을 입력하세요: ");
    unknown();
    return 0;
}



///13번
#include <stdio.h>
int sum(int n)
{
	if (n == 1) return 1;
	else return n + sum(n - 1);
}
int main(void)
{
	printf("%d", sum(n));
	return 0;
}


///14번
//#include <stdio.h>
double sum(int n)
{
	if (n == 1) return 1;
	else return (double)1 / n + sum(n - 1);
}
int main(void)
{
	printf("%f", sum(n));
	return 0;
}


///15번
#include<stdio.h>
int fib(int n) {
	printf("fib(%d) is called\n", n);
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
};
int main(void) {
	int i = fib(6);
	return 0;
}


///16번
int sum(int n)
{
	int result = 0;
	for (int i = 1; i <= n; i++)
		result += i;
	return result;
}
int main(void)
{
	printf("%d", sum(n));
	return 0;
}

///17번
//********순환
#include <stdio.h>
int bioomial(int n, int k)
{
    if (k == 0 || n == 1) return 1;
    else return bioomial(n - 1, k - 1) + bioomial(n - 1, k);
}
int main(void)
{
    printf("%f", bioomial(n, k));
    return 0;
}

//**********반복
int bioomial(int n, int k)
{
    int x, y, z;
    for (int i = 0; i < n; i++)
        x *= i;
    for (int i = 0; i < k; i++)
        y *= i;
    for (int i = 0; i < n - k; i++)
        z *= i;
    return x / (y * z);
}



/// 21번
#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

#define WHITE 0
#define BLACK 1
#define YELLOW 2

int screen[WIDTH][HEIGHT];   // ← 오타 수정

char read_pixel(int x, int y)
{
    return screen[x][y];
}

void write_pixel(int x, int y, int color)
{
    screen[x][y] = color;
}

// 영역 채우기 (경계 체크 추가)
void flood_fill(int x, int y)
{
    // 배열 범위 벗어나면 종료
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    if (read_pixel(x, y) == WHITE)
    {
        write_pixel(x, y, BLACK);

        flood_fill(x + 1, y);
        flood_fill(x - 1, y);
        flood_fill(x, y + 1);
        flood_fill(x, y - 1);
    }
}

// 화면 출력 함수
void print_screen()
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", screen[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    // 초기값: 전부 WHITE
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            screen[i][j] = WHITE;

    // 장애물 만들기 (YELLOW)
    screen[4][4] = YELLOW;
    screen[4][5] = YELLOW;
    screen[5][4] = YELLOW;

    printf("채우기 전:\n");
    print_screen();

    // (0,0)부터 채우기
    flood_fill(0, 0);

    printf("\n채우기 후:\n");
    print_screen();

    return 0;
}
