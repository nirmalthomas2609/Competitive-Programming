#include<iostream>
#include<stdlib.h>

using namespace std;
int s = 0;
int r = 0;

void place_the_queens(int, int, int[]);
int check_and_return(int [], int);
void placeNQueens(int);
void print_status(int [], int);
void print_a(int [], int);
int check_a(int [], int);



void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  int a[n];
  int i, j;
  for(j = 2; j<=n; j++)
  {
//    cout<<"Going in for the first thing\n";
    r = 0;
    a[0] = j;
    for(i = 1; i<n; i++)
      a[i] = 0;
    place_the_queens(n, 0, a);
//    cout<<"\n\nReturned after the first thing\n\n";
  }
  /*
  for(j = 1; j<=n; j++)
  {
    for(i = 1; i<n; i++)
      a[i] = 0;
    a[0] = j;
    place_the_queens(n, 0, a);
  }
  */
}

int check_a(int a[], int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    if(a[i] == 0)
      return 1;
  }
  return 0;
}

void print_a(int a[], int n)
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

void print_status(int a[], int n)
{
  int i;
  for(i = 0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void place_the_queens(int n, int l, int a[])
{
  if(l == n)
  {
    s = 1;
    return;
  }
  int m;
  if(l == 0)
  {
    r++;
//    print_status(a, n);
    if(r > 1)
    {
//      cout<<"I am going to return because the count has exceeded\n";
      return;
    }
    if(a[l] == n+1)
      return;
    place_the_queens(n, l+1, a);
    if(s == 1)
    {
//      cout<<"The value of a[0] is "<<a[0]<<" and I am going to print out the matrix rowise"<<endl;
      print_a(a, n);
      s = 0;
    }
    return;
  }
  while(a[l] < n+1)
  {
//    print_status(a, n);
//    cout<<"The value of l is "<<l<<endl;
    a[l]++;
    if(a[l] == n+1)
    {
      a[l] = 0;
      place_the_queens(n, l-1, a);
      return;
    }
    if(check_and_return(a, l) == 0)
    {
      place_the_queens(n, l+1, a);
      return;
    }
  }
}

int check_and_return(int a[], int l)
{
  int i;
  for(i = 0; i < l; i++)
  {
    if(a[i] == a[l] || a[i] + (l - i) == a[l] || a[i] - (l - i) == a[l])
      return 1;
  }
  return 0;
}
