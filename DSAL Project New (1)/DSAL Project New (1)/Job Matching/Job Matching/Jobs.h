#pragma once

#include <iostream>
#include <cstddef>
#include <string>
#include <vector>

using namespace std;

class Jnode
{
public:
	string jobName;
	Jnode* next;
	vector<string> QualificationsRequired;

	Jnode() {
		jobName = string();
		next = NULL;
	}

	Jnode(string jobname) {
		jobName = jobname;
		next = NULL;

	}
};

class linkedListJobs {

public:
	Jnode* head;
	Jnode* tail;
	int size;
public:
	linkedListJobs() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(string value) {

		Jnode* temp = new Jnode(value);

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

	void insertLast(string value) {
		Jnode* temp = new Jnode(value);

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

	void insertAt(string value, int pos) {
		if (pos<0 || pos>size) {
			cout << "Invalid Index" << endl;
		}
		else if (pos == 0) {
			insertFirst(value);
		}
		else if (pos == size) {
			insertLast(value);
		}
		else {
			Jnode* temp = new Jnode(value);
			Jnode* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
			size++;
		}

	}

	void deleteFirst() {
		Jnode* temp = head;
		if (size == 0) {
			cout << "Empty List" << endl;
		}
		else if (size == 1) {
			delete temp;
			head = NULL;
			tail = NULL;
			size--;
		}
		else {
			head = head->next;
			delete temp;
			size--;
		}

	}

	void deleteLast() {
		if (size == 0) {
			cout << "Empty List" << endl;
		}
		else if (size == 1) {
			Jnode* temp = tail;
			delete temp;
			tail = NULL;
			head = NULL;
			size--;
		}
		else {
			Jnode* temp = tail;
			Jnode* current = head;
			for (int i = 0; i < size - 2; i++) {
				current = current->next;
			}
			tail = current;
			tail->next = NULL;
			delete temp;
			size--;
		}
	}

	void deleteAt(int pos) {
		if (pos < 0 || pos >= size) {
		}
		else if (pos == 0) {
			deleteFirst();
		}
		else if (pos == size - 1) {
			deleteLast();
		}
		else {
			Jnode* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			Jnode* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}

	void search(string value) {
		Jnode* current = head;

		for (int i = 0; i < size; i++) {
			if (current->jobName == value) {
				break;
			}
			current = current->next;
			if (i = size)
			{
				return;
			}
		}

		cout << endl;
	}

	bool searchBool(string value) {
		Jnode* current = head;

		for (int i = 0; i < size; i++) {
			if (current->jobName == value) {
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

	Jnode* returnNode(string value) {
		Jnode* current = head;

		if (searchBool(value)) {
			for (int i = 0; i < size; i++) {
				if (current->jobName == value) {
					return current;
					break;
				}
				current = current->next;
			}
		}
	}

	void print() {
		Jnode* current = head;
		//system("cls");
		//cout << current->value << " ";
		while (current != NULL) {
			cout << current->jobName << endl;
			current = current->next;
		}
	}

	int returnPos(string Qualify)
	{
		if (size == 0) {
			return -1;
		}
		else {
			Jnode* current = head;
			int i = 0;
			for (i = 0; i < size; i++) {
				if (current->jobName == Qualify) {
					return i;
					break;
				}
				current = current->next;
			}

			if (i == size) { 
				return -1;
			}
		}
	}

	void searchString(string q)
	{
		if (head == NULL) {
			return;
		}
		else {
			Jnode* current = head;
			int i = 0;
			for (i = 0; i < size; i++) {
				if (current->jobName == q) {
					break;
				}
				current = current->next;
			}

			if (i == size) {
				return;
			}
		}
	}
};