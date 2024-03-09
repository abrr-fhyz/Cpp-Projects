#include<iostream>
using namespace std;

struct list
{
	struct node
	{
		int data;
		node* next;
	};	

	node* head=NULL; 
	node* tail=NULL;

	void insert_L(int x)
	{
		node* current=new node;
		current->data=x;
		current->next=head;

		if(head==NULL)
		{
			head=current;
			tail=current;
		}
		else
		{
			tail->next=current;
			tail=current;
		}
	}

	void print()
	{
		node* temp=head;
		while(temp!=tail)
		{
			cout << temp->data << " " ;
			temp=temp->next;
		}
		cout << tail->data << endl;
	}


	void print_1() //obsolete, will keep going in circles
	{
		node* temp=head;
		while(temp!=NULL)
		{
			cout << temp->data << " " ;
			temp=temp->next;
		}
		cout << endl;
	}
};

int main()
{
	list circular;
	int n;
	cin >> n;
	while(n--)
	{
		int x; 
		cin >> x;
		circular.insert_L(x);
	}
	circular.print();
	return 0;
}