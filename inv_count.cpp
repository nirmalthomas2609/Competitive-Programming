#include<iostream>
using namespace std;


long long merge_sort(int[], int, int, int);
long long merge(int [], int, int);
void print_status(int [], int);
long long solve(int [], int);

int main()
{
int a[] = {2,1,5,3,4};
  cout<<solve(a, 5);

}


long long solve(int A[], int n)
{
	long long ans = merge_sort(A, 0, n-1, n);
  print_status(A, n);
  return ans;
}

long long merge_sort(int a[], int x, int y, int n)
{
  if(x<y)
  {
    long long u, v, z;
    u = merge_sort(a, x, (x+y)/2, n); 
    v = merge_sort(a, (((x+y)/2) + 1), y, n); 
    print_status(a, n);
    z = merge(a, x, y);
    print_status(a, n);
    return u+v+z;
  }
  return 0;
}

void print_status(int a[], int n)
{
  int i;
  for( i = 0; i < n ; i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

long long merge(int a[], int x, int y)
{
  int i = x, j = ((x+y)/2) + 1;
  long long count = 0;
  int temp[y-x+1];
  int k = 0;
  while(i<=((x+y)/2) && j<=y)
  {
    if(a[i] <= a[j])
      temp[k++] = a[i++];
    else
    {
      temp[k++] = a[j++];
      count += ((x+y)/2) - i + 1;
    }
  }
  while(i<=((x+y)/2))
    temp[k++] = a[i++];
  while(j<=y)
    temp[k++] = a[j++];
  for(i = 0, j = x; i < k; i++, j++)
  {
    a[j] = temp[i];
  }
  return count;
}