#include<iostream>
using namespace std;

int word_cnt = 1;

struct stack{
	char data;
	stack* next;
	stack* prev;

	stack* head = NULL;
	stack* tail = NULL;

	void push(char x)
	{
		stack* current = new stack;
		current -> data = x;
		current -> next = NULL;
		current -> prev = NULL;

		if(head == NULL){
			head = current;
			tail = current;
		}
		else{
			current -> next = head;
			head -> prev = current;
			head = current;
		}
	}

	void print()
	{
		stack* temp = tail;
		while(temp != NULL){
			cout << temp -> data;
			temp = temp -> prev;
		}
		cout << endl;
	}

	int len()
	{
		stack* temp = head;
		int cnt = 0;
		while(temp != NULL){
			cnt++;
			temp = temp -> next;
		}
		return cnt;
	}
};

void generate_words(stack list, string vocab){
	if(vocab.length() == list.len()){
		cout << word_cnt << ". ";
		list.print();
		word_cnt++;
		return;
	}

	for(int i=0; i<vocab.length(); i++){
		stack new_stack = list;
		new_stack.push(vocab[i]);
		generate_words(new_stack, vocab);
	}
}




int main()
{
	stack list;
	string vocab;
	cout << "Enter the vocabulary: " << endl;
	cin >> vocab;
	generate_words(list, vocab);
	return 0;
}
