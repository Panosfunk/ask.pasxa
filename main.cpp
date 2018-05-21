#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <fstream>
#define pow2(n) (1 << (n))
#include "avlTree.h"
#include "avlNode.h"

using namespace std;

int main()
{
	nodeptr root,root1,rootOfNeighbors,min,max;//,flag;
	int value,choice,findele,delele,tbf; // tbf = to be found
	char ch='y';
	avlTree bst;
	avlTree Neighbors;

	//system("clear");
	root = NULL;
	root1=NULL;
	rootOfNeighbors=NULL;
	cout<<"\n\t\t\t\tWELCOME TO AVL TREE"<<endl;
	cout<<"\t\t\t\t:::::::::::::::::::\n"<<endl;

	do
	{
		cout<<"\t\t::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 1 to insert a new node::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 2 to find the minimum value:::::::::::"<<endl;
		cout<<"\t\t::::Enter 3 to find the max value:::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 4 to search a value:::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 5 to delete a value:::::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 6 to display Preorder:::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 7 to display Inorder NEIGHBORS::::::::"<<endl;
		cout<<"\t\t::::Enter 8 to display Postorder::::::::::::::::"<<endl;
		cout<<"\t\t::::Enter 9 to display the height of the tree:::"<<endl;
		cout<<"\t\t::::Enter 0 to exit:::::::::::::::::::::::::::::"<<endl;
		cout<<"\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n"<<endl;

		cout<<"\nEnter the choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\n\t\tADDING NEW NODE"<<endl;
				cout<<"\t\t:::::::::::::\n"<<endl;
				//cout<<"Enter a new value: ";

                bst.passFromFile(root);
                //bst.passToNeighbors(root);
                //cin>>value;
                //bst.insert(value,root);

				cout<<"\nThe new value have been added to your tree successfully\n"<<endl;
				break;
			case 2:
				if (root !=NULL)
				{
					min=bst.findmin(root);
					cout<<"\nThe minimum element in the tree is: "<<min->element<<endl;
				}
				break;
			case 3:
				if (root !=NULL)
				{
					max=bst.findmax(root);
					cout<<"\nThe maximum element in the tree is: "<<max->element<<endl;
				}
				break;
			case 4:
				cout<<"\nEnter node to search: ";
				cin>>findele;
				if (root != NULL)
				{
					bst.find(findele,root);
					//cout <<  bst.find(findele, root)->element;
				}
				break;
			case 5:
				cout<<"\nEnter node to delete: ";
				cin>>delele;
				bst.del(delele,root);
				bst.inorder(root);
				cout<<endl;
				break;
			case 6:
				cout<<"\n\t\tPRE-ORDER TRAVERSAL"<<endl;
				bst.preorder(root);
				cout<<endl;
				break;
			case 7:
				cout<<"\n\t\tIN-ORDER TRAVERSAL"<<endl;
				cout << "Which node's Neighbors do u want to see?" << endl;
				cin>>tbf; //tbf = To Be Found
				//node *nodeWhomstNeighborsToShow = bst.find(tbf,root);
				//PREPEI KAPOY NA ALLAKSW TO rootOfNeighbors
				cout << "Node:" << tbf << "\t" "Neighbors: " << endl;
				//bst.inorder(root);
				bst.inorder(bst.find(tbf, root)->nero);
				cout << endl;
				break;
			case 8:
				cout<<"\n\t\tPOST ORDER TRAVERSAL"<<endl;
				bst.postorder(root);
				cout<<endl;
				break;
			case 9:
				//cout<<"\n\t\tHEIGHT\n"<<endl;
				cout<<"The height of the tree is: "<<bst.bsheight(root)<<endl;
				break;
			case 0:
				cout<<"\n\tThank your for using AVL tree program\n"<<endl;
				break;
			default:
				cout<<"Sorry! wrong input\n"<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(choice != 0);
	return 0;
}
