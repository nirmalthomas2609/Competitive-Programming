#include<iostream>
#include<stdlib.h>
using namespace std;

int z;

int coin_change(int n, int arr[], int k, int prev[][z])
{
	if(n == 0)
		return 1;
	else if (n < 0)
		return 0;
	if(prev[n-1][k-1] > 0)
		return prev[n-1];
	if (k == 0)
		return 0;
	prev[n-1][k-1] = coin_change(n - arr[0], arr, k, prev) + coin_change(n, arr + 1, k - 1, prev);
	return prev[n-1][k-1];
}


int main ()
{
	int n;
	cout<<"Enter the value of currency for which change is required\n";
	cin>>n;
	int k;
	cout<<"Enter the total number of currency notes available\n";
	cin>>k;
	z = k;
	int arr[k];
	cout<<"Enter the currency notes available\n";
	for(int i = 0; i < k; i++)
		cin>>arr[i];
	int temp[n][k];
	for(int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			temp[i][j] = 0;
	cout<<coin_change(n, arr, k, temp);
	cout<<endl;
	return 0;
}