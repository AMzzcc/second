#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"LinkStack.h"
#include"SqStack.h"
#include<math.h>
#include<iostream>
using namespace std;
class Calculator
{
public:
	
	typedef struct Node {
		double num;//操作数
		char oper;//操作符
		bool judge;//true表示操作数，false表示操作符
	}node;
	LinkStack < node > s;//操作符
	LinkStack < node > s1;//操作数
	LinkStack < node > q;//后缀表达式倒数
	LinkStack < node > q1;//真正后缀表达式

	Calculator();
	~Calculator();
	bool ClearCalculator();//清除计算器
	bool compare(char a, char b);	//操作符优先级比较
	void change(string input);    //中缀变后缀
	bool invert();			//转置成真正后缀表达式
	bool calculate(double &e);  //计算
	bool Print(LinkStack < node >&q1);//输出后缀表达式
	bool negative(string input, int &i);//处理负数
public:
	
};

#endif // !CALCULATOR_H

