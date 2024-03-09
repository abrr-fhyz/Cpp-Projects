//pop push peek print

#include<iostream>
using namespace std;

struct stack
{
	int num;
	stack* next;
	stack* head=NULL;

	void pop()
	{
		stack* temp=(head->next);
		head=temp;
	}

	void push(int x)
	{
		stack* current=new stack;
		current->num=x;
		current->next=NULL;
		if(head==NULL)
			head=current;
		else
		{
			current->next=head;
			head=current;
		}
	}

	int peek()
	{
		return head->num;
	}

	void print()
	{
		stack* temp=head;
		while(temp!=NULL)
		{
			cout << temp->num << endl;
			temp=temp->next;
		}
	}

};


int main()
{
	stack list;
	int n;
	cin >> n;
	while(n--)
	{
		int x; 
		cin >> x;
		list.push(x);
	}
	cout << "printing" << endl;
	list.print();
	int a=list.peek();

	cout << "PEEK: " << a << endl;
	list.pop();
	a=list.peek();
	cout << "PEEK: " << a << endl;
	cout << "printing" << endl;
	list.print();
	return 0;
}