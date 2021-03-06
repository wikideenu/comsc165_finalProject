// PizzaOrder.cpp : 
// Name: Anu Mahinkanda
// Date: 05/18/2019
// COMSC-165


#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <string>

using namespace std;


// Varible Declarations global contants
const double TAX = 0.0825;
const double BASE_PRICE = 10.0;
const double TOPPINGS_MULTIPLIER = 0.15;


//-----------------------------------------------------------------------
// Toppings available for sale class definitions
// Used in manager menu
//-----------------------------------------------------------------------
struct item_Description {
	string toppingName;
};

struct node_item_list {
	string toppingName;
	node_item_list *next;
};

// Linked list of various toppings
class toppingList {
private:
	node_item_list * head, *tail;

public:
	// Initialize available topping linked list
	toppingList() {
		head = NULL;
		tail = NULL;
	}

	// Add available topping node to linked list
	void Push(string i) {
		node_item_list *tmp = new node_item_list;
		tmp->toppingName = i;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
		}
		cout << i << " added as available topping." << endl;
	}

	// Display available topping linked list items
	void display()
	{
		int counter = 0;
		node_item_list *temp = new node_item_list;
		temp = head;
		cout << endl << "Available toppings" << endl << "_________________________" << endl;
		while (temp != NULL)
		{
			counter++;
			cout << "- " << temp->toppingName << endl;
			temp = temp->next;
		}
	}

	// Find specific topping in linked list
	int findTopping(string del_topping) {
		int counter = 0;
		int returnVal = 0;
		node_item_list *temp = new node_item_list;
		temp = head;
		while ((temp != NULL) && returnVal == 0) {
			if (temp->toppingName == del_topping) {
				returnVal = counter + 1;
			}
			if (temp->next == nullptr){
				if (returnVal == 0) {
					returnVal = -1;
				}				
			}
			else {
				temp = temp->next;
			}
			counter++;
		}
		if (returnVal == -1) { // input validation
			cout << del_topping << " is not an available topping." << endl;
		}
		return returnVal;
	}

	// Delete specific topping for availble topping linked list
	void deletePosition(string name)
	{
		cout << "Name: " << name << endl;
		if (name.length() > 0) {
			int pos = findTopping(name) - 1;
			if (pos >= 0) {
				cout << "pos " << pos << endl;
				node_item_list *current = new node_item_list;
				node_item_list *previous = new node_item_list;
				current = head;
				if (pos == 0) {
					head = head->next;
					delete current;
				}
				else {
					for (int i = 1; i <= pos; i++)
					{
						previous = current;
						current = current->next;
					}
					previous->next = current->next;
				}
			}
		}
	}
};

//--------------------------------------------------------------------
// Customer menu pizza order class definitions
//--------------------------------------------------------------------

//Topping linked list
struct node_topping {
	string toppingName;
	node_topping *next;
};

class Toppings {
private:
	node_topping * head, *tail;

public:
	Toppings() {
		head = NULL;
		tail = NULL;
	}

	void Push(string t) {
		node_topping *tmp = new node_topping;
		tmp->toppingName = t;

		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
		}
		cout << t << " added to pizza." << endl;
	}

	// Display list of toppings per pizza
	void display()
	{
		int counter = 0;
		node_topping *temp = new node_topping;
		temp = head;
		cout << endl << "Added Toppings" << endl << "_________________________" << endl;
		while (temp != NULL)
		{
			counter++;
			cout << "- " << temp->toppingName << endl;
			temp = temp->next;
		}
	}

	// Find specific topping on pizza
	int findTopping(string del_topping) {
		int counter = 0;
		int returnVal = 0;
		node_topping *temp = new node_topping;
		temp = head;
		while ((temp != NULL) && returnVal == 0) {
			if (temp->toppingName == del_topping) {
				returnVal = counter + 1;
			}
			if (temp->next == nullptr) {
				if (returnVal == 0) {
					returnVal = -1;
				}
			}
			else {
				temp = temp->next;
			}
			counter++;
		}
		if (returnVal == -1) { // input validation
			cout << del_topping << " is not an available topping." << endl;
		}
		return returnVal;
	}

	// Delete specific topping on pizza
	void deleteAddedTopping(string name)
	{

		if (name.length() > 0) {
			int pos = findTopping(name) - 1;
			if (pos >= 0) {
				node_topping *current = new node_topping;
				node_topping *previous = new node_topping;
				current = head;
				if (pos == 0) {
					head = head->next;
					delete current;
				}
				else {
					for (int i = 1; i <= pos; i++)
					{
						previous = current;
						current = current->next;
					}
					previous->next = current->next;
				}
			}
		}
	}

	// Return the number of toppings on a pizza
	int toppingCount()
	{
		int counter = 0;
		node_topping *temp = new node_topping;
		temp = head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
};


