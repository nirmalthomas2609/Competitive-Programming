#include<iostream>
#include<string>
#include<vector>

using namespace std;

int get_mod_a(string a, int s, int l, int mod, int curr = 0)
{
	if(s == l)
		return curr;
	return get_mod_a(a, s+1, l, mod, ((((curr % mod) * (10 % mod)) % mod) + (((int)a[s] - 48) % mod)) % mod);
}

int gcd(int a, int b)
{
	if(a < b)
		return gcd(b, a);
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		string b;
		cin>>a>>b;
		int c = get_mod_a(b, 0, b.length(), a);
		cout<<gcd(a, c)<<endl;
	}
}