#include<iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	int i = 1;
	int t = 0;
	while (i<=n && i<=3)
		t = t + count(n, i);
	cout<<"The no of different ways is "<<t;
}

int count(int n, int i)
{
	if(i == n)
		return 1;
	int j = 1, t = 0;
	while(i<=)
}