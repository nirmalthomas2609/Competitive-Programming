#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;
int mod = (int)(pow(10, 9) + 7);

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int input[n];
		for(int i = 0; i < n; i++)
			cin>>input[i];
		sort(input, input+n);
		int a[input[n-1]];
		int j = 0;
		for(int i =0; i < input[n-1]; i++)
		{
			if(i+1 == input[j])
			{
				a[i] = 1;
				j++;
			}
			else
				a[i] = 0;
		}
		int p = 0;
		for(int i = 0; i < input[n-1]; i++)
		{
			if(a[i] > 0)
			{
				j = (i+1)*2;
				while(j <= input[n-1])
				{
					if(a[j - 1] > 0)
					{
						a[j-1] += a[i];
					}
					j += (i+1);
				}
				p = (p + a[i]%mod)%mod;
			}
		}
		cout<<p<<endl;
	}
}