//--------------------------------------------------------------
// Pizza Linked list class definitions
//--------------------------------------------------------------
struct node_pizza {
	Toppings topping;
	//Size size;
	node_pizza *next;
};

class Pizza {
private:
	// Linked list variables
	node_pizza * head, *tail;
	// Data Members
	int itemNum;


public:
	// Initialize pizza linked list
	Pizza() {
		head = NULL;
		tail = NULL;
	}

	// Add pizza to linked list with set of toppings
	void Push(Toppings t) {//Size s) {
		node_pizza *tmp = new node_pizza;
		tmp->topping = t;

		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
		}

	}

	// Display menu option for pizza toppings
	void DisplayMenu() {
		cout << endl << "What would you like on your pizza?(Enter DONE when you are done adding toppings)" << endl << "_________________________" << endl;
	}

	// Display toppings on a pizza
	void DisplayTopping() {
		int counter = 0;
		node_pizza *temp = new node_pizza;
		temp = head;
		if (temp != NULL) {
			temp->topping.display();
		}
		
	}

	// Edit the toppings on a pizza - add/remove
	void EditTopping(toppingList availableToppings) {
		int editNum;
		node_pizza *temp = new node_pizza;
		temp = head;

		cout << endl << "Would you like to add or remove toppings?" << endl << "1. Add" << endl << "2. Remove" << endl;
		cin >> editNum;
		switch (editNum) {
		case 1: {
			string addTopping = "";
			availableToppings.display();
			cout << endl << "What toppings would you like to add?(Enter DONE when finished)";
			while (addTopping != "DONE") {
				getline(cin, addTopping);
				if (addTopping.length() > 0 && addTopping != "DONE" && addTopping != "done") {
					temp->topping.Push(addTopping);
				}
			}
			break;
		}
		case 2: {
			string delTopping = "";
			while (delTopping != "DONE") {
				cout << endl << "What toppings would you like to delete?(Enter DONE when finished)" << endl;
				getline(cin, delTopping);
				if (delTopping.length() > 0 && delTopping != "DONE" && delTopping != "done") {
					temp->topping.deleteAddedTopping(delTopping);
				}

			}
			temp->topping.display();
			break;
		}
		default:
			cout << "This is not a valid entry." << endl;


		}

	}

	// Return the number of toppings on a pizza
	int getNumTopping() {
		node_pizza *temp = new node_pizza;
		temp = head;
		int returnNumTopping = temp->topping.toppingCount();
		return returnNumTopping;
	}
};


//----------------------------------------------------------------------
// Order linked list
//----------------------------------------------------------------------
struct node_order {
	Pizza pizza;
	node_order *next;
};

class OrderLinkedList {
private:
	// Linked list variables
	node_order * head, *tail;

	// Data Members

	int numToppings = 0;
	double finalPrice = 0;
	int orderChoice;

public:
	// Initialize linked list of ordera
	OrderLinkedList() {
		head = NULL;
		tail = NULL;
	}

	// Return the order choice
	int getOrderChoice() {
		return orderChoice;
	}

