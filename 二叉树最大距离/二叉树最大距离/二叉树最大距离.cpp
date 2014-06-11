#include <iostream>
#include "vld.h"
using namespace std;

struct Node
{
	char val;
	int max_right;
	int max_left;
	Node *right;
	Node *left;
	Node(int ch)
	{
		val = ch;
		max_left = 0;
		max_right = 0;
		right = NULL;
		left = NULL;
	}
};
void bulid(Node **root);
void print_node(Node *root);
void delete_tree(Node *root);
void find_max_distance(Node *root,int &max_distance);
int main()
{
	Node *root = NULL;
	bulid(&root);
	if(root == NULL) cout<<"NULL！"<<endl;
	cout<<"先序遍历！"<<endl;
	print_node(root);
	cout<<"节点最大距离！"<<endl;
	int max_dis = 0;
	find_max_distance(root,max_dis);
	cout<<endl<<max_dis<<endl;

	delete_tree(root);
	return 0;
}

void bulid(Node **root)//构建树，必须用指针的指针！
{
	 char ch;
	 cin>>ch;
	 if (ch == '0')
	 {
		root = NULL;
	 }
	 else
	 {
		*root = new Node(ch);
		bulid(&((*root)->left));
		bulid(&((*root)->right));
	 }
}

void print_node(Node *root)
{ 
	 if(root == NULL) return ;

	cout<<root->val<<" ";
	print_node(root->left);
	print_node(root->right);
 
}


void delete_tree(Node *root)//资源释放
{
	if(root == NULL) return ;

	delete_tree(root->left);
	delete_tree(root->right);
	delete root;

}

void find_max_distance(Node *root,int &max_distance)
{
	if (root == NULL)
	{
		return ;
	}
	
	if (root->left == NULL)
	{
		root->max_left = 0;
	}
	if (root->right == NULL)
	{
		root->max_right = 0;
	}

	if (root->left != NULL)
	{
		find_max_distance(root->left,max_distance);	

		if (root->left->max_left > root->left->max_right)
		{
			root->max_left = root->left->max_left + 1; 
		}
		else
		{
			root->max_left = root->left->max_right + 1;
		}
	}

	if (root->right != NULL)
	{
		find_max_distance(root->right,max_distance);

		if (root->right->max_left > root->right->max_right)
		{
			root->max_right = root->right->max_left + 1; 
		}
		else
		{
			root->max_right = root->right->max_right + 1;
		}
	}
	 
	if (max_distance < root->max_left + root->max_right)
	{
		max_distance = root->max_left + root->max_right;
	}

}