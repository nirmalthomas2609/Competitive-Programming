#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;
int k[100000000];
int l = 2;
int fib(int n, int arr[])
{
	if(arr[n] != 0)
		return arr[n];
	if(n <= 1)
	{
		arr[n] = 1;
		return 1;
	}
	arr[n] = fib(n-1, arr) + fib(n-2, arr) ;
	return arr[n];
}
// For the normal code the height of the recursion tree
// will be n.
//O(2^n) is the time complexity of the code when the 
// fibonacci function is written using the normal 
// recursion method. This happens due to the overlapping
// function calls which happens during the recursive fucntion.
// To solve the problem of overlapping sub problems
// an array is passed along with the function to the fibonacci function
// which then stores the fibonacci results previously computed 
// within the function.

int main ()
{
	int arr[n+1];
	for(int i = 0; i <= n; i++)
		arr[i] = 0;

}