#include "qgsort.h"

void swap(int * a, int * b)
{
	int p = *b;
	*b = *a;
	*a = p;
}

void insertSort(int * a, int n)
{
	for (int i = 1; i<n; i++) {
		int key = a[i];
		int j = i - 1;
		while ((j >= 0) && (key<a[j])) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void MergeArray(int * a, int begin, int mid, int end, int * temp)
{
	int i, p, k;
	i = begin;
	p = mid+1;
	k = 0;
	while ((i <= mid) && (p <= end))
	{
		if (a[i] < a[p])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[p++];
		}
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while(p<=end)
		temp[k++] = a[p++];
	for (int q = 0; q < k; q++)
	{
		a[q+begin] = temp[q];
	}
	
}

void MergeSort(int * a, int begin, int end, int * temp)
{
	if (begin >=end)return;
	int mid = begin+(end - begin) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}

void QuickSort_Recursion(int * a, int begin, int end)
{
	if (begin > end)return;
	int key =a[begin], p = begin , q = end;
	if (p == q)
	{
		swap(&a[p], &a[q]);
	}
	while (p != q)
	{
		while (a[q] >= key && p < q)
			--q;
		while (a[p] <= key && p < q)
			++p;
		if (p < q)
		{
			swap(&a[p], &a[q]);
		}
	}
	a[begin] = a[p];
	a[p] = key;
	QuickSort_Recursion(a, begin, p-1);
	QuickSort_Recursion(a, q + 1, end);
	return;
}

void QuickSort(int * a, int size)
{
	int minindex = 0, maxindex = size - 1, midindex = (minindex + maxindex) / 2;
	pair<int, int>apair;
	apair.first = 0;
	apair.second = size - 1;
	stack<pair<int, int>>p;
	p.push(apair);
	while (!p.empty())
	{
		apair = p.top();
		p.pop();
		minindex = apair.first;
		maxindex = apair.second;
		midindex = Partition(a, minindex, maxindex);
		if (minindex < midindex - 1)
		{
			apair.first = minindex;
			apair.second = midindex - 1;
			p.push(apair);
		}
		if (maxindex > midindex + 1)
		{
			apair.first = midindex + 1;
			apair.second = maxindex;
			p.push(apair);
		}
	}
}

int Partition(int * a, int begin, int end)
{
	int key = a[begin], p = begin, q = end;
	//cout << "key:"<<key <<"  begin:"<<begin<<"  end:"<<end<<endl;
	if (p == q)
	{
		swap(&a[p], &a[q]);
	}
	while (p != q)
	{
		while (a[q] >= key && p < q)
			--q;
		while (a[p] <= key && p < q)
			++p;
		if (p < q)
		{
			swap(&a[p], &a[q]);
		}
	}
	swap(&a[begin], &a[p]);
	return p;
}

void CountSort(int * a, int size, int max)
{
	int *b = new int [max+1] {0};
	int *c = new int[size] {0};
	int t = 0;
	for (t= 0; t < size; t++)
	{
		++b[a[t]];
	}
	
	for (t = 1; t< max+1; t++)
	{
		b[t] += b[t - 1];
	}
	
	for (t = size - 1; t >= 0; t--)
	{
		c[--b[a[t]]] = a[t];
		
	}
	
	for (t = 0; t < size; t++)
	{
		a[t] = c[t];
	}
	
	delete(b);
	delete(c);
	b = nullptr;
	c = nullptr;
}

void RadixCountSort(int * a, int size)
{
	vector<vector<int>>b(10,vector<int>());
	int *c = new int[size];
	int t = 0,i,p,status,num=0,key=a[0];
	for (t = 0; t < size; t++)
	{
		if (a[t] > key)key = a[t];
	}
	while (key / 10 != 0)
	{
		++num;
		key /= key;
	}
	++num;
	for (t = 1; t <= num; t++)
	{
		
		for (status = size-1; status >=0; status--)
		{
			p = t-1;
			key = a[status];
			while (key / 10!=0 && p > 0)
			{
				key /= 10;
				--p;
			}
			if (p > 0)key = 0;
			else key %= 10;
			b[key].push_back(a[status]);
		}
		
		for (i = 0,p=0; i < size; i++)
		{
			while(b[p].empty())++p;
			a[i] = b[p].back();
			b[p].pop_back();
		}
	}
	delete(c);
	c = nullptr;
}

void ColorSort(int * a, int size)
{
	int p = 0, p1 = 0, p2 = size - 1;
	while (p1 != p2)
	{
		while (a[p1] != 2 && p1 < p2)++p1;
		if (a[p1] == 2 && a[p2] !=2)swap(&a[p1], &a[p2]);
		while (a[p2] == 2 && p1 < p2)--p2;
		if(a[p2]==0 && a[p1] != 0)swap(&a[p1], &a[p2]);
	}
	while (p != p1)
	{
		while (a[p1] != 0 && p < p1)--p1;
		if (a[p1] == 0 && a[p] != 0)swap(&a[p1], &a[p]);
		while (a[p] == 0 && p < p1)++p;
		if (a[p1] == 0 && a[p] != 0)swap(&a[p1], &a[p]);
	}
}

int Find(int * a, int size,int num)
{
	int minindex = 0, maxindex = size - 1, midindex = (minindex + maxindex) / 2;
	pair<int, int>apair;
	apair.first = 0;
	apair.second = size - 1;
	stack<pair<int, int>>p;
	p.push(apair);
	while (!p.empty())
	{
		apair = p.top();
		p.pop();
		minindex = apair.first;
		maxindex = apair.second;
		midindex = Partition(a, minindex, maxindex);
		if (midindex == (num-1))return a[midindex];
		if (minindex < midindex - 1)
		{
			apair.first = minindex;
			apair.second = midindex - 1;
			p.push(apair);
		}
		if (maxindex > midindex + 1)
		{
			apair.first = midindex + 1;
			apair.second = maxindex;
			p.push(apair);
		}
	}
	return a[num-1];
}
