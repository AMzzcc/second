#include"main.h"
int a[200000] = { 0 };  //普通排序测试
int b[200000] = { 0 };	//承载数组
int c[200000] = { 0 };  //颜色排序测试
using namespace std;
using std::cout;
int main(void)
{
	
	clock_t start, finish; //计时
	int j = 10000, k = 50000, p = 200000,i,t,y,num;
	int choice = -1,choices=-1;
	while (choice)
	{
		cout << "\n算法测试：" << endl;
		cout << "1.插入排序   2. 归并排序  3.快速排序（递归版）  4.快速排序（非递归版）  5.计数排序\n";
		cout << "6.基数计数排序  7:颜色排序 8.查找应用  0.结束当前排序的测试 \n";

		cout << "\n请输入你的测试选择:";
		while (!(std::cin >> choice))
		{
			std::cin.clear();
		}
		cout << "\n";
		switch (choice)
		{
		case 1:
			choices = -1;
			cout << "插入排序:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						start = clock();
						insertSort(a, j);
						finish = clock() - start;
						cout << "插入排序测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						insertSort(a, k);
						finish = clock() - start;
						cout << "插入排序测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						insertSort(a, p);
						finish = clock() - start;
						cout << "插入排序测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							start = clock();
							insertSort(a, 100);
							finish += clock() - start;
						}
						cout << "插入排序测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}
				}
			}
			else if (choices == 2)
			{
				t=0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				insertSort(a, t);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n插入排序测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 2:
			choices = -1;
			cout << "归并排序:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						start = clock();
						MergeSort(a, 0, j - 1, b);
						finish = clock() - start;
						cout << "归并排序测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						MergeSort(a, 0, k - 1, b);
						finish = clock() - start;
						cout << "归并排序测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						MergeSort(a, 0, p - 1, b);
						finish = clock() - start;
						cout << "归并排序测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							start = clock();
							MergeSort(a, 0, 99, b);
							finish += clock() - start;
						}
						cout << "归并快排测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}
				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				MergeSort(a, 0, t-1, b);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << b[i] << " ";
				cout << "\n归并排序测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 3:
			choices = -1;
			cout << "递归快排:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort_Recursion(a, 0, j - 1);
						finish = clock() - start;
						cout << "递归快排测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort_Recursion(a, 0, k - 1);
						finish = clock() - start;
						cout << "递归快排测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort_Recursion(a, 0, p - 1);
						finish = clock() - start;
						cout << "递归快排测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							start = clock();
							QuickSort_Recursion(a, 0, 99);
							finish += clock() - start;
						}
						cout << "递归快排测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				QuickSort_Recursion(a, 0, t-1);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n递归快排测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 4:
			choices = -1;
			cout << "非递归快排:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort(a, j);
						finish = clock() - start;
						cout << "非递归快排测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort(a, k);
						finish = clock() - start;
						cout << "非递归快排测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort(a, p);
						finish = clock() - start;
						cout << "非递归快排测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							start = clock();
							QuickSort(a, 100);
							finish += clock() - start;
						}
						cout << "非递归快排测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				QuickSort(a, t);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n非递归快排测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 5:
			choices = -1;
			cout << "计数排序:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						num = a[i - 1];
						for (i = 0; i < j; i++)
						{
							if (a[i] > num)num = a[i];
						}
						start = clock();
						CountSort(a, j, num);
						finish = clock() - start;
						cout << "计数排序测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						num = a[i - 1];
						for (i = 0; i < k; i++)
						{
							if (a[i] > num)num = a[i];
						}
						start = clock();
						CountSort(a, k, num);
						finish = clock() - start;
						cout << "计数排序测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						num = a[i - 1];
						for (i = 0; i < p; i++)
						{
							if (a[i] > num)num = a[i];
						}
						start = clock();
						CountSort(a, p, num);
						finish = clock() - start;
						cout << "计数排序测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							num = a[i - 1];
							for (i = 0; i < 100; i++)
							{
								if (a[i] > num)num = a[i];
							}
							start = clock();
							CountSort(a, 100, num);
							finish += clock() - start;
						}
						cout << "计数排序测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				num = a[t - 1];
				for (i = 0; i < t; i++)
				{
					if (a[i] > num)num = a[i];
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				CountSort(a, t, num);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n计数排序测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 6:
			choices = -1;
			cout << "基数计数排序:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						start = clock();
						RadixCountSort(a, j);
						finish = clock() - start;
						cout << "基数计数测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						RadixCountSort(a, k);
						finish = clock() - start;
						cout << "基数计数测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						RadixCountSort(a, p);
						finish = clock() - start;
						cout << "基数计数测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							start = clock();
							RadixCountSort(a, 100);
							finish += clock() - start;
						}
						cout << "基数计数测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				RadixCountSort(a, t);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n基数计数排序测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 7:
			choices = -1;
			cout << "颜色排序:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand() % 3;
						}
						start = clock();
						ColorSort(a, j);
						finish = clock() - start;
						cout << "颜色排序测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand() % 3;
						}
						start = clock();
						ColorSort(a, k);
						finish = clock() - start;
						cout << "颜色排序测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand() % 3;
						}
						start = clock();
						ColorSort(a, p);
						finish = clock() - start;
						cout << "颜色排序测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						finish = 0;
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand() % 3;
							}
							start = clock();
							ColorSort(a, 100);
							finish += clock() - start;
						}
						cout << "颜色排序测试100数据*100k次排序use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				cout << "输入十个数字（0，1，2），空格隔开,回车结束,若超出范围，直到输入足够为止：";
				for (t = 0; t < 10; )
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					if (num != 1 && num != 0&&num!=2)
					{
						continue;
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				for (i = 0; i < t; i++)cout << a[i] << " ";
				start = clock();
				ColorSort(a, t);
				finish = clock() - start;
				cout << "排序后:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n颜色排序测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 8:
			choices = -1;
			cout << "查找应用:1.自动测试  2.手动输入\n";
			cout << "\n请输入你的测试选择:";
			while (!(std::cin >> choices))
			{
				std::cin.clear();
			}
			if (choices == 1)
			{
				for (t = 0; t < 4; t++)
				{
					switch (t)
					{
					case 0:
						for (i = 0; i < j; i++)
						{
							a[i] = rand();
						}
						start = clock();
						num = Find(a, j, 5000);
						finish = clock() - start;
						cout << "number:" << num;
						cout << "\t查找应用测试1w数据use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						num = Find(a, k, 5000);
						finish = clock() - start;
						cout << "number:" << num;
						cout << "\t查找应用测试5w数据use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						num = Find(a, p, 5000);
						finish = clock() - start;
						cout << "number:" << num;
						cout << "\t查找应用测试20w数据use times:" << finish << "ms\n";
						break;
					case 3:
						for (y = 0; y < 100000; y++)
						{
							for (i = 0; i < 100; i++)
							{
								a[i] = rand();
							}
							start = clock();
							num = Find(a, 100, 50);
							finish = clock() - start;
							cout << "\t查找应用测试100数据*100k次排序use times:" << finish << "ms\n";
							break;
						}
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "输入十个数字，空格隔开,回车结束：";
				for (p = 0; p < 10; p++)
				{
					while (!(std::cin >> num))
					{
						std::cin.clear();
					}
					a[t] = num;
					++t;
				}
				while (getchar() != '\n');
				cout << "查找第几大元素：";
				while (!(std::cin >> num))
				{
					std::cin.clear();
				}
				if (num < 1 || num>10)
				{
					cout << "超出查找范围!!!" << endl;
					break;
				}
				start = clock();
				num = Find(a, t, num);
				finish = clock() - start;
				cout << "number:" << num;
				cout << "\n查找应用测试数据use times:" << finish << "ms\n\n";
				break;
			}
			break;
		default:
			break;
		}
	}
	
	getchar();
}