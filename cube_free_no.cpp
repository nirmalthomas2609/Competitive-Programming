#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main ()
{
	int * a = new int[1000000];
	for(int i = 0; i < 1000000; i++)
		a[i] = 0;
	for(int i = 2; i < 101; i++)
	{
		int j = i*i*i;
		while(j <= 1000000)
		{
			a[j-1] = -1;
			j += (i*i*i);
		}
	}
	int c = 1;
	for(int i = 0; i < 1000000; i++)
	{
		if(a[i] != -1)
		{
			a[i] = c++;
		}
	}
	cin>>c;
	for (int r = 1; r<=c; r++)
	{
		int n;
		cin>>n;
		if(a[n-1] == -1)
		{
			cout<<"Case "<<r<<": Not Cube Free"<<endl;
			continue;
		}
		cout<<"Case "<<r<<": "<<a[n-1]<<endl;
	}
	return 0;
}