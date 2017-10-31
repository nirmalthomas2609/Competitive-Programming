#include<iostream>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<vector>

using namespace std;

int check_and_return(int []);


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
	int temp[9];
	int k = 0;
	for(int u = 0; u < 2; u++)
	{
		for(int j = 0; j<9; j++)
		{
			k = 0;
			for(int z = 0; z<9; z++)
			{
//              cout<<"j z"<<j<<" "<<z<<endl;
				if(u == 1)
                {
					temp[k++] = board[j][z];
//                  cout<<"Row No "<<j+1<<endl;
                }
                else
                {
					temp[k++] = board[z][j];
//                  cout<<"Col No "<<j+1<<endl;
                }
			}
          	int o = check_and_return(temp);
			if(o == 0)
			  return false;
		}
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			k = 0;
			for(int g = 0; g < 3; g++)
			{
				for(int h = 0; h < 3; h++)
				{
					temp[k++] = board[3*i + g][3*j + h];
				}
			}
          	int o = check_and_return(temp);
			if(o == 0)
		      return false;
		}
	}
	return true;
}

int check_and_return(int a[])
{
	unordered_map<int, int> m;
	for(int i = 0; i < 9;  i++)
	{
		if(a[i]>9 || a[i]<0)
        {
//          cout<<"The element "<<a[i]<<" is not valid\n";
			return 0;
        }
		else if (a[i] != 0)
		{
//          cout<<"The element "<<a[i]<<" is not a zero\n";
			m[a[i]] += 1;
			if(m[a[i]] > 1)
            {
//              cout<<"The element has occured twice\n";
				return 0;
            }
		}
	}
	return 1;
}