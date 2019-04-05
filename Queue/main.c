#include"main.h"
int main(void)
{
	LQueue Q;
	AQueue R;
	int choice1 = -1;
	int choice2 = -1;
	int num[50] = { 0 };
	char zifu[50] = { '0' };
	double flo[50] = { 0 };
	int i = 0;
	int *n = NULL;
	char *m = NULL;
	double *p = NULL;
	printf("链队列测试：");
	printf("数据类型：1.整数  2.字符  3.double");
	printf("\n请输入你的测试选择:");
	while (scanf_s("%d", &choice1) != 1)
	{
		printf("\nerror,again:");
		fflush(stdin);
		while (getchar() != '\n');
	}
	if (choice1 == 1)
	{
		i = 0;
		InitLQueue(&Q, sizeof(int));
		while (choice2)
		{

			printf("测试项目：");
			printf("1.入队   2.遍历输出  3.链表长度  4.出队  5.输出队尾  6.清除数据 0.结束当前链表的测试\n");
			printf("\n请输入你的测试选择:");
			while (scanf_s("%d", &choice2) != 1)
			{
				printf("\nerror,again:");
				fflush(stdin);
				while (getchar() != '\n');
			}
			switch (choice2)
			{
			case 1:
				printf("输入的数据：");
				while (scanf_s("%d", &num[i]) != 1)
				{
					printf("\nerror,again:");
					fflush(stdin);
					while (getchar() != '\n');
				}
				n = &num[i];
				i++;
				if (EnLQueue(&Q, n));
				printf("\n");
				break;
			case 2:
				printf("队列为：");
				if(TraverseLQueue(&Q, LPrint))printf("\n");
				else printf("The queue is empty\n");
				break;
			case 3:
				printf("The queue's length is %d\n", LengthLQueue(&Q));
				printf("\n");
				break;
			case 4:
				if(DeLQueue(&Q));
				else printf("The queue is empty\n");
				printf("\n");
				break;
			case 5:
				if (GetHeadLQueue(&Q, n))
					LPrint(n, Q.typesize);
				printf("\n");
				break;
			case 6:
				ClearLQueue(&Q);
				break;
			default:
				break;
			}
		}
	}
	else if (choice1 == 2)
	{
		i = 0;
		InitLQueue(&Q, sizeof(char));
		while (choice2)
		{

			printf("测试项目：");
			printf("1.入队   2.遍历输出  3.链表长度  4.出队  5.输出队尾  6.清除数据 0.结束当前链表的测试\n");
			printf("\n请输入你的测试选择:");
			while (scanf_s("%d", &choice2) != 1)
			{
				printf("\nerror,again:");
				fflush(stdin);
				while (getchar() != '\n'&&getchar()!=EOF);
			}
			while (getchar() != '\n');
			switch (choice2)
			{
			case 1:
				printf("输入的数据：");
				while (scanf_s("%c", &zifu[i],1) != 1)
				{
					printf("\nerror,again:");
					fflush(stdin);
					while (getchar() != '\n');
				}
				
				m = &zifu[i];
				i++;
				if (EnLQueue(&Q, m));
				printf("\n");
				break;
			case 2:
				printf("队列为：");
				if(TraverseLQueue(&Q, LPrint))printf("\n");
				else printf("The queue is empty\n");
				break;
			case 3:
				printf("The queue's length is%d\n", LengthLQueue(&Q));
				printf("\n");
				break;
			case 4:
				DeLQueue(&Q);
				printf("\n");
				break;
			case 5:
				if (GetHeadLQueue(&Q, m))
					LPrint(m, Q.typesize);
				printf("\n");
				break;
			case 6:
				ClearLQueue(&Q);
				break;
			default:
				break;
			}
		}
	}
	else if (choice1 == 3)
	{
		InitLQueue(&Q, sizeof(double));
		while (choice2)
		{
			printf("测试项目：");
			printf("1.入队   2.遍历输出  3.链表长度  4.出队  5.输出队尾  6.清除数据 0.结束当前链表的测试\n");
			printf("\n请输入你的测试选择:");
			while (getchar() != '\n'&&getchar() != EOF);
			while (scanf_s("%d", &choice2) != 1)
			{
				printf("\nerror,again:");
				fflush(stdin);
				while (getchar() != '\n');
			}
			switch (choice2)
			{
			case 1:
				printf("输入的数据：");
				while (scanf_s("%lf", &flo[i]) != 1)
				{
					printf("\nerror,again:");
					fflush(stdin);
					while (getchar() != '\n');
				}
				p = &flo[i];
				i++;
				if (EnLQueue(&Q, p));
				printf("\n");
				break;
			case 2:
				printf("队列为：");
				if(TraverseLQueue(&Q, LPrint));
				else printf("The queue is empty");
				printf("\n");
				break;
			case 3:
				printf("The queue's length is%d\n", LengthLQueue(&Q));
				printf("\n");
				break;
			case 4:
				DeLQueue(&Q);
				printf("\n");
				break;
			case 5:
				if (GetHeadLQueue(&Q, p))
					LPrint(p, Q.typesize);
				printf("\n");
				break;
			case 6:
				ClearLQueue(&Q);
				break;
			default:
				break;
			}
		}
	}
	choice1 = -1;
	choice2 = -1;
	printf("============================================================================\n") ;
	getchar();
	getchar();
	system("pause");
	return 0;
}