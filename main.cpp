#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Contact structure
struct Contact {
    string name;
    string phone;
    string email;
    string address;
};

// Vector to store all contacts
vector<Contact> contacts;

// Function to display menu
void displayMenu() {
    cout << "\n========== ADDRESS BOOK ==========\n";
    cout << "1. Add Contact\n";
    cout << "2. View All Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. Edit Contact\n";
    cout << "6. Exit\n";
    cout << "==================================\n";
    cout << "Enter choice: ";
}

// Function to add a new contact
void addContact() {
    cout << "\n--- Add New Contact ---\n";
    Contact newContact;
    
    cout << "Enter name: ";
    getline(cin, newContact.name);
    
    if (newContact.name.empty()) {
        cout << "Name cannot be empty!\n";
        return;
    }
    
    cout << "Enter phone: ";
    getline(cin, newContact.phone);
    
    cout << "Enter email: ";
    getline(cin, newContact.email);
    
    cout << "Enter address: ";
    getline(cin, newContact.address);
    
    contacts.push_back(newContact);
    cout << "\n[SUCCESS] Contact added successfully!\n";
}

// Function to display all contacts
void viewAllContacts() {
    if (contacts.empty()) {
        cout << "\nNo contacts found!\n";
        return;
    }
    
    cout << "\n--- All Contacts ---\n";
    cout << string(100, '-') << endl;
    cout << left << setw(20) << "Name" 
         << setw(15) << "Phone" 
         << setw(25) << "Email" 
         << setw(40) << "Address" << endl;
    cout << string(100, '-') << endl;
    
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << left << setw(20) << contacts[i].name
             << setw(15) << contacts[i].phone
             << setw(25) << contacts[i].email
             << setw(40) << contacts[i].address << endl;
    }
    
    cout << string(100, '-') << endl;
    cout << "Total contacts: " << contacts.size() << endl;
}

