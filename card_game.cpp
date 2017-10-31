#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<stdlib.h>
#include<map>

using namespace std;

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

map<int, int> prime_factorise(int a, int sieve[])
{
	map<int, int> factors;
	for(int i = 2; i <= a/2; i++)
		if(sieve[i-1] == 1)
			while(a%i == 0 && a>1)
			{
				factors[i]++;
				a = a/i;
			}
  	if(a != 1)
      factors[a] = 1;
	return factors;
}


int valid_decks(int input[], vector<map<int, int> > current_factors, map<int, int> k_factors, int k, int n)
{
	if(k == n)
		return 0;
	int j = 0, i;
	map<int, int> c_factors;
	map<int, int> temp;
	map<int, int>::iterator it;
	for(i = k; i < n; i++)
	{
		temp = current_factors[i];
		for(it = temp.begin(); it != temp.end(); ++it)
			c_factors[it->first] += it->second;
		j = 1;
		for(it = k_factors.begin(); it != k_factors.end(); ++it)
		{
			if(c_factors[it->first] < it->second)
			{
				j = 0;
				break;
			}
		}
		if(j == 1)
			break;
	}
	if(j == 0)
		return 0;
	return (n - i) + valid_decks(input, current_factors, k_factors, k+1, n);
}


void display_factors(int a, map<int, int> b)
{
	cout<<"Displaying the prime factors of "<<a<<endl;
	map<int, int>::iterator it;
	for(it = b.begin(); it!=b.end(); ++it)
	{
		cout<<it->first<<":"<<it->second<<endl;
	}
	cout<<"Displayed the prime factors of "<<a<<endl<<endl;
	return;
}


int get_max(int a, int b)
{
  if(a>=b)
    return a;
  return b;
}


int main()
{
	int n, k;
	cin>>n>>k;
	int *input = new int[n];
	int maxi = -1, i;
	for(i = 0; i < n; i++)
	{
		cin>>input[i];
		maxi = get_max(maxi, input[i]);
	}
	maxi = get_max(maxi, k);
  	maxi /= 2;
  	if(maxi <= 0)
      return 0;
	int sieve[maxi];
	sieve[0] = 0;
	for(i = 1; i < maxi; i++)
		sieve[i] = 1;
	get_sieve(sieve, maxi);
  	map<int, int> prime_factors = prime_factorise(k, sieve);
	display_factors(k, prime_factors);
	vector<map<int, int> > fact_array;
	for(i = 0; i < n; i++)
	{
//      cout<<i<<endl;
		fact_array.push_back(prime_factorise(input[i], sieve));
		display_factors(input[i], fact_array[i]);
	}
	cout<<valid_decks(input, fact_array, prime_factors, 0, n)<<endl;
	return 0;
}