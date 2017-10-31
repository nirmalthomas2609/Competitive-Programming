#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<math.h>

using namespace std;

void print_all_strings(map<int, vector<string> > m, int len, int c_pos, string s = "")
{
//	cout<<"The value of len is "<<len<<endl;
//	cout<<m[c_pos].size()<<" is the size of the vector string at position "<<c_pos<<endl;
	if(c_pos == len)
	{
		cout<<s<<endl;
		return;
	}
	else
	{
		vector<string> temp = m[c_pos];
		if(temp.size() == 0)
		{
//			cout<<"The size of the vector string obtained is 0 for c_pos = "<<c_pos<<endl;
			return;
		}
		else
		{
//			cout<<"The value of c_pos is "<<c_pos<<endl;
			for(int i = 0; i < temp.size(); i++)
			{
//				cout<<"The string which is sent in is "<<temp[i]<<endl;
				print_all_strings(m, len, c_pos + temp[i].length(), s + temp[i] + string(1, ' '));
			}
		}
		return;
	}
}

void display_map(map<int, vector<string> > m)
{
	map<int, vector<string> >::iterator it;
	for(it = m.begin(); it != m.end(); ++it)
	{
		vector<string> temp = it->second;
		cout<<"Displaying all the strings at position "<<it->first<<endl;
		for(int u = 0; u < temp.size(); u++)
		{
			cout<<temp[u]<<" ";
		}
		cout<<endl;
	} 
}

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	vector<string> dict;
	while(n--)
	{
		string element;
		getline(cin, element);
		dict.push_back(element);
	}
	string line;
	getline(cin, line);
	int len = line.length();
	map<int, vector<string> > m;
	for(int i = 0; i < dict.size(); i++)
	{
		int j = 0;
		while(j <= len)
		{
			if(line.find(dict[i], j) == string::npos)
			{
//				if(i == 7)
//					cout<<"The string "<<dict[i]<<" was not found in the line"<<endl;
				break;
			}
			int t = line.find(dict[i], j);
//			if(i == 7)
//				cout<<"The string "<<dict[i]<<" was found at pos "<<t<<" in the line"<<endl;
			j = t+1;
//			if(i == 7)
//				cout<<"The value of j is now "<<j<<endl;
			m[t].push_back(dict[i]);
		}
	}
//	cout<<endl;
//	display_map(m);
//	cout<<m[5].size()<<" is the size of the vector string at position 5"<<endl;
//	cout<<endl;
	print_all_strings(m, len, 0);
	return 0;
}