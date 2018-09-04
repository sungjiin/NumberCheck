#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int comp[3];
int user[3];

// ��ǻ�Ͱ� ������ 3���� ���ڸ� �迭�� ����. ��, �ߺ� ���� �ȵ�!!, 0���� 9������ ����!!
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

// �迭�� ���� �Է�
void ReadInput() {
	printf("�Է� :");
	scanf_s("%d %d %d", &user[0], &user[1], &user[2]);
}

// ��ǻ���� ���ڿ� ���� �ۼ��� ���� �� �� ���� ��Ʈ����ũ ����
int CheckResult() {
	int i, j;
	int st = 0, ball = 0; // comp�� user�� ���ڿ� �迭�� �ڸ��� ������ strike!
	//user�� ���ڰ� comp�� ���� �ȿ� �ִ� ���ڿ� ������ �ڸ��� �ٸ��� ball!
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
	printf("%d��° ����!", count);


	scanf_s("%d", &i);
	return 0;
}