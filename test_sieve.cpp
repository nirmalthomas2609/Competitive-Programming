#include<iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	int a[n];
	a[0] = 0;
	int i, j;
	for(i = 2; i<=n; i++)
		a[i-1] = 1;
	int count = n-1;
	for(i = 2; i*i <= n; i++)
	{
		if(a[i-1] == 1)
		{
			j = 2;
			while(i*j <= n)
			{
				if(a[i*j - 1] == 1)
				{
					a[i*j - 1] = 0;
					count --;
				}
				j++;
			}
		}
	} 
	cout<<count;
	return 0;
}