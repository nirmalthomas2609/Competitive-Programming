#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<math.h>

using namespace std;
int mod = (int)(pow(10, 9) + 7);

void get_sieve(int s[], int l)
{
	for(int i = 2; i <= l; i++)
		if(s[i - 1] == 1)
		{
			int j = i*i;
			while(j <= l)
			{
				s[j-1] = 0;
				j += i;
			}
		}
	return;
}

int prime_factorise(int a, int sieve[])
{
	int c = 0;
	int p = 1;
	for(int i = 2; i <= a; i++)
		if(sieve[i-1] == 1)
		{
			c = 0;
			int j = i;
			while(j <= a)
			{
				c = ((a/j))%mod;
				j = j*i;  
			}
			p = (p * ((c%mod + 1)%mod))%mod;
		}
	return p;
}

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sieve[n];
		get_sieve(sieve, n);
		cout<<prime_factorise(n, sieve)<<endl;
	}
}