#include<iostream>
#include<stack>
#include<vector>
#include<stdlib.h>
#include<queue>

using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};
struct node *Newnode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
};
void insert(struct node **root,int key)
{
	struct node *temp;
	temp = (*root);
	if(temp == NULL)
	{
		(*root) = Newnode(key);
		return;
	}
	while(1)
	{
//		cout<<"Inside the loop please check\n";
		if(temp->data >= key)
		{
			if(temp->left == NULL)
				break;
			else
				temp = temp->left;
		}
		else
			if (temp->right == NULL)
				break;
			else
				temp = temp->right;
	}
//	cout<<"SEg fault not yet"<<endl;
	if(temp->data >= key)
		temp->left = Newnode(key);
	else
		temp->right = Newnode(key);
	return;

}
void inorder(struct node *root)
{	
	if(root!=NULL)
	{
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
	}
}
void print_level_order(queue<struct node *> s)
{
    struct node *temp;
    queue<struct node *> p;
    if(s.size() == 0)
        return;
    else
    {
        while(!s.empty())
        {
            cout<<(s.front())->data<<" ";
            temp = s.front();
            s.pop();
            if(temp -> left != NULL)
                p.push(temp->left);
            if(temp->right != NULL)
                p.push(temp->right);
        }
        print_level_order(p);
    }
    return;
}
int main()
{
	struct node *l;
	l = NULL;
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	int i,key;
	for(i=0;i<n;++i)
	{
		cout<<"Enter  value:";
		cin>>key;
		insert(&l,key);
	}
	queue <struct node *> s;
	s.push(l);
	cout<<"The size of the stack in this case is "<<s.size()<<endl;
	print_level_order(s);
	return 0;
}