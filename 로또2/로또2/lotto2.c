#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void lottonumber(int* lotto,int *total)//로또번호 생성,저장함수 lotto=로또번호, total=저장, num =1~45 저장
{
	srand(time(NULL));
	int n = 1;
	int t = 0;
	int i;
	while (n <= 5000)
	{
		for ( i = 0; i < 6; i++)  // 로또번호 생성
		{
			lotto[i] = (rand() % 45) + 1;
			for (int j = 0; j < i; j++)
			{
				if (lotto[i] == lotto[j])
				{
					lotto[i] = (rand() % 45) + 1;
				}
			}
		}									
		for (i = 0; i < 6; i++) //로또번호 저장
		{
			total[t] = lotto[i];
			t++;
		}
		n++;
	}
}
void count(int* total, int* numcount) // 갯수 저장 함수 total=전체 번호, numcount= 1~45 갯수
{
	int i = 0;
	int j = 0;
	int x,y;
	for ( i = 1; i < 46; i++)
	{
		for (j = 0; j < 30000; j++)
		{
			x = total[j];	
			if (x==i)  //숫자를 비교하여 같으면 저장
			{
				numcount[i]++;
			}
		}
	}
}
void number(int* num) //1~45 저장
{
	for (int i = 1; i < 46; i++)
	{
		num[i] = i;
	}
}

int main(void)
{
	printf("로또 추첨 번호 발생 모의시험(5000회 시행)\n");
	system("pause");
	int total[30000] = { 0 };//전체 번호 저장
	int lotto[6] = { 0 }; //로또 번호
	int num[46] = { 0 }; //1~45
	int numcount[46] = { 0 }; //1~45 갯수
	double level[46] = { 0 }; // 확률 순서
	double x;
	
	number(num);
	lottonumber(lotto,total);
	count(total, numcount);
	
	for (int i = 1; i < 46; i++)
	{
		x = (double)numcount[i] / 30000;
		level[i] = x;
		printf("숫자 %d:횟수 %d 확률 %.3f\n", num[i] , numcount[i],level[i]);
	}
	printf("\n");
	printf("** 가장 많이 추출된 숫자 **\n\n");

		for (int a= 1; a < 46; a++) //내림차순
		{
			x = (double)numcount[a] / 30000;
			level[a] = x;
			for (int b = a+1; b < 46; b++)
			{
				if (level[a] < level[b])
				{
					double temp1;
					int temp2, temp3;
					temp1 = level[a];   //확률 내림차순
					level[a] = level[b];
					level[b] = temp1;

					temp2 = num[a]; // 횟수 내림차순
					num[a] = num[b];
					num[b] = temp2;

					temp3 = numcount[a]; // 숫자 내림차순
					numcount[a] = numcount[b];
					numcount[b] = temp3;
				}
			}
		}

	for (int j = 1; j < 7; j++)
	{
		printf("숫자 %d 횟수 %d 확률 %.3f\n",num[j], numcount[j], level[j]);
	}
	return 0;
}