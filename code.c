// LINK LIST DATA STRUCTURE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

class Node
{
private:
  int object;
	Node *nextNode;
public:
	void set(int object) 
	{ 
		this->object = object;
	}
	int get1() 
	{
		return object;
	}
	void setNext(Node *nextNode) 
	{
		this->nextNode = nextNode; 
	}
	Node *getNext() 
	{ 
		return nextNode;
	}
};
class List
{
private:
	int size;
	Node *headNode;								//it refer to address of headnode(class type)
	Node *currentNode;							//it refer to address of current node(class type)
	Node *lastCurrentNode;						//it refer to address of lastcurrent node(class type)
public:
	List()
	{
		headNode = new Node();					//new node is created
		headNode->setNext(NULL);				//sitting the null value in the headnode
		currentNode = NULL;						//sittind the currentnode value null
		size = 0;
	}

void add(int addObject)
{
	Node* newNode = new Node();
	newNode->set(addObject);
	if( currentNode != NULL)
	{
		Node *a;								//to store the address of the new current node
		a=currentNode->getNext();				//to move the current node one step forward
		newNode->setNext(a);					//to store the address of the next node
		currentNode->setNext(newNode);			//sitting the current node to the new node
		lastCurrentNode = currentNode;			//assining the value of the lastcurrent node
		currentNode = newNode;					//assining the current node to the new node
	}
       else
	   {
		   newNode->setNext(NULL);
		   headNode->setNext(newNode);
		   lastCurrentNode=headNode;
		   currentNode=newNode;
       }
       size++;
 }

int length() 
	{
		return size;
	}

void start()								//that ftn move the current pointer to the head node
{
	lastCurrentNode = headNode;				//sit the lastcurrentnode as headnode
	currentNode = headNode;					//set the currentnode as headnode
	cout<<endl;
}

bool next()
{
	if (currentNode == NULL)
		return false;
	lastCurrentNode = currentNode;
	currentNode = currentNode->getNext();
	if (currentNode == NULL || size == 0) 
		return false;
	else
		return true;
	cout<<endl;
}

void remove()
{
	if(currentNode != NULL && currentNode != headNode)
	{
		lastCurrentNode->setNext(currentNode->getNext()); //It set the adress of the lastcurrent node
		delete currentNode;
		currentNode = lastCurrentNode->getNext();
		size--;
	}
	else
		cout<<"can not delete";
	if(size==0)
		cout<<" list Empty";
	cout<<endl;
}

int get()
{ 
	if (currentNode != NULL)
		return currentNode->get1();
	cout<<endl;
}
void search(int a)
{
	int x=0;
	while (next())
		if(a==get())
			x++;
	if(x==0)
		cout<<"Element Didnt found";
	else
		cout<<"Element found in List";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	char aa,n,m,y,b;
	int x,a;
	do
	{
		cout<<"Will you add Element in the list [Y/N]=";
		cin>>n;
		if(n=='y'||n=='Y')
		{
			cout<<endl;
			cout<<"Enter Element:";
			cin>>x;
			list.add(x);
		}
	}
	while (n=='y'||n=='Y');
	cout<<endl;
	list.start();			//bring the current pointer back to the headnode
	while (list.next())
		cout << "List Element: "<< list.get()<<endl;
	cout<<endl;
	cout<<"Size of lst is:"<<list.length()<<endl;
	list.start();			//bring the current pointer back to the headnode
	cout<<endl;
	do
	{
		cout<<"Would you like to move the current pointer [Y/N]=";
		cin>>m;
		if(m=='y'||m=='Y')
		{
			cout<<list.next();
			cout<<endl;
		}
	}
	while(m=='y'||m=='Y');
	cout<<endl;
	do
	{
		cout<<"Would you like to remove the current pointer element from list [Y/N]=";
		cin>>y;
		if(y=='y'||y=='Y')
		{
			list.remove();
			cout<<endl;
		}
	}
	while(y=='y'||y=='Y');
	cout<<endl;
	cout<<endl;
	cout<<"The size of the list is="<<list.length();
	list.start();
	cout<<endl;
	do
	{
		cout<<"Input element you search:";
		cin>>a;
		list.search(a);
		cout<<endl;
		list.start();
		cout<<"Would you like to search another:";
		cin>>aa;
	}
	while(aa=='y'||aa=='Y');
	_getch();
	return 0;
}
