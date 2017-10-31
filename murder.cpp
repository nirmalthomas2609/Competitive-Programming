#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

long long merge_sort(int [], int, int);
long long merge(int [], int, int);

int main ()
{
	int t;
	cin>>t;
	for(int r = 0; r<t; r++)
	{
		int n;
		cin>>n;
		int a[n];
		int i;
		for(i = 0; i<n; i++)
			cin>>a[i];
		cout<<merge_sort(a, 0, n-1)<<endl;
	}
}

long long merge_sort(int a[], int x, int y)
{
	if(x<y)
	{
		return merge_sort(a, x, (x+y)/2) + merge_sort(a, (x+y)/2 + 1, y) + merge(a, x, y);
	}
	return 0;
}

long long merge(int a[], int x, int y)
{
	int i = x, j = (x+y)/2 + 1, k = 0;
	int temp[y-x + 1];
	long long sum = 0;
	while(i <= (x+y)/2 && j <= y)
	{
		if(a[i] < a[j])
		{
			sum += (a[i]) * (y - j + 1);
			temp[k++] = a[i++];
		}
		else
			temp[k++] = a[j++];
	}
	while(i <= (x+y)/2)
		temp[k++] = a[i++];
	while(j <= y)
		temp[k++] = a[j++];
	for(i = 0; i < k; i++)
		a[x+i] = temp[i];
	return sum;
}