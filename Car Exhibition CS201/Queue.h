#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Car
{
	string name;
	string model;
	string plateNumber;
};

class queue {
public:
	queue();
	queue(string name1, string model1, string plateNumber1); 
	queue(string name1, string model1, string plateNumber1, string status1);
	void AddCar(queue *currNode);
	void AddVIPCar(queue *currNode);
	void carToAuction();
	void CancelCar(queue* headNode, queue* currNode);
	void ListCurrentCars();

	string GetName() {
		return name;
	}
	string GetPlateNum() {
		return plateNumber;
	}
	string GetModel() {
		return model;
	}

	string GetStatus() { 
		return status;
	}
	int GetCount() {
		return count;
	}
	queue* GetNext() {
		return this->next;
	}
private:
	string name;
	string model;
	string plateNumber;
	string status;
	int count;

	queue* next;
};

//Constructor
queue::queue() {
	name = "";
	model = "";
	plateNumber = "";
	status = "";
	next = NULL;
	count = 0;
}
//Constructor
queue::queue(string name1, string model1, string plateNumber1) {
	name = name1;
	model = model1;
	plateNumber = plateNumber1;
	count = 1;
	next = NULL;
}
//Constructor
queue::queue(string name1, string model1, string plateNumber1, string status1) {
	name = name1;
	model = model1;
	plateNumber = plateNumber1;
	status = status1;
	next = NULL;
	count = 1;

}
//Adds all cars to the back (end) of linked list
void queue::AddCar(queue* currNode) {
	queue* temp = new queue;

	temp->name = currNode->name;
	temp->model = currNode->model;
	temp->plateNumber = currNode->plateNumber;
	temp->status = currNode->status;

	temp->next = NULL;
	temp = this->next;
	this->next = currNode;
	currNode->next = temp;
	count++;
}
//Specifically adds VIP cars to front of list
void queue::AddVIPCar(queue* currNode) {
	queue* temp = NULL;

	temp = this->next;
	this->next = currNode;
	currNode->next = temp;
	count++;
}
//Goes through. If finds car, removes it but if it reaches end of list (NULL) then prints out "Car Does Not Exist"
void queue::CancelCar(queue* headNode, queue* currNode) {
	queue* temp = headNode;
	queue* current = headNode->next;
	while (current != NULL) {
		if (current->name == currNode->name) {
			break;
		}
		else {
			temp = current;
			current = current->next;
		}
	}
	if (current == NULL) {
		cout << "\nCar Does Not Exist.\n";
	}
	else {
		temp->next = current->next;
		delete current;
		count--;
		cout << "\nCar Removed\n";
	}
}
//Updates count whne car has been sent to auction
void queue::carToAuction() {
	count--;
}
//Prints out Cars information
void queue::ListCurrentCars() {
	cout << "Name: " << this->name << endl;
	cout << "Model: " << this->model << endl;
	cout << "Plate Number: " << this->plateNumber << endl;
	cout << "Status: " << this->status << endl;
	cout << endl;
}



