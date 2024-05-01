#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <iostream>
#include <vector>
using namespace std;

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";
    cartItems = {};
}

ShoppingCart::ShoppingCart(string name, string date)
{
    customerName = name;
    currentDate = date;
    cartItems = {};
}

string ShoppingCart::GetCustomerName() const
{
    return customerName;
}

string ShoppingCart::GetDate() const
{
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name)
{
    int index = -1;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if (name == cartItems.at(i).GetName())
        {
            index = i;
        }
    }
    if (index != -1)
    {
        cartItems.erase(cartItems.begin() + index);
    }
    else
    {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    int index = -1;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if (item.GetName() == cartItems.at(i).GetName())
        {
            index = i;
        }
    }
    if (index != -1)
    {
        if ((item.GetDescription() == "none") || (item.GetPrice() == -1) || (item.GetQuantity() == -1))
        {
            cartItems.at(index).SetQuantity(item.GetQuantity());
        }
        else
        {
            cout << "Item has default perameters." << endl;
        }
    }
    else
    {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart()
{
    int totalItems = 0;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        totalItems = totalItems + cartItems.at(i).GetQuantity();
    }
    return totalItems;
}

double ShoppingCart::GetCostOfCart()
{
    int totalCost;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        totalCost = totalCost + (cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice());
    }
    return totalCost;
}

void ShoppingCart::PrintTotal()
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl
        << endl;

    size_t i = 0;
    if (i == cartItems.size())
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else
    {
        for (i = 0; i < cartItems.size(); i++)
        {
            cartItems.at(i).PrintItemCost();
        }
    }

    cout << endl
        << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions()
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl
        << endl;
    cout << "Item Descriptions" << endl;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        cartItems.at(i).PrintItemDescription();
    }
}