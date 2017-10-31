#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdlib.h>
using namespace std;

void get_min_largest_distance(vector<int>, int, int, int, int *);
int check(vector<int>, int, int);
int main() {

	// Write your code here
  int t;
  int n, c;
  cin>>t>>n>>c;
  int i, k, j, d;
  vector<int> a;
  int temp = -1;
  for(i = 0; i < t; i++)
  {
	a.clear();
    for(j = 0; j < n; j++)
    {
      cin>>k;
      a.push_back(k);
    }
    sort(a.begin(), a.end());
    d = -(*(a.begin())) + *(a.end() - 1);
    get_min_largest_distance(a, 0, d, c, &temp);
    cout<<temp<<endl;
  }
}

void get_min_largest_distance(vector<int> a, int x, int y, int c, int * temp)
{
  int pp;
  cout<<"Checking for distance "<<(x+y)/2<<endl;
  pp = check(a, (x+y)/2, c);
  if(pp == 1)
  {
    cout<<"Positive result"<<endl;
    (*temp) = (x+y)/2;
    cout<<"The value of temp changed to "<<(*temp)<<endl;
  }
  if(x >= y)
    return;
  else
    if(pp == 0)
      get_min_largest_distance(a, x, (x+y)/2 - 1, c, temp);
    else
      get_min_largest_distance(a, (x+y)/2 + 1, y, c, temp);
  return;
}

int check(vector<int> a, int l, int c)
{
  int p = 1;
  int t = a[0];
  int i;
  for(i = 1; i < a.size(); i++)
  {
    if(a[i] - t >= l)
    {
      p++;
      t = a[i];
    }
    if(p == c)
      break;
  }
  if(p < c)
    return 0;
  else
    return 1;
}
