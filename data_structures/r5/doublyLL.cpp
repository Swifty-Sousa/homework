#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL() {

}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}
void doublyLL::print_list()
{
	Node *temp= head;
	while(temp->next!=nullptr)
	{
		cout<< temp->id<< endl;
		temp= temp->next;
	}
	temp =nullptr;
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}
bool doublyLL::deleteNode(int key)
{
	Node *temp=head;
	bool found = false;
	while(temp->next != nullptr)	
	{
		if(temp->id==key)
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete temp;
		}
		temp=temp->next;
	}
	if(found==false)
	{
		return false;
	}
	return true;
}
bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}
int main(void)
{
	int values[21];
	for(int i=0; i<21;i++)
	{
		if(i%2==0)
		{
			values[i]=999;
		}
		else
		{
			values[i]=i;
		}
	}
	doublyLL self(-1);
	Node temp;
	for(int i=0; i<21;i++)
	{
		self.insertNodeAtEnd(values[i]);
	}
	cout<< "The list is currently:"<< endl;
	cout<< " # "<< endl;
	self.print_list();
	cout<< " #"<< endl;
	self.deleteNode(999);
	cout<<  "Now the list is "<<endl;
	cout<< "#"<< endl;
	self.print_list();

}








