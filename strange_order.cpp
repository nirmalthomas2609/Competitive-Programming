#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sieve(int a[], int l)
{
//	cout<<"Starting the computation for the sieve\n";
	for(int i = 2; i*i <= l; i++)
	{
		if(a[i] == i)
		{
			for(int j = i*i; j <= l; j += i)
			{
				if(a[j] == j)
					a[j] = i;
			}
		}
	}
//	cout<<"Done with the computation for the sieve\n";
/*	for(int i = 1; i <= l; i++)
	{
		cout<<"i "<<i<<": "<<a[i]<<endl;
	}
	cout<<"Done with the computation of the sieve\n";
	*/
}

int lpd(int a, vector<int> * primes)
{
  for(int i = 0; i < primes->size(); i++)
  {
    if(a%primes->at(i) == 0)
      return primes->at(i);
  }
  return a;
}

vector<int>* return_per(int a, bool marked[], int s[])
{
	int t = a;
//	cout<<"Displaying the factors of a = "<<a<<endl;
//	display_vector(factors);
	vector<int>* temp = new vector<int>();
	temp->push_back(a);
 	t = a;
  	int c;
	while(t > 1)
	{
//		cout<<"The value of t is "<<t<<endl;
      	c = s[t];
//      	cout<<"The least prime divisor of t = "<<t<<" is "<<c<<endl;
      	while(t%c == 0)
          t = t/c;
		int j = a - c;
		while(j > 0)
		{
			if(!marked[j])
			{
				marked[j] = true;
				temp->push_back(j);
			}
			j -= c;
		}
	}
	sort(temp->begin(), temp->end(), greater<int>());
//	cout<<"Displaying the generated vector "<<endl;
//	display_vector(temp);
	return temp;
}

int main ()
{
	int n;
	cin>>n;
	bool marked[(n+1)];
  	marked[0] = false;
	for(int i = 1; i <= n; i++)
		marked[i] = false;
//	cout<<"Displaying the vector of primes"<<endl;
//	display_vector(sieve(n/2));
//	cout<<"Initialising the sieve array\n";
	int *s = new int[n+1];
//	cout<<"Done with initialising the sieve wala array\n";
	for(int i = 1; i <= n; i++)
		s[i] = i;
	sieve(s, n);
//	cout<<"Done with the sieve"<<endl;
//  vector<int>* primes = new vector<int>();
//  primes->push_back(2);
//  primes->push_back(3);
	vector<int>* result = new vector<int>();
	for(int i = n; i >= 1; i--)
	{
//		cout<<"Checking for n = "<<i<<endl;
		if(!marked[i])
		{
//			cout<<"Checking for i = "<<i<<endl;
			marked[i] = true;
			vector<int>* temp = return_per(i, marked, s);
			result->insert(result->end(), temp->begin(), temp->end());
		}
	}
	for(int i = 0; i < result->size(); i++)
	{
		cout<<result->at(i)<<" ";
	}
	return 0;
}