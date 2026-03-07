#include<iostream>
using namespace std;
class AVL
{
	struct node
	{
		int data;
		node* left;
		node* right;
		int height;
	}*root;
	public:
		AVL()
		{
			root=NULL;
		}
		int Height(node *p)
		{
			if(p==NULL)
				return -1;
			return p->height;
		}
		int max(int a,int b)
		{
			return(a>b)?a:b;
		}
		int getbalance(node *P)
		{
			if(P==NULL)
				return 0;
			return (Height(P->left)-Height(P->right));
		}
		node* insert(int x,node* T)
		{
			if(T==NULL)
			{
				T=new node;
				T->data=x;
				T->height=0;
				T->left=T->right=NULL;
			}
			else if(x<T->data)
			{
				T->left=insert(x,T->left);
				if(Height(T->left)-Height(T->right>=2)
				{
					if(x<T->left->data)
						T=singlerightrotate(T);
					else
						T=doubleleftrightrotate(T);
				}
			}
			else if(x>T->data)
			{
				T->right=insert(x,T->right);
				if(Height(T->right)-Height(T->left)==2)
				{
					if(x>T->right->data)
						T=singleleftrotate(T);
					else
						T=doublerightleftrotate(T);
				}
			}
			T->height=max(Height(T->left),Height(T->right))+1;
			return T;
		}
		node* singlerightrotate(node* K2)
		{
			node* K1;
			K1=K2->left;
			K2->left=K1->right;
			K1->right=K2;
			K2->height=max(Height(K2->left),Height(K2->right))+1;
			K1->height=max(Height(K1->left),Height(K1->right))+1;
			return K1;
		}
		node* singleleftrotate(node* K1)
		{
			node* K2;
			K2=K1->right;
			K1->right=K2->left;
			K2->left=K1;
			K1->height=max(Height(K1->left),Height(K1->right))+1;
			K2->height=max(Height(K2->left),Height(K2->right))+1;
			return K2;
		}
		node* doubleleftrightrotate(node* K3)
		{
			K3->left=singleleftrotate(K3->left);
			return singlerightrotate(K3);
		}
		node* doublerightleftrotate(node* K1)
		{
			K1->right=singlerightrotate(K1->right);
			return singleleftrotate(K1);
		}
		void insertion(int x)
		{
			root=insert(x,root);
		}
		void inorder(node *T)
		{
			if(T!=NULL)
			{
			inorder(T->left);
			cout<<T->data<<' ';
			inorder(T->right);
			}
		}
		void display()
		{
			cout<<"The inserted elements for AVL tree are"<<endl;
			inorder(root);	
			cout<<endl;
			cout<<"The AVL TREE structure is"<<endl;
			preorder(root);
			cout<<endl;
		}
		node* deletenode(int x,node* T)
		{
			node *temp;
			if(T==NULL)
				cout<<"Element not Found";
			else if(x<T->data)
				T->left=deletenode(x,T->left);
			else if(x>T->data)
				T->right=deletenode(x,T->right);
			else if(T->left!=NULL&&T->right!=NULL)
			{
				temp=findmin(T->right);
				T->data=temp->data;
				T->right=deletenode(T->data,T->right);
			}
			else
			{
				temp=T;
				if(T->left==NULL)
					T=T->right;
				else if(T->right==NULL)
					T=T->left;
				delete(temp);
			}
			return T;
			if(T!=NULL)
			{
				int balance=getbalance(T);
				if(balance>1&&getbalance(T->left)>=0)
					T=singlerightrotate(T);
				else if(balance>1&&getbalance(T->left)<0)
					T=doubleleftrightrotate(T);
				else if(balance<-1&&getbalance(T->right)>0)
					T=doublerightleftrotate(T);
				else if(balance<-1&&getbalance(T->right)<=0)
					T=singleleftrotate(T);
				T->height=1+max(Height(T->left),Height(T->right));
			}
			return T;
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
		void deleting()
		{
			int x;
			cout<<"Enter the element to delete:";
			cin>>x;
			deletenode(x,root);
			display();
		}
		void preorder(node* T)
		{
			if(T!=NULL)
			{
				cout<<T->data<<"\t";
				preorder(T->left);
				preorder(T->right);
			}
		}
};
int main()
{
	AVL ob;
	ob.insertion(3);
	ob.insertion(2);
	ob.insertion(1);
	ob.insertion(4);
	ob.insertion(5);
	ob.insertion(6);
	ob.insertion(7);
	ob.insertion(16);
	ob.insertion(15);
	ob.insertion(14);
	ob.insertion(13);
	ob.display();
	ob.deleting();
	ob.deleting();
	ob.deleting();
	return 0;
}
