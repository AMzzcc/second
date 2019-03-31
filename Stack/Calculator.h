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
		double num;//������
		char oper;//������
		bool judge;//true��ʾ��������false��ʾ������
	}node;
	LinkStack < node > s;//������
	LinkStack < node > s1;//������
	LinkStack < node > q;//��׺���ʽ����
	LinkStack < node > q1;//������׺���ʽ

	Calculator();
	~Calculator();
	bool ClearCalculator();//���������
	bool compare(char a, char b);	//���������ȼ��Ƚ�
	void change(string input);    //��׺���׺
	bool invert();			//ת�ó�������׺���ʽ
	bool calculate(double &e);  //����
	bool Print(LinkStack < node >&q1);//�����׺���ʽ
	bool negative(string input, int &i);//������
public:
	
};

#endif // !CALCULATOR_H

