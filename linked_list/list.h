#pragma once
#include <iostream>
#include "node.h"
using namespace std;

class List {
	int list_size;
	Node *head_ptr; //Holds newest member
	Node *tail_ptr; //Holds oldest member
	Node *curr;
	public:
	List() {
		list_size = 0;
		head_ptr = NULL;
		tail_ptr = NULL;
		curr = NULL;
	}
	int get_list_size() const { return list_size; }

	//Output the list
	void print_list() {
		if (head_ptr == NULL) {
			cout << "EMPTY LIST\n";
			return;
		}
		Node *temp_ptr = head_ptr;
		int counter = 0;
		while (temp_ptr) { //Same as saying while (temp_ptr != NULL)
			cout << "Node " << counter++ << ": " << temp_ptr->get_data() << endl;
			temp_ptr = temp_ptr->get_next();
		}
	}

	//Write these functions
	int pop();
	void push(int new_data);
	bool search(int test_data);
	bool remove (int old_data);
};
