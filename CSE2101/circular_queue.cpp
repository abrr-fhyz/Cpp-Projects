#include<bits/stdc++.h>
using namespace std;

struct CircularQueue{
	int size;
	int elements;
	CircularQueue(int n){
		size  = n;
		elements = 0;
	}
	struct node{
		int val;
		node* next;
		node* prev;
	};
	node* head = NULL;
	node* tail = NULL;
	void queue(int x){
		if(elements < size){
			node* current = new node;
			current->val = x;
			current->next = NULL;
			current->prev = NULL;
			if(!head){
				head = current;
				head->next = tail;
				head->prev = tail;
				tail = current;
				tail->next = head;
				tail->prev = head;
			} else{
				current->next = head;
				current->prev = tail;
				head->prev = current;
				head = current;
			}
			elements++;
		} else{
			cout << "Queue is full" << endl;
		}
	}
	void dequeue(){
		tail = tail->prev;
		tail->next = head;
		elements--;
	}
	void front(){
		cout << head->val << endl;
	}
	void back(){
		cout << tail->val << endl;
	}
	void print(){
		node* temp = head;
		while(temp != tail){
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << temp->val << endl;
	}
};

int main(){
	CircularQueue cq(5);
	cq.queue(23);
	cq.queue(26);
	cq.queue(28);
	cq.queue(19);
	cq.queue(100);
	cq.queue(1);
	cq.print();
	cq.dequeue();
	cq.dequeue();
	cq.print();
	cq.queue(2);
	cq.queue(69);
	cq.front();
	cq.back();
	cq.print();
}