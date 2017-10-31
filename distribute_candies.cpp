#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

void get_max_candies(int [], int, int, int, int, int *);

int check_and_return(int a[], int n, int k, int t)
{
	int p = 0;
	for(int i = 0; i<n; i++)
	{
		p += (a[i]/t);
		if(p >= k)
			return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	for(int r = 0; r<t; r++)
	{
		int n, k, i;
		cin>>n>>k;
		int a[n];
		for(i = 0; i<n; i++)
			cin>>a[i];
		sort(a, a+n, greater<int>());
		int mini = 0;
		get_max_candies(a, n, k, 0, a[0], &mini);
		cout<<mini<<endl;
	}
}

void get_max_candies(int a[], int n, int k, int l, int r, int *m)
{
	int s;
	if(l > r)
		return;
	else
	{
		s = check_and_return(a, n, k, (l+r)/2);
		if(s == 1)
		{
			(*m) = (l+r)/2;
			get_max_candies(a, n, k, ((l+r)/2 + 1), r, m);
		}
		else
			get_max_candies(a, n, k, l, ((l+r)/2 - 1), m);
	}
}