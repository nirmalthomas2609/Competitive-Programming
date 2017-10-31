#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool return_digit(int l, int aim, int ai, int n, int c, int prev_sum = 0)
{
//	cout<<"The prev_sum is "<<prev_sum<<endl;
	if(l == n)
	{
//		cout<<"The valuf of l is equal to n"<<endl;
//		cout<<"The valie of prev_sum now is "<<prev_sum<<endl;
		if(prev_sum == 0)
			return true;
		else
			return false;
	}
	int k = ((ai*c)%10 + aim)%10;
//	cout<<"The next digit calculated is "<<k<<endl;
//	cout<<"The new prev_sum is "<<(((prev_sum * 10)%41 + k) % 41)<<endl;
	return return_digit(l+1, ai, k, n, c, (((prev_sum * 10)%41 + k) % 41));
}

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a0, a1, c, n;
		cin>>a0>>a1>>c>>n;
		if(n == 0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		else if ( n == 1 )
		{
			if(a0 == 0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
//		cout<<"The function returned "<<return_digit(2, a0, a1, n, c, (((a0*10)%41 + a1)%41))<<endl;
		if(return_digit(2, a0, a1, n, c, (((a0*10)%41 + a1)%41)))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
}