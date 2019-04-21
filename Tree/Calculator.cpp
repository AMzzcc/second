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



bool Calculator::compare(char a, char b)//b是要插入的
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
		{//遇到右括号：执行出栈操作，输出到后缀表达式，直到弹出的是左括号
			while (!s.isEmptyStack() && s.top->next->data.oper != '(') 
			{
				q.push(s.top->next->data);
				s.pop();
			}
			s.pop();//弹出左括号
			i++;
		}
		else if (input[i] >= '0'&&input[i] <= '9') 
		{
			//数字
			temp.judge = true;
			temp.num = input[i] - '0';
			//cout << temp.num<<endl;  //测试代码
			i++;//后移一位,因为数字不一定是个位数
			while (i < (int)input.length() && input[i] >= '0'&&input[i] <= '9')
			{
				temp.num = temp.num * 10 + (input[i] - '0');
				i++;
			}
			q.push(temp);//操作数进入后缀表达式
		}
		else if (input[i] == '-')  //负号
		{
			negative(input,i);
		}
		else {
			//操作符
			//遇到其他运算符：弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈
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
	//将栈中剩余内容依次弹出后缀表达式
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
	double num_a, num_b;//操作数a,b
	node cur, temp;
	while (!q1.isEmptyStack()) 
	{//后缀队列非空
		cur = (q1.top->next->data);//记录队首元素
		q1.pop();
		if (cur.judge == true) 
		{//是操作数进入栈
			s1.push(cur);
			//cout << "number" << endl;
		}
		else {//是操作符就运算
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
			s1.pop();//弹出第二操作数
			if (s1.isEmptyStack())return false;
			num_a = s1.top->next->data.num;
			s1.pop();//弹出第一操作数
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
				if (num_b == 0)return false;//分母不为0
				temp.num = (int)num_a % (int)num_b;
			}
			else if(cur.oper=='/')
			{
				if (num_b == 0)return false;//分母不为0
				temp.num = num_a / num_b;
			}
			else if (cur.oper == '^')
			{
				temp.num = pow(num_a, num_b);
			}
			else return false;
			s1.push(temp);//把计算后的结果再次压栈
		}
	}
	e= s1.top->next->data.num;
	return true;
}

bool Calculator::Print(LinkStack < node >& q1)
{
	cout << "前缀表达式: ";
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



bool Calculator::negative(string input, int &i)   //负号用‘_'代替的分离
{
	//A.在开头
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
	else if (i == 0 && input[i + 1] >= '0'&&input[i + 1] <= '9')  //A在开头+num
	{
	//数字
		temp.judge = true;
		temp.num = input[i + 1] - '0';
		//cout << temp.num<<endl;  //测试代码
		i += 2;//后移一位,因为数字不一定是个位数
		while (i < (int)input.length() && input[i] >= '0'&&input[i] <= '9')
		{
			temp.num = temp.num * 10 + (input[i] - '0');
			i++;
		}
			temp.num = -temp.num;
			q.push(temp);//操作数进入后缀表达式
			return true;
	}
											//B在中间，前面一定需要括号
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
	//否则全为运算符
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


