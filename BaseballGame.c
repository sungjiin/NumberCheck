#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int comp[3];
int user[3];

// 컴퓨터가 임의의 3개의 숫자를 배열에 저장. 단, 중복 숫자 안됨!!, 0부터 9까지의 숫자!!
void CompInit() {
	int i, j;
	int x;
	x = sizeof(comp) / sizeof(comp[0]);
	srand((int)time(NULL));
	for (i = 0; i < 3; i++) {
		comp[i] = rand() % 10;
		for (j = 0; j < i; j++) {
			if (comp[i] == comp[j] || comp[0] == comp[x])
				i--;
		}
	}
	printf("%d %d %d", comp[0], comp[1], comp[2]);

}

// 배열에 숫자 입력
void ReadInput() {
	printf("입력 :");
	scanf_s("%d %d %d", &user[0], &user[1], &user[2]);
}

// 컴퓨터의 숫자와 내가 작성한 숫자 비교 및 볼과 스트라이크 정리
int CheckResult() {
	int i, j;
	int st = 0, ball = 0; // comp와 user의 숫자와 배열의 자리가 같으면 strike!
	//user의 숫자가 comp의 숫자 안에 있는 숫자와 같지만 자리가 다르면 ball!
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (user[i] == comp[i] && i == j)
			{
				st++;
				break;
			}
			else if (user[i] == comp[j])
				ball++;
		}
	}

	printf("%d strike, %d ball\n", st, ball);

	if (st == 3) return TRUE;
	else return FALSE;
}
int main()
{
	int i, count = 0;
	CompInit();

	while (1)
	{
		count++;
		ReadInput();
		if (CheckResult() == TRUE)
			break;
	}
	printf("%d번째 성공!", count);


	scanf_s("%d", &i);
	return 0;
}