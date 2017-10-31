#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;

struct Group
{
	ll x, y, g;
};

Group gcd(ll a, ll b)
{
	if(b == 0)
	{
		Group temp;
		temp.x = 1;
		temp.y = 0;
		temp.g = a;
		return temp;
	}	
	Group u = gcd(b, a%b);
	Group v;
	v.x = u.y;
	v.y = u.x - ((a/b)*(u.y));
	v.g = u.g;
	return v;
}

ll mod_inverse(ll a, ll m)
{
	ll x = gcd(a, m).x;
	return (x%m + m)%m;
}

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a, b, d;
		cin>>a>>b>>d;
		ll g = __gcd(a, b);
		if(d%g)
		{
			cout<<0<<endl;
			continue;
		}
		if(d == 0)
		{
			cout<<1<<endl;
			continue;
		}
		if(a<b)
			swap(a, b);
		a /= g;
		b /= g;
		d /= g;
//		cout<<"The value of a is "<<a<<endl;
//		cout<<"The value of b is "<<b<<endl;
		ll mmi = mod_inverse(b, a);
//		cout<<"The mod inverse of b wrt a is "<<mmi<<endl;
		ll y1 = ((d%a)*(mmi%a))%a;
		if(d < y1*b)
		{
			cout<<0<<endl;
			continue;
		}
//		cout<<"The minimum value of y at which d-by is divisible by a is "<<y1<<endl;
		ll n = ((d/b) - y1)/a;
//		cout<<"The value of n is "<<n<<endl;
		cout<<n+1<<endl;
	}
}
