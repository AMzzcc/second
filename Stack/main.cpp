#include"main.h"
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string input;
	Calculator cal;
	double answer;
	int choice=-1;
	/*LinkStack<int> firstStack;//���Դ���
	for (int c = 0; c <= 6; ++c)
	{
		firstStack.push(c);
	}
	firstStack.stackTraverse();
	cout << firstStack.getTopStack() << endl;
	cout << firstStack.LStackLength() << endl;*/
	//firstStack.pop();
	/*if (firstStack.isEmptyStack())cout << "is empty" << endl;
	firstStack.pop();*/

	while (true)
	{
		choice = -1;
		cout << '\n';
		cout << "-------------------------------Calculator Demo-----------------------" << endl;
		cout << "0.exit  1.calculator  2.direction for use" << endl;
		cout << "Please input your choice correctly:";
		while (true)
		{
			cin >> choice;
			if (choice == 0 || choice == 1 || choice == 2)
			{
				cout << "You input the choice correctly,very great!You are a clever human!" << endl;
				cout << '\n';
				break;
			}
			else
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Please look at the direction for use carefully and input your choice correctly,OK?:";
			}
		}
		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			cout << "Please input correctly:";
			while (true)
			{
				cin >> input;
				cal.change(input);
				cal.Print(cal.q1);
				if (cal.calculate(answer))
				{
					cout << "The answer is:";
					cout << answer << endl;
					cout << '\n';
					if (cal.ClearCalculator());
					else cout << "clear error" << endl;
					break;
				}
				else cout << "Error input!Please input correctly:";
				if (cal.ClearCalculator());
				else cout << "clear error" << endl;
			}
		}
		else if (choice == 2)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~direction for use~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout << "In this Calculator,you can use operator: + - * / %    and use integer...." << endl;
			cout << "That is all,try to use the Calculator correctly!" << endl;
			cout << '\n';
		}
		
	}
	
	/*for (int c = 0; c < input.length(); c++)//���Դ���
	{
		cout << input[c]<<endl;
	}*/
	system("pause");
	return 0;
}
