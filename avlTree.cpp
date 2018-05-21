#include "avlTree.h"
#include<iostream>
#include<cstdio>
#include <fstream>
#include<sstream>
#include<algorithm>

//passing values from file to avl trees
void avlTree::passFromFile(nodeptr &p)
{
    avlTree IDs;
    int value,tfn;
    fstream myFile;
    myFile.open("testtestinput.txt");
    if(myFile){
        while(myFile >> value) {
                IDs.insert(value, p);
                int parent=value;
                myFile>>value;
                IDs.find(parent, p)->Neighbors->insert(value,p->nero);
//                tfn=value; // tfn = To Fill Neighbors
//                myFile>> value;
//                nodeptr a=IDs.find(tfn, p);
//                a->Neighbors->insert(value, p->nr);
        }
        myFile.close();
    }
    else{
        cout << "Unable to open" << endl;
    }
}
//void avlTree::passToNeighbors(nodeptr &p)
//{
//    avlTree a;
//    int value;
//    fstream myFile;
//    myFile.open("testtestinput.txt");
//    if(myFile){
//        while(myFile >> value) {
//                int parent=value;
//                myFile>>value;
//                a.find(parent, p)->nr->Neighbors->insert(value, nr);
////                tfn=value; // tfn = To Fill Neighbors
////                myFile>> value;
////                nodeptr a=IDs.find(tfn, p);
////                a->Neighbors->insert(value, p->nr);
//        }
//        myFile.close();
//    }
//    else{
//        cout << "Unable to open" << endl;
//    }
//}
// Inserting a node
void avlTree::insert(int x,nodeptr &p)
{
	if (p == NULL)
	{
		p = new node;
		//p->pn = new node;
		p->element = x;
		p->left=NULL;
		p->right = NULL;
		p->height=0;
		p->nero = new node;
		if (p==NULL)
		{
			cout<<"Out of Space\n"<<endl;
		}
	}
	else
	{
		if (x<p->element)
		{
			insert(x,p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2)
			{
				if (x < p->left->element)
				{
					p=srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x>p->element)
		{
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2)
			{
				if (x > p->right->element)
				{
					p=srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			cout<<"Element Exists\n"<<endl;
		}
    }
    int m,n,d;
    m=bsheight(p->left);
    n=bsheight(p->right);
    d=max(m,n);
    p->height = d + 1;
}
// Finding the Smallest
nodeptr avlTree::findmin(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->left !=NULL)
		{
			p=p->left;
			//return p;
		}
		return p;
	}
}
// Finding the Largest node
nodeptr avlTree::findmax(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->right !=NULL)
		{
			p=p->right;
			//return p;
		}
		return p;
	}
}
// Finding an element
nodeptr avlTree::find(int x,nodeptr &p)
{
	if (p==NULL)
	{
        cout<<"Sorry! element not found\n"<<endl;
        //cout << "Im retarded" << endl;
        //cout << endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x,p->left);
		}
		else
		{
			if (x>p->element)
			{
				find(x,p->right);
			}
			else
			{
			    return p;
			    cout<<"Element found!\n"<<endl;
			}
		}
	}
}
// Copy a tree
void avlTree::copy(nodeptr &p,nodeptr &p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}
// Make a tree empty
void avlTree::makeempty(nodeptr &p)
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d=p;
		free(d);
		p=NULL;
	}
}
// Copy the nodes
nodeptr avlTree::nodecopy(nodeptr &p)
{
	nodeptr temp;
	if (p==NULL)
	{
		return p;
	}
	else
	{
		temp = new node;
		temp->element = p->element;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}
// Deleting a node
void avlTree::del(int x,nodeptr &p)
{
	nodeptr d;
	if (p==NULL)
	{
		cout<<"Sorry! element not found\n"<<endl;
	}
	else if ( x < p->element)
	{
		del(x,p->left);
	}
	else if (x > p->element)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d=p;
		free(d);
		p=NULL;
		cout<<"Element deleted successfully\n"<<endl;
	}
	else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
		cout<<"Element deleted successfully\n"<<endl;
	}
	else if (p->right == NULL)
	{
		d=p;
		p=p->left;
		free(d);
		cout<<"Element deleted successfully\n"<<endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}
int avlTree::deletemin(nodeptr &p)
{
	int c;
	cout<<"inside deltemin\n"<<endl;
	if (p->left == NULL)
	{
		c=p->element;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}
void avlTree::preorder(nodeptr p)
{
	if (p!=NULL)
	{
		cout<<p->element<<"\t";
		preorder(p->left);
		preorder(p->right);
	}
}
// Inorder Printing
void avlTree::inorder(nodeptr p)
{
	if (p!=NULL)
	{
		inorder(p->left);
		cout<<  p->element <<endl;

		//cout << " Neighbors: " ;
		//inorder(pNeighbors);
		inorder(p->right);
	}
}
//show Neighbors inorder
//void avlTree::inorderNeighbors(nodeptr &p, avlTree a)
//{
//    a.find(tbf, p).Neighbors->inorder(a.find(tbf, p));
//    inorder(a.find(p));
//    cout << " Neighbors: " ;
//}
// PostOrder Printing
void avlTree::postorder(nodeptr p)
{
	if (p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->element<<"\t";
	}
}
int avlTree::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}
int avlTree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}
nodeptr avlTree:: srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left),p1->height) + 1;
	return p2;
}
nodeptr avlTree:: srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(p1->height,bsheight(p2->right)) + 1;
	return p2;
}
nodeptr avlTree:: drl(nodeptr &p1)
{
	p1->left=srr(p1->left);
	return srl(p1);
}
nodeptr avlTree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}
int avlTree::nonodes(nodeptr p)
{
	int count=0;
	if (p!=NULL)
	{
		nonodes(p->left);
		nonodes(p->right);
		count++;
	}
	return count;
}
