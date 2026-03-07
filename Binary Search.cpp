#include<iostream>
using namespace std;
class tree
{
	struct node
	{
		int data;
		node *left;
		node *right;
	}*root;
	public:
		tree()
		{
			root=NULL;
			}
		node* insert(int x,node *T)
		{
			if(T==NULL)
			{
				T=new node;
				T->data=x;
				T->left=T->right=NULL;
			}
			else if(x<T->data)
				T->left=insert(x,T->left);
			else if(x>T->data)
				T->right=insert(x,T->right);
			return T;
		}
		node* find(int x,node *T)
		{
			if(T==NULL)
				return NULL;
			else if(x<T->data)
				return find(x,T->left);
			else if(x>T->data)
				return find(x,T->right);
			else
				return T;
		}
		node* findmax(node *T)
		{
			if(T!=NULL)
			{
				while(T->right!=NULL)
				T=T->right;
			return T;
			}
		}
		node* findmin(node *T)
		{
			if(T!=NULL)
			{
				while(T->left!=NULL)
				T=T->left;
			return T;
			}
				
		}
		node* deletion(int x,node*T)
		{
			node *temp;
			if(T==NULL)
			{
				cout<<"Element not found";
			}
			else
			{
				if(x<T->data)
				{
					T->left=deletion(x,T->left);
				}
				else if(x>T->data)
				{
					T->right=deletion(x,T->right);
				}
				else if(T->left && T->right)
				{
					temp=findmin(T->right);
					T->data=temp->data;
					T->right=deletion(T->data,T->right);
				}
				else
				{
					temp=T;
					if(T->left==NULL)
					{
						T=T->right;
					}
					else if(T->right==NULL)
					 T=T->left;
  	         		delete temp;
				}
				return T;
			}
		}
		void inorder(node *T)
		{
			if(T!=NULL)
			{
			inorder(T->left);
			cout<<T->data<<" ";
			inorder(T->right);
			}
		}
		void preorder(node *T)
		{
			if(T!=NULL)
			{
				cout<<T->data<<" ";
				preorder(T->left);
				preorder(T->right);
			}
		}
		void postorder(node *T)
		{
			if(T!=NULL)
			{
				postorder(T->left);
				postorder(T->right);
				cout<<T->data<<" ";
			}
		}
		void insertion(int x)
		{
			root=insert(x,root);
		}
		void deletion(int x)
		{
			root=deletion(x,root);
		}		
		void display()
		{
			inorder(root);
			cout<<endl;
			cout<<"After the preorder the TREE is";
			preorder(root);
			cout<<endl;
			cout<<"After the postorder the TREE is";
			postorder(root);
			cout<<endl;
		}
		
		
};
main()
{
	tree ob;
	cout<<"The TREE elements are"<<endl;
	ob.insertion(5);
	ob.insertion(6);
	ob.insertion(9);
	ob.insertion(4);
	ob.display();
	cout<<"After deleting (5) the TREE are"<<endl;
	ob.deletion(5);
	ob.display();
}
