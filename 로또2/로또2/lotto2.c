#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void lottonumber(int* lotto,int *total)//�ζǹ�ȣ ����,�����Լ� lotto=�ζǹ�ȣ, total=����, num =1~45 ����
{
	srand(time(NULL));
	int n = 1;
	int t = 0;
	int i;
	while (n <= 5000)
	{
		for ( i = 0; i < 6; i++)  // �ζǹ�ȣ ����
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
		for (i = 0; i < 6; i++) //�ζǹ�ȣ ����
		{
			total[t] = lotto[i];
			t++;
		}
		n++;
	}
}
void count(int* total, int* numcount) // ���� ���� �Լ� total=��ü ��ȣ, numcount= 1~45 ����
{
	int i = 0;
	int j = 0;
	int x,y;
	for ( i = 1; i < 46; i++)
	{
		for (j = 0; j < 30000; j++)
		{
			x = total[j];	
			if (x==i)  //���ڸ� ���Ͽ� ������ ����
			{
				numcount[i]++;
			}
		}
	}
}
void number(int* num) //1~45 ����
{
	for (int i = 1; i < 46; i++)
	{
		num[i] = i;
	}
}

int main(void)
{
	printf("�ζ� ��÷ ��ȣ �߻� ���ǽ���(5000ȸ ����)\n");
	system("pause");
	int total[30000] = { 0 };//��ü ��ȣ ����
	int lotto[6] = { 0 }; //�ζ� ��ȣ
	int num[46] = { 0 }; //1~45
	int numcount[46] = { 0 }; //1~45 ����
	double level[46] = { 0 }; // Ȯ�� ����
	double x;
	
	number(num);
	lottonumber(lotto,total);
	count(total, numcount);
	
	for (int i = 1; i < 46; i++)
	{
		x = (double)numcount[i] / 30000;
		level[i] = x;
		printf("���� %d:Ƚ�� %d Ȯ�� %.3f\n", num[i] , numcount[i],level[i]);
	}
	printf("\n");
	printf("** ���� ���� ����� ���� **\n\n");

		for (int a= 1; a < 46; a++) //��������
		{
			x = (double)numcount[a] / 30000;
			level[a] = x;
			for (int b = a+1; b < 46; b++)
			{
				if (level[a] < level[b])
				{
					double temp1;
					int temp2, temp3;
					temp1 = level[a];   //Ȯ�� ��������
					level[a] = level[b];
					level[b] = temp1;

					temp2 = num[a]; // Ƚ�� ��������
					num[a] = num[b];
					num[b] = temp2;

					temp3 = numcount[a]; // ���� ��������
					numcount[a] = numcount[b];
					numcount[b] = temp3;
				}
			}
		}

	for (int j = 1; j < 7; j++)
	{
		printf("���� %d Ƚ�� %d Ȯ�� %.3f\n",num[j], numcount[j], level[j]);
	}
	return 0;
}