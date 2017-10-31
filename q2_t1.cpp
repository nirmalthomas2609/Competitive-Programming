#include<iostream>
#include<math.h>
#include<utility>

using namespace std;

int main ()
{
	int n;
	cin>>n;
	long long a[n];
	long long p = 1;
	long long max = -1;
	for(int i = 0; i < n; i++)
	{
		p *= a[i];
		cin>>a[i];
		if(a[i] > max)
			max = a[i];
	}
	long long start = 1;
	long long end = max;
	long long ans = -1;
	long long mid;
	while(start <= end)
	{
		mid = (start + end)/2;
		if(pow(mid, n) > p)
		{
			ans = mid;
			end = mid - 1;
		}
		else if (pow(mid, n) <= p)
			start = mid + 1;
	}
	cout<<ans<<endl;
}