#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int check_and_return(int a[], int l)
{
  int i;
  for(i = 0; i < l; i++)
  {
    if(a[i] == a[l] || a[i] + (l - i) == a[l] || a[i] - (l - i) == a[l])
      return 0;
  }
  return 1;
}

void display_board(int a[], int n)
{
  int i, j;
  for(i = 0; i<n; i++)
  {
    for(j = 0; j<n; j++)
    {
      if(a[i] - 1 == j)
        cout<<"1 ";
      else 
        cout<<"0 ";
    }
  }
  cout<<endl;
}

void n_queens(int n, int l, int a[])
{
	if(l == 0 && a[l] == n)
		return;
	else
	{
		if(a[l] == n)
		{
			a[l] = 0;
			n_queens(a, l-1, n);
		}
		else
		{
			a[l]++;
			int s = check_and_return(a, l);
			if(s == 1 && l == n-1)
			{
				display_board(a, n);
				n_queens(a, l, n);
			}
			else if (s == 1)
				n_queens(a, l+1, n);
			else if (s == 0)
				n_queens(a, l, n);
		}
	}
}

int main ()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
		a[i] = 0;
	n_queens(a, 0, n);
	return 0;
}