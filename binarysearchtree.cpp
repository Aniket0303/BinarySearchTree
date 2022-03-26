#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Node
{
      public:
               Node* left;
               char data[20];
               Node* right;
      public:
               Node();
               ~Node();
               Node* Create_Node();
};
class BinaryTree : public Node
{
     private:
             Node* root;
     public:
             BinaryTree();
             ~BinaryTree();
             void create();
             void insert(Node *root, Node *p);
             void inorder(Node *root);
             void preorder(Node *root);
             void postorder(Node *root);
             Node* return_root()
             {
                 return root;
             }
};
BinaryTree :: BinaryTree()
{
     root=NULL;
}
BinaryTree :: ~BinaryTree()
{
     delete root;
}
void BinaryTree :: create()
{
     Node *p;
     p=Create_Node();

     if(root==NULL)
     {
         root=p;
     }
     else
     {
         insert(root, p);
     }
}
void BinaryTree :: insert(Node *r, Node *p)
{
     int x = atoi(p->data);
     int y = atoi(r->data);
     if(x<y)
     {
         if(r->left==NULL)
         {
             r->left=p;
         }
         else
         {
             insert(r->left, p);
         }
     }
     else if(x>=y)
     {
         if(r->right==NULL)
         {
             r->right=p;
         }
         else
         {
             insert(r->right, p);
         }
     }

}
void BinaryTree :: inorder(Node *r)
{
     if(r!=NULL)
     {
        inorder(r->left);
        cout<<" "<<r->data;
        inorder(r->right);
     }
}
void BinaryTree :: preorder(Node *r)
{
     if(r!=NULL)
     {
        cout<<" "<<r->data;
        inorder(r->left);
        inorder(r->right);
     }
}
void BinaryTree :: postorder(Node *r)
{
     if(r!=NULL)
     {

        inorder(r->left);
        inorder(r->right);
        cout<<" "<<r->data;
     }
}
Node :: Node()
{
     strcpy(data," ");
     left=NULL;
     right=NULL;
}
Node :: ~Node()
{
     delete left;
     delete right;
}

Node* Node :: Create_Node()
{
     Node* p;
     p=new Node;
     cout<<"\n\t Enter the data: ";
     cin>>p->data;
     p->left=NULL;
     p->right=NULL;
}
int main()
{
     BinaryTree obj;
     Node *r;
     int ch;
     char c;
    do
    {
			cout<<"\n\t Menu";
			cout<<"\n\t 1.Create";
			cout<<"\n\t 2.Display";
			cout<<"\n\t 3.Inorder";
			cout<<"\n\t 4.Preorder";
			cout<<"\n\t 5.Postorder";
			cout<<"\n\t 6.Display All";

			cout<<"\n\t Enter your choice(1-6): ";
			cin>>ch;

			switch(ch)
			{
				case 1:
				       obj.create();
				       break;
				case 2:

				       break;
				case 3:
				       r=obj.return_root();
				       if(r==NULL)
				       {
				           cout<<"\n\t Binary tree is empty";
				       }
				       else
				       {
				           cout<<"\n\t Inorder sequence is: ";
				           obj.inorder(r);
				       }
				       break;
				case 4:
				       r=obj.return_root();
				       if(r==NULL)
				       {
				           cout<<"\n\t Binary tree is empty";
				       }
				       else
				       {
				           cout<<"\n\t preorder sequence is: ";
				           obj.preorder(r);
				       }
				       break;
				case 5:
				       r=obj.return_root();
				       if(r==NULL)
				       {
				           cout<<"\n\t Binary tree is empty";
				       }
				       else
				       {
				           cout<<"\n\t postorder sequence is: ";
				           obj.postorder(r);
				       }
				       break;
				case 6:
				       r=obj.return_root();
				       if(r==NULL)
				       {
				           cout<<"\n\t Binary tree is empty";
				       }
				       else
				       {
				           cout<<"\n\t Inorder sequence is: ";
				           obj.inorder(r);
				           cout<<"\n\t preorder sequence is: ";
				           obj.preorder(r);
				           cout<<"\n\t postorder sequence is: ";
				           obj.postorder(r);
				       }
				       break;
				default:
				         cout<<"\n\t Invalid choice";
			}
			cout<<"\n\t Do you want to continue(y/n): ";
			cin>>c;
	  }while(c=='Y'|| c=='y');
      return 0;
}
