// Michael Llanes
// Manny Garcia
// git@github.com:MALLANES/LlanesYGarciaLab13.5.git

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu()
{
   /* Type your code here */
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl << endl;
}

void ExecuteMenu(char option, ShoppingCart &theCart)
{
   // Declaring variables necessary for switch statements
   string name, description;
   int price, quantity;
   char temp;

   switch (option)
   {
   case 'a':
   {
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, name);
      cout << "Enter the item description:" << endl;
      getline(cin, description);
      cout << "Enter the item price:" << endl;
      cin >> price;
      cout << "Enter the item quantity:" << endl;
      cin >> quantity;

      ItemToPurchase item(name, description, price, quantity);
      theCart.AddItem(item);
      
      cout << endl;
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> temp;
      cin.ignore();
      ExecuteMenu(temp, theCart);
      
      break;
   }

   case 'd':
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      getline(cin, name);
      theCart.RemoveItem(name);
      
      cout << endl;
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> temp;
      cin.ignore();
      ExecuteMenu(temp, theCart);
      
      break;

   case 'c':
   {
      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, name);
      cout << "Enter the new quantity:" << endl;
      cin >> quantity;
      ItemToPurchase item(name, "none", -1, quantity);
      theCart.ModifyItem(item);
      
      cout << endl;
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> temp;
      cin.ignore();
      ExecuteMenu(temp, theCart);
      
      break;
   }

   case 'i':
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      theCart.PrintDescriptions();
      
      cout << endl;
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> temp;
      cin.ignore();
      ExecuteMenu(temp, theCart);
      
      break;

   case 'o':
      cout << "OUTPUT SHOPPING CART" << endl;
      theCart.PrintTotal();
      
      cout << endl;
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> temp;
      cin.ignore();
      ExecuteMenu(temp, theCart);
      
      break;
   case 'q':
      
      break;
   default:
      cout << "Choose an option:" << endl;
      cin >> temp;
      cin.ignore();
      ExecuteMenu(temp, theCart);
      break;
   }
}

int main()
{
   string name;
   string date;
   char userChoice;

   cout << "Enter customer's name:" << endl;
   getline(cin, name);
   cout << "Enter today's date:" << endl;
   getline(cin, date);
   ShoppingCart cart(name, date);

   cout << endl;
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << date << endl << endl;

   PrintMenu();
   cout << "\nChoose an option:" << endl;
   cin >> userChoice;
   cin.ignore();
   ExecuteMenu(userChoice, cart);

   return 0;
}