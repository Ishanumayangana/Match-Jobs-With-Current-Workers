#pragma once

#include <iostream>
#include <cstddef>
#include <string>
#include <vector>

using namespace std;

class node
{
public:
	string name;
	int Age;
	string Hometown;
	node* next;
	vector<string> qualifications;

	node() {
		name = string();
		Age = 0;
		Hometown = string();
		next = NULL;
	}

	node(string applicant, int age, string hometown) {
		name = applicant;
		next = NULL;
		Age = age;
		Hometown = hometown;
	}
};

class linkedList {

private:
	node* head;
	node* tail;
	int size;
public:
	linkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(string name, int age, string hometown) {

		node* temp = new node(name, age, hometown);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}

		size++;
	}

	void insertLast(string value, int age, string hometown) {
		node* temp = new node(value, age, hometown);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		size++;
	}

	void insertAt(string value, int age, string hometown, int pos) {
		if (pos<0 || pos>size) {
			cout << "Invalid Index" << endl;
		}
		else if (pos == 0) {
			insertFirst(value, age, hometown);
		}
		else if (pos == size) {
			insertLast(value, age, hometown);
		}
		else {
			node* temp = new node(value, age, hometown);
			node* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
			size++;
		}

	}

	bool searchBool(string value) {
		node* current = head;

		for (int i = 0; i < size; i++) {
			if (current->name == value) {
				return true;
				break;
			}
			current = current->next;
			if (i == size - 1)
			{
				return false;
			}
		}
		cout << endl;
	}

	node* returnNode(string value) {
		node* current = head;

		if (searchBool(value)) {
			for (int i = 0; i < size; i++) {
				if (current->name == value) {
					return current;
					break;
				}
				current = current->next;
			}
		}
	}

	void print() {
		node* current = head;
		while (current != NULL) {
			cout << "Name : " << current->name << endl;
			cout << "Age  : " << current->Age << endl;
			cout << "Hometown : " << current->Hometown << endl;
			cout << endl;
			cout << "List of qualifications" << endl;
			for (int i = 0; i < current->qualifications.size()-1; i++)
			{
				cout << current->qualifications[i] << " ";
			}
			cout << endl;
			cout << endl;
			current = current->next;
		}
	}

	
};