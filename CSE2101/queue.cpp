#include<iostream>
using namespace std;

struct queue{

		struct node{
			node* next;
			node* prev;
			int data;
		};

		node* head=NULL;
		node* tail=NULL;

		void enqueue(int x)
		{
			node* current = new node;
			current->data=x;
			current->next=NULL;
			current->prev=NULL;

			if(head==NULL)
			{
				head=current;
				tail=current;
			}
			else
			{
				current->next=head;
				head->prev=current;
				head=current;
			}
		}

		void dequeue()
		{
			tail=tail->prev;
			tail->next=NULL;
		}

		int peek()
		{
			return tail->data;
		}

		void print()
		{
			cout << "The queue is:" << endl;
			node* temp=head;
			while(temp)
			{
				cout << temp->data << endl;
				temp=temp->next;
			}
			cout << endl;
		}

};



int main()
{
	queue list;
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		list.enqueue(x);
	}
	list.print();
	cout << "the number to pop is " << list.peek() << endl;
	list.dequeue();
	list.print();
	cout << "the number to pop is " << list.peek() << endl;
	list.dequeue();
	list.print();
	cout << "the number to pop is " << list.peek() << endl;
	list.dequeue();
	list.print();
	return 0;
}