#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main ()
{
	int * a = new int[1000000];
	a[0] = 0;
	for(int i = 1; i < 1000000; i++)
		a[i] = 1;
	for(int i = 2; i <= 500000; i++)
	{
		if(a[i-1] == 1)
		{
			int j = 2*i;
			while(j <= 1000000)
			{
				a[j-1]++;
				j += i;
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int x, y, n;
		cin>>x>>y>>n;
		int p = 0;
		for(int i = x; i <= y; i++)
		{
			if(a[i -1 ] == 1 || a[i-1] == 0)
			{
				if(a[i-1] == n)
					p++;
			}
			else
			{
				if(a[i-1] - 1 == n)
					p++;
			}
		}
		cout<<p<<endl;
	}
	return 0;
}