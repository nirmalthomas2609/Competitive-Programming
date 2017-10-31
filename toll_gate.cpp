#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int pay_toll(int m[], int c[], int b[], int n, int l = 0, int toll_paid = 0)
{
	if(l == n)
	{
		return toll_paid;
	}
	int x = pay_toll(m, c, b, n, l+1, toll_paid + c[l]);
	b[2] += m[l];
	int y = pay_toll(m, c, b, n, l+1, toll_paid + (2*c[l]));
	b[2] -= m[l];
	int min_toll = min(x, y);
	if(b[1] + b[2] + b[0] >= m[l])
	{
		int k[3];
		for(int i = 0; i < 3; i++)
			k[i] = b[i];
		int s = m[l];
		int u = 0;
		while(s > 0)
		{
			if(s-b[u] >= 0)
			{
				s -= b[u];
				b[u] = 0; 
			}
			else
			{
				b[u] -= s;
				s = 0; 
			}
			u++;
		}
		for(int i = 0; i <= 1; i++)
			b[i] = b[i+1];
        b[2] = 0;
		int z = pay_toll(m, c, b, n, l+1, toll_paid);
		min_toll = min(min_toll, z);
		for(int i = 0; i < 3; i++)
			b[i] = k[i];
	}
	return min_toll;
}

int main ()
{
	int n;
	cin>>n;
	int m[n], c[n];
	for(int i = 0; i < n; i++)
		cin>>m[i]>>c[i];
	int b[] = {0, 0, 0};
	cout<<pay_toll(m, c, b, n);
}