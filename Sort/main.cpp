#include"main.h"
int a[200000] = { 0 };  //��ͨ�������
int b[200000] = { 0 };	//��������
int c[200000] = { 0 };  //��ɫ�������
using namespace std;
using std::cout;
int main(void)
{
	
	clock_t start, finish; //��ʱ
	int j = 10000, k = 50000, p = 200000,i,t,y,num;
	int choice = -1,choices=-1;
	while (choice)
	{
		cout << "\n�㷨���ԣ�" << endl;
		cout << "1.��������   2. �鲢����  3.�������򣨵ݹ�棩  4.�������򣨷ǵݹ�棩  5.��������\n";
		cout << "6.������������  7:��ɫ���� 8.����Ӧ��  0.������ǰ����Ĳ��� \n";

		cout << "\n��������Ĳ���ѡ��:";
		while (!(std::cin >> choice))
		{
			std::cin.clear();
		}
		cout << "\n";
		switch (choice)
		{
		case 1:
			choices = -1;
			cout << "��������:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "�����������1w����use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						insertSort(a, k);
						finish = clock() - start;
						cout << "�����������5w����use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						insertSort(a, p);
						finish = clock() - start;
						cout << "�����������20w����use times:" << finish << "ms\n";
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
						cout << "�����������100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}
				}
			}
			else if (choices == 2)
			{
				t=0;
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n���������������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 2:
			choices = -1;
			cout << "�鲢����:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "�鲢�������1w����use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						MergeSort(a, 0, k - 1, b);
						finish = clock() - start;
						cout << "�鲢�������5w����use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						MergeSort(a, 0, p - 1, b);
						finish = clock() - start;
						cout << "�鲢�������20w����use times:" << finish << "ms\n";
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
						cout << "�鲢���Ų���100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}
				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << b[i] << " ";
				cout << "\n�鲢�����������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 3:
			choices = -1;
			cout << "�ݹ����:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "�ݹ���Ų���1w����use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort_Recursion(a, 0, k - 1);
						finish = clock() - start;
						cout << "�ݹ���Ų���5w����use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort_Recursion(a, 0, p - 1);
						finish = clock() - start;
						cout << "�ݹ���Ų���20w����use times:" << finish << "ms\n";
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
						cout << "�ݹ���Ų���100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n�ݹ���Ų�������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 4:
			choices = -1;
			cout << "�ǵݹ����:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "�ǵݹ���Ų���1w����use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort(a, k);
						finish = clock() - start;
						cout << "�ǵݹ���Ų���5w����use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						QuickSort(a, p);
						finish = clock() - start;
						cout << "�ǵݹ���Ų���20w����use times:" << finish << "ms\n";
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
						cout << "�ǵݹ���Ų���100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n�ǵݹ���Ų�������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 5:
			choices = -1;
			cout << "��������:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "�����������1w����use times:" << finish << "ms\n";
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
						cout << "�����������5w����use times:" << finish << "ms\n";
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
						cout << "�����������20w����use times:" << finish << "ms\n";
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
						cout << "�����������100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n���������������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 6:
			choices = -1;
			cout << "������������:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "������������1w����use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand();
						}
						start = clock();
						RadixCountSort(a, k);
						finish = clock() - start;
						cout << "������������5w����use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand();
						}
						start = clock();
						RadixCountSort(a, p);
						finish = clock() - start;
						cout << "������������20w����use times:" << finish << "ms\n";
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
						cout << "������������100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				t = 0;
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n�������������������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 7:
			choices = -1;
			cout << "��ɫ����:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "��ɫ�������1w����use times:" << finish << "ms\n";
						break;
					case 1:
						for (i = 0; i < k; i++)
						{
							a[i] = rand() % 3;
						}
						start = clock();
						ColorSort(a, k);
						finish = clock() - start;
						cout << "��ɫ�������5w����use times:" << finish << "ms\n";
						break;
					case 2:
						for (i = 0; i < p; i++)
						{
							a[i] = rand() % 3;
						}
						start = clock();
						ColorSort(a, p);
						finish = clock() - start;
						cout << "��ɫ�������20w����use times:" << finish << "ms\n";
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
						cout << "��ɫ�������100����*100k������use times:" << finish << "ms\n";
						break;
					default:
						break;
					}

				}
			}
			else if (choices == 2)
			{
				cout << "����ʮ�����֣�0��1��2�����ո����,�س�����,��������Χ��ֱ�������㹻Ϊֹ��";
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
				cout << "�����:";
				for (i = 0; i < t; i++)cout << a[i] << " ";
				cout << "\n��ɫ�����������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		case 8:
			choices = -1;
			cout << "����Ӧ��:1.�Զ�����  2.�ֶ�����\n";
			cout << "\n��������Ĳ���ѡ��:";
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
						cout << "\t����Ӧ�ò���1w����use times:" << finish << "ms\n";
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
						cout << "\t����Ӧ�ò���5w����use times:" << finish << "ms\n";
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
						cout << "\t����Ӧ�ò���20w����use times:" << finish << "ms\n";
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
							cout << "\t����Ӧ�ò���100����*100k������use times:" << finish << "ms\n";
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
				cout << "����ʮ�����֣��ո����,�س�������";
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
				cout << "���ҵڼ���Ԫ�أ�";
				while (!(std::cin >> num))
				{
					std::cin.clear();
				}
				if (num < 1 || num>10)
				{
					cout << "�������ҷ�Χ!!!" << endl;
					break;
				}
				start = clock();
				num = Find(a, t, num);
				finish = clock() - start;
				cout << "number:" << num;
				cout << "\n����Ӧ�ò�������use times:" << finish << "ms\n\n";
				break;
			}
			break;
		default:
			break;
		}
	}
	
	getchar();
}