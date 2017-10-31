#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

typedef long long ll;
#define MAX 500001
int mod = (int)(pow(10, 9) + 7);

vector<int>* sieve()
{
	bool isPrime[MAX];
	for(int i = 2; i<=MAX; i++)
		isPrime[i] = true;
	for(int i = 2; i*i <= MAX; i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i; j<=MAX; j+=i)
				isPrime[j] = false;
		}
	}
	vector<int>*primes = new vector<int>();
	primes->push_back(2);
	for(int i = 3; i <= MAX; i++)
	{
		if(isPrime[i])
			primes->push_back(i);
	}
	return primes;
}

ll divisors(int n, vector<int>* & primes)
{
	ll result = 1;
	for(int i = 0; primes->at(i) <= n; i++)
	{
		int k = primes->at(i);
		ll count = 0;
		while(n/k != 0)
		{
			count = (count + (n/k))%mod;
			k = k*primes->at(i);
		}
		result = (result * ((count + 1)%mod))%mod;
	}
	return result;
}

int main()
{
	int t;
	cin>>t;
	vector<int>* primes = sieve();
	while(t--)
	{
		int n;
		cin>>n;
		cout<<divisors(n, primes)<<endl;
	}
}