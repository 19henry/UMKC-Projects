//Henry Madriles
//Professor May Zein el din
//Computer Science 201R
//December 11, 2020

/*Mercedes Car Exhibition: Program will print 
menu screen for user to choose option from and 
either add cars to linked list, add vip cars to 
front of list, send cars to auction, or remove 
cars. USer can also print out queue (which 
prints in order from top (front of queue) to
back. The queue will print name, model and 
plate number as well as if it is either a 
normal car or VIP.*/

#include <iostream>
#include<string>
#include "Queue.h"

using namespace std;

int main()
{
	string carName;
	string carModel;
	string carPlateNumber;

	int count = 0;

	queue carList;

	queue* headNode;
	queue* currNode;
	queue* lastNode;

	headNode = new queue();
	lastNode = headNode;

	Car carInfo;

	int choice = -1;

	while (choice != 4)
	{
		int choice2 = -1;
		cout << "Welcome to Mercedes\n";
		cout << "1. New Cars\n";
		cout << "2. Old and historical cars\n";
		cout << "3. Luxury Cars\n";
		cout << "4. Exit\n";

		cout << "Please enter your choice\n";
		cin >> choice;
		if (choice == 4)
		{
			choice = 4;
		}
		else
		{
			while (choice2 != 6)
			{
				switch (choice)
				{
				case 1:
					cout << endl;
					cout << "Welcome to exhibition: New Cars\n";
					cout << "Please enter your choice:\n";
					cout << "1. Add Car\n";
					cout << "2. Add VIP Car\n";
					cout << "3. Take Car to Auction\n";
					cout << "4. Cancel Car\n";
					cout << "5. List all currently queued Cars\n";
					cout << "6. Exit back to main menu\n";
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						cout << endl;
						cout << "Add Car\n";
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, carName);
						carInfo.name = carName;
						cout << "Enter model: ";
						getline(cin, carModel);
						carInfo.model = carModel;
						cout << "Enter plate number: ";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 0)
						{
							cout << endl;
							cout << "\nEnter key pressed. Request cancelled\n";
							choice2 = 6;
						}
						else
						{
							carInfo.plateNumber = carPlateNumber;
							cout << endl;
							cout << "You have entered:\n";
							cout << "Name: " << carInfo.name << endl;
							cout << "Model: " << carInfo.model << endl;
							cout << "Plate Number: " << carInfo.plateNumber << endl;

							currNode = new queue(carInfo.name, carInfo.model, carInfo.plateNumber, "Normal");
							count++;
							lastNode->AddCar(currNode);
							lastNode = currNode;

							cout << "\nPress key to continue\n";
							getline(cin, carPlateNumber);
							if (carPlateNumber.length() == 1)
							{
								choice2 = 6;
							}
						}
						break;
					case 2:
						cout << endl;
						cout << "Add VIP Car\n";
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, carName);
						carInfo.name = carName;
						cout << "Enter model: ";
						getline(cin, carModel);
						carInfo.model = carModel;
						cout << "Enter plate number: ";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 0)
						{
							cout << endl;
							cout << "Enter key pressed. Request cancelled\n";
							choice2 = 6;
						}
						else
						{
							carInfo.plateNumber = carPlateNumber;
							cout << endl;
							cout << "You have entered:\n";
							cout << "Name: " << carInfo.name << endl;
							cout << "Model: " << carInfo.model << endl;
							cout << "Plate Number: " << carInfo.plateNumber << endl;

							currNode = new queue(carInfo.name, carInfo.model, carInfo.plateNumber, "VIP");
							count++;
							if (headNode->GetNext() == NULL)
							{
								lastNode->AddCar(currNode);
								lastNode = currNode;
							}
							else
							{
								queue* temp = headNode;
								while (temp->GetNext()->GetStatus() != "Normal")
								{
									temp = temp->GetNext();
								}
								temp->AddVIPCar(currNode);
							}
							cout << "\nPress key to continue\n";
							getline(cin, carPlateNumber);
							if (carPlateNumber.length() == 1)
							{
								choice2 = 6;
							}
						}
						break;
					case 3:
						cout << "\nCar to auction\n";
						if (headNode->GetNext() != NULL)
						{
							cout << "\n Car sent to auction:\n";
							currNode = headNode->GetNext();
							if (currNode->GetNext() == NULL)
							{
								currNode->ListCurrentCars();
								currNode->carToAuction();
								queue* temp = headNode;
								headNode = headNode->GetNext();
								delete temp;
								headNode = NULL;
								count--;
							}
							else
							{
								currNode->ListCurrentCars();
								currNode->carToAuction();
								queue* temp = headNode;
								headNode = headNode->GetNext();
								delete temp;
								count--;
							}
						}
						else
						{
							cout << "No more cars.\n";
						}

						cin.ignore();
						cout << "Press key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;
					case 4:
						cout << "\nCancel Car\n";
						cin.ignore();
						cout << "Name of car to cancel: ";
						getline(cin, carName);
						cout << "Model: ";
						getline(cin, carModel);
						cout << "PlateNumber: ";
						getline(cin, carPlateNumber);
						
						currNode = new queue(carName, carModel, carPlateNumber);
						currNode->CancelCar(headNode, currNode);
						count += currNode->GetCount();

						cout << "\nPress key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;

					case 5:
						cout << endl << "List all currently queued Cars (First is front of line)\n";
						currNode = headNode;
						if (count == 0) {
							cout << "Currently No Cars\n";
							cout << endl;
						}
						else {
							while (currNode->GetNext() != NULL)
							{
								currNode = currNode->GetNext();
								currNode->ListCurrentCars();
							}
						}

						cin.ignore();
						cout << "Press key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;

					case 6:
						choice = 6;
						break;
					default:
						break;
					}
					cout << endl;
					break;
				case 2:
					cout << endl;
					cout << "Welcome to exhibition: Old and Historical Cars\n";
					cout << "Please enter your choice:\n";
					cout << "1. Add Car\n";
					cout << "2. Add VIP Car\n";
					cout << "3. Take Car to Auction\n";
					cout << "4. Cancel Car\n";
					cout << "5. List all currently queued Cars\n";
					cout << "6. Exit back to main menu\n";
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						cout << endl;
						cout << "Add Car\n";
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, carName);
						carInfo.name = carName;
						cout << "Enter model: ";
						getline(cin, carModel);
						carInfo.model = carModel;
						cout << "Enter plate number: ";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 0)
						{
							cout << endl;
							cout << "\nEnter key pressed. Request cancelled\n";
							choice2 = 6;
						}
						else
						{
							carInfo.plateNumber = carPlateNumber;
							cout << endl;
							cout << "You have entered:\n";
							cout << "Name: " << carInfo.name << endl;
							cout << "Model: " << carInfo.model << endl;
							cout << "Plate Number: " << carInfo.plateNumber << endl;

							currNode = new queue(carInfo.name, carInfo.model, carInfo.plateNumber, "Normal");
							count++;
							lastNode->AddCar(currNode);
							lastNode = currNode;

							cout << "\nPress key to continue\n";
							getline(cin, carPlateNumber);
							if (carPlateNumber.length() == 1)
							{
								choice2 = 6;
							}
						}
						break;
					case 2:
						cout << endl;
						cout << "Add VIP Car\n";
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, carName);
						carInfo.name = carName;
						cout << "Enter model: ";
						getline(cin, carModel);
						carInfo.model = carModel;
						cout << "Enter plate number: ";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 0)
						{
							cout << endl;
							cout << "Enter key pressed. Request cancelled\n";
							choice2 = 6;
						}
						else
						{
							carInfo.plateNumber = carPlateNumber;
							cout << endl;
							cout << "You have entered:\n";
							cout << "Name: " << carInfo.name << endl;
							cout << "Model: " << carInfo.model << endl;
							cout << "Plate Number: " << carInfo.plateNumber << endl;

							currNode = new queue(carInfo.name, carInfo.model, carInfo.plateNumber, "VIP");
							count++;
							if (headNode->GetNext() == NULL)
							{
								lastNode->AddCar(currNode);
								lastNode = currNode;
							}
							else
							{
								queue* temp = headNode;
								while (temp->GetNext()->GetStatus() != "Normal")
								{
									temp = temp->GetNext();
								}
								temp->AddVIPCar(currNode);
							}
							cout << "\nPress key to continue\n";
							getline(cin, carPlateNumber);
							if (carPlateNumber.length() == 1)
							{
								choice2 = 6;
							}
						}
						break;
					case 3:
						cout << "\nCar to auction\n";
						if (headNode->GetNext() != NULL)
						{
							cout << "\n Car sent to auction:\n";
							currNode = headNode->GetNext();
							if (currNode->GetNext() == NULL)
							{
								currNode->ListCurrentCars();
								currNode->carToAuction();
								queue* temp = headNode;
								headNode = headNode->GetNext();
								delete temp;
								headNode = NULL;
								count--;
							}
							else
							{
								currNode->ListCurrentCars();
								currNode->carToAuction();
								queue* temp = headNode;
								headNode = headNode->GetNext();
								delete temp;
								count--;
							}
						}
						else
						{
							cout << "No more cars.\n";
						}

						cin.ignore();
						cout << "Press key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;
					case 4:
						cout << "\nCancel Car\n";
						cin.ignore();
						cout << "Name of car to cancel: ";
						getline(cin, carName);
						cout << "Model: ";
						getline(cin, carModel);
						cout << "PlateNumber: ";
						getline(cin, carPlateNumber);

						currNode = new queue(carName, carModel, carPlateNumber);
						currNode->CancelCar(headNode, currNode);
						count += currNode->GetCount();

						cout << "\nPress key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;

					case 5:
						cout << endl << "List all currently queued Cars (First is front of line)\n";
						currNode = headNode;
						if (count == 0) {
							cout << "Currently No Cars\n";
							cout << endl;
						}
						else {
							while (currNode->GetNext() != NULL)
							{
								currNode = currNode->GetNext();
								currNode->ListCurrentCars();
							}
						}

						cin.ignore();
						cout << "Press key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;

					case 6:
						choice = 6;
						break;
					default:
						break;
					}
					cout << endl;
					break;
				case 3:
					//Here
					cout << endl;
					cout << "Welcome to exhibition: Luxury Cars\n";
					cout << "Please enter your choice:\n";
					cout << "1. Add Car\n";
					cout << "2. Add VIP Car\n";
					cout << "3. Take Car to Auction\n";
					cout << "4. Cancel Car\n";
					cout << "5. List all currently queued Cars\n";
					cout << "6. Exit back to main menu\n";
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						cout << endl;
						cout << "Add Car\n";
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, carName);
						carInfo.name = carName;
						cout << "Enter model: ";
						getline(cin, carModel);
						carInfo.model = carModel;
						cout << "Enter plate number: ";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 0)
						{
							cout << endl;
							cout << "\nEnter key pressed. Request cancelled\n";
							choice2 = 6;
						}
						else
						{
							carInfo.plateNumber = carPlateNumber;
							cout << endl;
							cout << "You have entered:\n";
							cout << "Name: " << carInfo.name << endl;
							cout << "Model: " << carInfo.model << endl;
							cout << "Plate Number: " << carInfo.plateNumber << endl;

							currNode = new queue(carInfo.name, carInfo.model, carInfo.plateNumber, "Normal");
							count++;
							lastNode->AddCar(currNode);
							lastNode = currNode;

							cout << "\nPress key to continue\n";
							getline(cin, carPlateNumber);
							if (carPlateNumber.length() == 1)
							{
								choice2 = 6;
							}
						}
						break;
					case 2:
						cout << endl;
						cout << "Add VIP Car\n";
						cout << "Enter name: ";
						cin.ignore();
						getline(cin, carName);
						carInfo.name = carName;
						cout << "Enter model: ";
						getline(cin, carModel);
						carInfo.model = carModel;
						cout << "Enter plate number: ";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 0)
						{
							cout << endl;
							cout << "Enter key pressed. Request cancelled\n";
							choice2 = 6;
						}
						else
						{
							carInfo.plateNumber = carPlateNumber;
							cout << endl;
							cout << "You have entered:\n";
							cout << "Name: " << carInfo.name << endl;
							cout << "Model: " << carInfo.model << endl;
							cout << "Plate Number: " << carInfo.plateNumber << endl;

							currNode = new queue(carInfo.name, carInfo.model, carInfo.plateNumber, "VIP");
							count++;
							if (headNode->GetNext() == NULL)
							{
								lastNode->AddCar(currNode);
								lastNode = currNode;
							}
							else
							{
								queue* temp = headNode;
								while (temp->GetNext()->GetStatus() != "Normal")
								{
									temp = temp->GetNext();
								}
								temp->AddVIPCar(currNode);
							}
							cout << "\nPress key to continue\n";
							getline(cin, carPlateNumber);
							if (carPlateNumber.length() == 1)
							{
								choice2 = 6;
							}
						}
						break;
					case 3:
						cout << "\nCar to auction\n";
						if (headNode->GetNext() != NULL)
						{
							cout << "\n Car sent to auction:\n";
							currNode = headNode->GetNext();
							if (currNode->GetNext() == NULL)
							{
								currNode->ListCurrentCars();
								currNode->carToAuction();
								queue* temp = headNode;
								headNode = headNode->GetNext();
								delete temp;
								headNode = NULL;
								count--;
							}
							else
							{
								currNode->ListCurrentCars();
								currNode->carToAuction();
								queue* temp = headNode;
								headNode = headNode->GetNext();
								delete temp;
								count--;
							}
						}
						else
						{
							cout << "No more cars.\n";
						}

						cin.ignore();
						cout << "Press key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;
					case 4:
						cout << "\nCancel Car\n";
						cin.ignore();
						cout << "Name of car to cancel: ";
						getline(cin, carName);
						cout << "Model: ";
						getline(cin, carModel);
						cout << "PlateNumber: ";
						getline(cin, carPlateNumber);

						currNode = new queue(carName, carModel, carPlateNumber);
						currNode->CancelCar(headNode, currNode);
						count += currNode->GetCount();

						cout << "\nPress key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;

					case 5:
						cout << endl << "List all currently queued Cars (First is front of line)\n";
						currNode = headNode;
						if (count == 0) {
							cout << "Currently No Cars\n";
							cout << endl;
						}
						else {
							while (currNode->GetNext() != NULL)
							{
								currNode = currNode->GetNext();
								currNode->ListCurrentCars();
							}
						}

						cin.ignore();
						cout << "Press key to continue\n";
						getline(cin, carPlateNumber);
						if (carPlateNumber.length() == 1)
						{
							choice2 = 6;
						}
						break;

					case 6:
						choice = 6;
						break;
					default:
						break;
					}
					cout << endl;
					break;
				default:
					break;
				}
			}
		}
	}
	return 0;
}