// Function to search contact by name
void searchContact() {
    if (contacts.empty()) {
        cout << "\nNo contacts to search!\n";
        return;
    }
    
    cout << "\n--- Search Contact ---\n";
    cout << "1. Search by Name\n";
    cout << "2. Search by Phone\n";
    cout << "3. Search by Email\n";
    cout << "Enter choice: ";
    
    string choice;
    getline(cin, choice);
    
    if (choice == "1") {
        cout << "Enter name to search: ";
        string searchName;
        getline(cin, searchName);
        
        bool found = false;
        cout << "\n--- Search Results ---\n";
        cout << string(100, '-') << endl;
        cout << left << setw(20) << "Name" 
             << setw(15) << "Phone" 
             << setw(25) << "Email" 
             << setw(40) << "Address" << endl;
        cout << string(100, '-') << endl;
        
        for (const auto& contact : contacts) {
            // Case-insensitive search
            string contactName = contact.name;
            transform(contactName.begin(), contactName.end(), 
                     contactName.begin(), ::tolower);
            string searchLower = searchName;
            transform(searchLower.begin(), searchLower.end(), 
                     searchLower.begin(), ::tolower);
            
            if (contactName.find(searchLower) != string::npos) {
                cout << left << setw(20) << contact.name
                     << setw(15) << contact.phone
                     << setw(25) << contact.email
                     << setw(40) << contact.address << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No contacts found with that name.\n";
        }
        
    } else if (choice == "2") {
        cout << "Enter phone to search: ";
        string searchPhone;
        getline(cin, searchPhone);
        
        bool found = false;
        cout << "\n--- Search Results ---\n";
        cout << string(100, '-') << endl;
        cout << left << setw(20) << "Name" 
             << setw(15) << "Phone" 
             << setw(25) << "Email" 
             << setw(40) << "Address" << endl;
        cout << string(100, '-') << endl;
        
        for (const auto& contact : contacts) {
            if (contact.phone.find(searchPhone) != string::npos) {
                cout << left << setw(20) << contact.name
                     << setw(15) << contact.phone
                     << setw(25) << contact.email
                     << setw(40) << contact.address << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No contacts found with that phone.\n";
        }
        
    } else if (choice == "3") {
        cout << "Enter email to search: ";
        string searchEmail;
        getline(cin, searchEmail);
        
        bool found = false;
        cout << "\n--- Search Results ---\n";
        cout << string(100, '-') << endl;
        cout << left << setw(20) << "Name" 
             << setw(15) << "Phone" 
             << setw(25) << "Email" 
             << setw(40) << "Address" << endl;
        cout << string(100, '-') << endl;
        
        for (const auto& contact : contacts) {
            if (contact.email.find(searchEmail) != string::npos) {
                cout << left << setw(20) << contact.name
                     << setw(15) << contact.phone
                     << setw(25) << contact.email
                     << setw(40) << contact.address << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No contacts found with that email.\n";
        }
    } else {
        cout << "Invalid choice!\n";
    }
}

// Function to delete contact
void deleteContact() {
    if (contacts.empty()) {
        cout << "\nNo contacts to delete!\n";
        return;
    }
    
    cout << "\n--- Delete Contact ---\n";
    cout << "Enter name of contact to delete: ";
    string deleteName;
    getline(cin, deleteName);
    
    auto it = find_if(contacts.begin(), contacts.end(),
        [&deleteName](const Contact& c) {
            string contactName = c.name;
            transform(contactName.begin(), contactName.end(), 
                     contactName.begin(), ::tolower);
            string searchLower = deleteName;
            transform(searchLower.begin(), searchLower.end(), 
                     searchLower.begin(), ::tolower);
            return contactName == searchLower;
        });
    
    if (it != contacts.end()) {
        cout << "Delete " << it->name << "? (y/n): ";
        string confirm;
        getline(cin, confirm);
        
        if (confirm == "y" || confirm == "Y") {
            contacts.erase(it);
            cout << "[SUCCESS] Contact deleted!\n";
        } else {
            cout << "Deletion cancelled.\n";
        }
    } else {
        cout << "Contact not found!\n";
    }
}

// Function to edit contact
void editContact() {
    if (contacts.empty()) {
        cout << "\nNo contacts to edit!\n";
        return;
    }
    
    cout << "\n--- Edit Contact ---\n";
    cout << "Enter name of contact to edit: ";
    string editName;
    getline(cin, editName);
    
    auto it = find_if(contacts.begin(), contacts.end(),
        [&editName](const Contact& c) {
            string contactName = c.name;
            transform(contactName.begin(), contactName.end(), 
                     contactName.begin(), ::tolower);
            string searchLower = editName;
            transform(searchLower.begin(), searchLower.end(), 
                     searchLower.begin(), ::tolower);
            return contactName == searchLower;
        });
    
    if (it != contacts.end()) {
        cout << "\nCurrent information:\n";
        cout << "Name: " << it->name << endl;
        cout << "Phone: " << it->phone << endl;
        cout << "Email: " << it->email << endl;
        cout << "Address: " << it->address << endl;
        
        cout << "\nEnter new details (press Enter to skip):\n";
        
        cout << "New name: ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) it->name = newName;
        
        cout << "New phone: ";
        string newPhone;
        getline(cin, newPhone);
        if (!newPhone.empty()) it->phone = newPhone;
        
        cout << "New email: ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) it->email = newEmail;
        
        cout << "New address: ";
        string newAddress;
        getline(cin, newAddress);
        if (!newAddress.empty()) it->address = newAddress;
        
        cout << "\n[SUCCESS] Contact updated!\n";
    } else {
        cout << "Contact not found!\n";
    }
}

int main() {
    cout << "\n*** Welcome to Address Book ***\n";
    
    string choice;
    
    while (true) {
        displayMenu();
        getline(cin, choice);
        
        if (choice == "1") {
            addContact();
        } else if (choice == "2") {
            viewAllContacts();
        } else if (choice == "3") {
            searchContact();
        } else if (choice == "4") {
            deleteContact();
        } else if (choice == "5") {
            editContact();
        } else if (choice == "6") {
            cout << "\nThank you for using Address Book!\n";
            cout << "Goodbye!\n\n";
            break;
        } else {
            cout << "[ERROR] Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
