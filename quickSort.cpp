#include<iostream>

using namespace std;

void quickSort(int [], int);
int partition(int[], int, int);
void qs(int [], int, int);

int main ()
{
	int a[6];
	int i;
	int k;
	for(i = 0; i<6; i++)
	{
		cin>>k;
		a[i] = k;
	}
	quickSort(a, 6);
	for(i=0; i<6; i++)
		cout<<a[i]<<" ";
	return 0; 
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
  qs(input, 0, size - 1);
}

void qs(int input[], int a, int b)
{
  if(b <= a)
    return;
  int c = partition(input, a, b);
  cout<<"Partitioned at c = "<<c<<endl;
  qs(input, a, c-1);
  qs(input, c+1, b);
}

int partition(int input[], int a, int b)
{
	cout<<"In Partition with a = "<<a<<" and b = "<<b<<"\n";
  int z, i;
  int pivot = input[a];
  int count = 0;
  for(i = a+1; i<=b; i++)
    if(input[i]<pivot)
      count++;
  z = input[a];
  input[a] = input[a+count];
  input[a+count] = z;
  int j = b;
  i = a;
  while(i < a+count && j > a+count)
  {
    if(input[i] >= pivot && input[j] < pivot)
    {
      z = input[i];
      input[i++] = input[j];
      input[j--] = z;
    }
    else
    {
      if(input[i] < pivot)
        i++;
      if(input[j] >= pivot)
        j--;
    }
  }
}