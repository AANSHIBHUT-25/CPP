#include <iostream>
 #include <string>
 #include <iomanip>
 using namespace std;
 
 const int MAX_ITEMS = 10;  
 struct Item {
     int id;
     string name;
     double price;
     int quantity;
 };
 void displayInventory(Item inventory[], int numItems) {
     cout << left << setw(10) << "Item ID"
          << setw(20) << "Item Name"
          << setw(10) << "Price"
          << setw(10) << "Quantity" << endl; 
     for (int i = 0; i < numItems; ++i) {
         cout << setw(10) << inventory[i].id
              << setw(20) << inventory[i].name
              << setw(10) << fixed << setprecision(2) << inventory[i].price
              << setw(10) << inventory[i].quantity << endl;
     }
     cout << endl;
 }
 void addStock(Item inventory[], int numItems, int itemId, int quantityToAdd) {
     for (int i = 0; i < numItems; ++i) {
         if (inventory[i].id == itemId) {
             inventory[i].quantity += quantityToAdd;
             cout << "Added " << quantityToAdd << " units to item " << inventory[i].name << ".\n";
             return;
         }
     }
     cout << "Item with ID " << itemId << " not found.\n";
 }
 void sellItem(Item inventory[], int numItems, int itemId, int quantityToSell) {
     for (int i = 0; i < numItems; ++i) {
         if (inventory[i].id == itemId) {
             if (inventory[i].quantity >= quantityToSell) {
                 inventory[i].quantity -= quantityToSell;
                 cout << "Sold " << quantityToSell << " units of " << inventory[i].name << ".\n";
                 return;
             } else {
                 cout << "Not enough stock to sell " << quantityToSell << " units of " << inventory[i].name << ". Available stock: " << inventory[i].quantity << endl;
                 return;
             }
         }
     }
     cout << "Item with ID " << itemId << " not found.\n";
 }
 
 int main() {
     Item inventory[MAX_ITEMS] = {
         {1, "Laptop", 799.99, 10},
         {2, "Headphones", 49.99, 30},
         {3, "Keyboard", 29.99, 15},
         {4, "Mouse", 19.99, 25},
         {5, "Monitor", 199.99, 5},
         {6, "Smartphone", 599.99, 8},
         {7, "Charger", 14.99, 50},
         {8, "USB Cable", 9.99, 100},
         {9, "Webcam", 39.99, 20},
         {10, "Speakers", 89.99, 12}
     };
 
     int numItems = 10; 
     cout << "Initial Inventory:\n";
     displayInventory(inventory, numItems);
     addStock(inventory, numItems, 2, 20); 
     sellItem(inventory, numItems, 3, 5);   
     sellItem(inventory, numItems, 5, 6);   
     cout << "\nUpdated Inventory:\n";
     displayInventory(inventory, numItems);
 
     return 0;
 }