	// Add pizza to an order
	void Push(Pizza p) {
		node_order *tmp = new node_order;
		tmp->pizza = p;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
		}
	}

	// Display order menu options - only pizza for now
	void DisplayMenu() {
		int n;
		cout << endl << "What would you like to order?" << endl << "_________________________" << endl;
		cout << "1. Pizza" << endl;
		cout << "2. Exit" << endl;
		cin >> n;
		orderChoice = n;
	}

	// Display the current list of existing pending orders
	int DisplayOrders() {
		int counter = 0;
		int returnVal = 0;
		node_order *temp = new node_order;
		temp = head;
		if (temp == NULL) {
			cout << "There are no orders to display." << endl;
			returnVal = -1;
		}
		else {
			while (temp != NULL) {
				counter++;
				cout << endl << "Order " << counter << ": ";
				temp->pizza.DisplayTopping();
				temp = temp->next;
			}
		}
		return returnVal;

	}

	// Delete a specific order
	void DeleteOrder(int pos) {
		node_order *current = new node_order;
		node_order *previous = new node_order;
		current = head;
		//pos = pos - 1;
		if (pos == 1) {
			head = head->next;
			delete current;
		}
		else {
			for (int i = 2; i <= pos; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
	}

	// Edit a specific order
	void EditOrder(toppingList availableToppings, int pos) {
		node_order *current;
		node_order *previous;
		current = head;
		int counter = 0;
		for (counter = 1; counter <= pos; counter++) {

			if (counter == pos) {
				current->pizza.DisplayTopping();
				current->pizza.EditTopping(availableToppings);
			}

			current = current->next;

		}

	}

	// Get the final price of an order
	double getOrderPrice(int pos) {


		node_order *current;
		current = head;
		int counter = 0;
		for (counter = 1; counter <= pos; counter++) {

			if (counter == pos) {
				current->pizza.DisplayTopping();
				numToppings = current->pizza.getNumTopping();
			}

			current = current->next;

		}

		finalPrice = ((BASE_PRICE * (TOPPINGS_MULTIPLIER * static_cast<double>(numToppings))) + BASE_PRICE)*(1 + TAX);
		return finalPrice;

	}
};



int main()
{
	// Variable declarations
	int loginNum, managerNum, customerNum;
	int exitNum = 0, loginMenuNum = 0;
	toppingList pizzaToppings;
	OrderLinkedList	newOrder;


	//initilize Pizza toppings
	cout << "Initializing toppings menu..." << endl;
	pizzaToppings.Push("mushroom");
	pizzaToppings.Push("chicken");
	pizzaToppings.Push("tomatoes");
	pizzaToppings.Push("pineapple");
	pizzaToppings.Push("sausage");
	pizzaToppings.Push("ham");
	pizzaToppings.Push("olives");
	pizzaToppings.Push("pepperoni");
	pizzaToppings.Push("bell pepper");
	pizzaToppings.Push("onion");


	//Prompt User Input
	while (exitNum != 1)
	{
		// Prompt user to select manager or customer menu
		cout << endl << "Main Menu: Please Select Login Option" << endl << "_________________________" << endl;
		cout << "1. Manager" << endl << "2. Customer" << endl << "3. Exit" << endl;
		cin >> loginNum;
		loginMenuNum = 0;
		if (loginNum == 1) {
			// Prompt user for manager menu
			while (loginMenuNum != 1) {
				cout << endl << "Manager menu: What would you like to do?" << endl << "_________________________" << endl;
				cout << "1. Change Pizza Topping options" << endl
					//<< "2. Change Drink Options" << endl
					//<< "3. Change Salad topping options" << endl
					<< "2. Display Pizza Topping options" << endl
					<< "3. Logout to Main Menu" << endl;
				cin >> managerNum;
				switch (managerNum)
				{
				case 1: // Edit list of available toppings
					pizzaToppings.display();
					cout << endl << "Would you like to delete a topping or add a new one?" << endl << "1. Add new topping" << endl << "2. Delete topping" << endl << "3. Exit" << endl;
					int toppingNum;
					cin >> toppingNum;

					switch (toppingNum) {
					case 1: { // Add a new topping
						string newTopping;
						cout << endl << "Please enter the topping to add(enter NONE to cancel): ";
						getline(cin, newTopping);
						getline(cin, newTopping);
						if (newTopping == "NONE" || newTopping == "none" || newTopping == "None") {
							cout << "Cancelling" << endl << endl;
						}
						else {
							pizzaToppings.Push(newTopping);
						}
						break;
					}
					case 2: { // Delete an existing topping
						string delTopping;
						cout << endl << "Please enter the topping to delete(enter NONE to cancel): ";
						getline(cin, delTopping);
						getline(cin, delTopping);
						if (delTopping == "NONE" || delTopping == "none" || delTopping == "None") {
							cout << "Cancelling" << endl << endl;
						}
						else {
							pizzaToppings.deletePosition(delTopping);
						}
						break;
					}
					case 3: {
						break;
					}
					default: {
						cout << "Not a valid option." << endl;
					}

					break;
					}

				case 2: {
					pizzaToppings.display();
					break;
				}
				case 3: // Exit
					loginMenuNum = 1;
				default: // code to be executed if n doesn't match any cases
					cout << "Not a valid entry." << endl << endl;
				}
			}

		}
		else if (loginNum == 2) {
			// Prompt user input for cutomer menu
			while (loginMenuNum != 1) {
				cout << endl << "Customer menu: What would you like to do?" << endl << "_________________________" << endl;
				cout << "1. Create an Order" << endl
					<< "2. Edit an Order" << endl
					<< "3. Delete an Order" << endl
					<< "4. Purchase an Order" << endl
					<< "5. Logout to Main Menu(CAUTION! Will reset any order)" << endl;
				cin >> customerNum;
				switch (customerNum)
				{
				case 1: { // Create an order

					newOrder.DisplayMenu();
					switch (newOrder.getOrderChoice()) {
					case 1: {
						Pizza p1;
						Toppings t1;
						string topping_temp = "";
						// Display list of available toppings
						pizzaToppings.display();
						// Display pizza calss custom menu
						p1.DisplayMenu();

						// Input toppings until user cancels
						while (topping_temp != "DONE") {
							getline(cin, topping_temp);
							if (topping_temp.length() > 0 && topping_temp != "DONE" && topping_temp != "done") {
								if (pizzaToppings.findTopping(topping_temp) >=0) {
									t1.Push(topping_temp);
								}
							}
						}

						p1.Push(t1);
						newOrder.Push(p1);
						break;
					}
					}

					break;
				}
				case 2: {// Edit an order;
					int editValid = newOrder.DisplayOrders();
					int editOrderNum;
					// prompt user to select which order to edit
					if (editValid != -1) {
						cout << endl << "Which order would you like to edit? ";
						cin >> editOrderNum;
						newOrder.EditOrder(pizzaToppings, editOrderNum);

					}
					break;
				}
				case 3: {// Delete an order
					int delValid = newOrder.DisplayOrders();
					int delOrderNumber;
					// Prompt user to select which order to delete
					if (delValid != -1) {
						cout << endl << "Which order would you like to delete? ";
						cin >> delOrderNumber;
						newOrder.DeleteOrder(delOrderNumber);
					}
					break;
				}
				case 4: { // Purchase order
					int buyValid = newOrder.DisplayOrders();
					int buyOrderNum;
					double orderFinalPrice;

					// Prompt user to select order to purchase
					if (buyValid != -1) {
						cout << endl << "Which order would you like to purchase? ";
						cin >> buyOrderNum;
						orderFinalPrice = newOrder.getOrderPrice(buyOrderNum);

						// Output final price and prompt user to buy or cancel - output relevant result
						cout << endl << "The final price after tax is: " << orderFinalPrice << endl;
						cout << "1. Continue?" << endl << "2. Cancel" << endl;
						int orderConfirmNum = 0;
						while (orderConfirmNum != 1 && orderConfirmNum != 2) {
							cin >> orderConfirmNum;

							if (orderConfirmNum == 1) { // user purchased
								cout << "Congratulations on your order!" << endl << endl;
								newOrder.DeleteOrder(buyOrderNum);
							}
							else if (orderConfirmNum == 2) { // User cancelled
								cout << "Exiting..." << endl << endl;
							}
							else {
								cout << "Not a valid entry." << endl;
							}
						}
					}
					break;
				}
				case 5: // Log out to main menu
					loginMenuNum = 1;
					break;
				default: {// code to be executed if input doesn't match any cases
					cout << "Not a valid entry." << endl << endl;
				}
				}
			}

		}
		else if (loginNum == 3) { // Exit
			exitNum = 1;
		}
		else { // Error checking
			cout << "Not a valid entry." << endl << endl;
		}
	}




	system("pause");
	return 0;
}

