#include "Calculator.h"

Calculator::Calculator()
{
	
}

Calculator::~Calculator()
{
	s.destroyLStack();
	s1.destroyLStack();
	q.destroyLStack();
	q1.destroyLStack();
	
}


bool Calculator::ClearCalculator()
{
	if(!s.top||!s1.top||!q.top||!q1.top)return false;
	//if (isEmpty())return true;
	s.clearStack();
	s1.clearStack();
	q.clearStack();
	q1.clearStack();
	
	return true;
}



bool Calculator::compare(char a, char b)//b��Ҫ�����
{
	if (a == '_')return true;
	if (a == '^')return true;
	if (b == '+' ||b== '-')
	{
		if(a!='(')return true;
		else return false;
	}
	else if (b == '*' || b == '/' || b == '%')
	{
		if (a == '+' || a == '-'||a=='(')return false;
		else return true;
	} 
	return false;
}


void Calculator::change(string input)
{
	node temp;
	for (int i = 0; i < (int)input.length();) 
	{
		if (input[i] == '(') 
		{
			temp.judge = false;
			temp.oper = input[i];
			s.push(temp);
			i++;
		}
		else if (input[i] == ')') 
		{//���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
			while (!s.isEmptyStack() && s.top->next->data.oper != '(') 
			{
				q.push(s.top->next->data);
				s.pop();
			}
			s.pop();//����������
			i++;
		}
		else if (input[i] >= '0'&&input[i] <= '9') 
		{
			//����
			temp.judge = true;
			temp.num = input[i] - '0';
			//cout << temp.num<<endl;  //���Դ���
			i++;//����һλ,��Ϊ���ֲ�һ���Ǹ�λ��
			while (i < (int)input.length() && input[i] >= '0'&&input[i] <= '9')
			{
				temp.num = temp.num * 10 + (input[i] - '0');
				i++;
			}
			q.push(temp);//�����������׺���ʽ
		}
		else if (input[i] == '-')  //����
		{
			negative(input,i);
		}
		else {
			//������
			//��������������������������ȼ����ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
			temp.judge = false;
			while (!s.isEmptyStack() && compare(s.top->next->data.oper,input[i]))
			{
				q.push(s.top->next->data);
				s.pop();
			}
			temp.oper = input[i];
			s.push(temp);
			i++;
		}
	}
	//��ջ��ʣ���������ε�����׺���ʽ
	while (!s.isEmptyStack()) 
	{
		q.push(s.top->next->data);
		s.pop();
	}
	//invert();	
}

bool Calculator::invert()
{
	if(q.isEmptyStack())
	return false;
	int num = q.count;
	while(!q.isEmptyStack())
	{
		//if (q.top->next == nullptr)return false;
		q1.push(q.top->next->data);
		q.top = q.top->next;
		q.count--;
	}
	q.top = q.top2;
	q.count = num;
	return true;
}

bool Calculator::calculate(double &e)
{
	double num_a, num_b;//������a,b
	node cur, temp;
	while (!q1.isEmptyStack()) 
	{//��׺���зǿ�
		cur = (q1.top->next->data);//��¼����Ԫ��
		q1.pop();
		if (cur.judge == true) 
		{//�ǲ���������ջ
			s1.push(cur);
			//cout << "number" << endl;
		}
		else {//�ǲ�����������
			//cout << "zifu" << endl;
			if (cur.oper == '_')
			{
				temp.judge = true;
				temp = s1.top->next->data;
				s1.pop();
				temp.num = -temp.num;
				s1.push(temp);
				continue;
			}
			if (s1.isEmptyStack())return false;	
			num_b = s1.top->next->data.num;
			s1.pop();//�����ڶ�������
			if (s1.isEmptyStack())return false;
			num_a = s1.top->next->data.num;
			s1.pop();//������һ������
			temp.judge = true;
			if (cur.oper == '+') 
			{
				temp.num = num_a + num_b;
			}
			else if (cur.oper == '-')
			{
				temp.num = num_a - num_b;

			}
			else if (cur.oper == '*') 
			{
				temp.num = num_a * num_b;
			}
			else if(cur.oper=='%')
			{
				if (num_b == 0)return false;//��ĸ��Ϊ0
				temp.num = (int)num_a % (int)num_b;
			}
			else if(cur.oper=='/')
			{
				if (num_b == 0)return false;//��ĸ��Ϊ0
				temp.num = num_a / num_b;
			}
			else if (cur.oper == '^')
			{
				temp.num = pow(num_a, num_b);
			}
			else return false;
			s1.push(temp);//�Ѽ����Ľ���ٴ�ѹջ
		}
	}
	e= s1.top->next->data.num;
	return true;
}

bool Calculator::Print(LinkStack < node >& q1)
{
	cout << "ǰ׺���ʽ: ";
	while (!q1.isEmptyStack())
	{
		if (q1.top->next == nullptr)
		{
			break;
		}
		if (q1.top->next->data.judge)
			cout << q1.top->next->data.num;
		else
			cout << q1.top->next->data.oper;
		q1.top = q1.top->next;
	}
	cout << '\n';
	q1.top = q1.top2;
	return true;
}



bool Calculator::negative(string input, int &i)   //�����á�_'����ķ���
{
	//A.�ڿ�ͷ
	node temp;
	temp.judge = false;
	if ((i == 0 &&input[i + 1] == '-')||(i>0&&input[i-1]=='('&&input[i + 1] == '-'))
	{
		i += 2;
		return true;
	}
	else if (i == 0 && input[i + 1] == '(')
	{
		temp.oper = '_';
		s.push(temp);
		i++;
		return true;
	}
	else if (i == 0 && input[i + 1] >= '0'&&input[i + 1] <= '9')  //A�ڿ�ͷ+num
	{
	//����
		temp.judge = true;
		temp.num = input[i + 1] - '0';
		//cout << temp.num<<endl;  //���Դ���
		i += 2;//����һλ,��Ϊ���ֲ�һ���Ǹ�λ��
		while (i < (int)input.length() && input[i] >= '0'&&input[i] <= '9')
		{
			temp.num = temp.num * 10 + (input[i] - '0');
			i++;
		}
			temp.num = -temp.num;
			q.push(temp);//�����������׺���ʽ
			return true;
	}
											//B���м䣬ǰ��һ����Ҫ����
	if (i > 0 && input[i - 1] == '(')
	{
		if (input[i + 1] == '+' || input[i + 1] == '*' || input[i + 1] == '/' || input[i + 1] == '%')
		{
			while (!s.isEmptyStack() && compare(s.top->next->data.oper, input[i]))
			{
				q.push(s.top->next->data);
				s.pop();
			}
			temp.oper = input[i];
			s.push(temp);
			i++;
			return true;
		}
		temp.oper = '_';
		s.push(temp);
		i++;
		return true;
	}
	//����ȫΪ�����
	while (!s.isEmptyStack() && compare(s.top->next->data.oper, input[i]))
	{
		q.push(s.top->next->data);
		s.pop();
	}
	temp.oper = input[i];
	s.push(temp);
	i++;
	return true;
}


