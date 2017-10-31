#include<stack>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main ()
{
	int n;
	cin>>n;
	int i;
	int a[n], k;
	for(i=0; i<n; i++)
	{
	cin>>k;
	a[i] = k;
	}
	stack<int> s;
	s.push(0);
	int r[n];
	r[0] = 1;
	for(i=1; i<n; i++)
	{
	while((!s.empty()) && (a[s.top()] <= a[i]))
		s.pop();
	r[i] = (s.empty()) ? (i+1):(i-s.top());
	s.push(i); 
	}
	cout<<"Printing span array\n";
	for(i=0; i<n; i++)
	{
	cout<<r[i]<<" "<<"\n";
	}
	return 0;
}