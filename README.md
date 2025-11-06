A simple, in-memory address book application built in C++. This program allows you to manage contacts (names, phone numbers, emails, and addresses) directly from your console.

🌟 Features
Add Contact: Add a new contact with a name, phone number, email, and address.

View All Contacts: Display a neatly formatted table of all saved contacts.

Search Contact: Find contacts by name, phone number, or email. The name search is case-insensitive.

Delete Contact: Remove a contact from the address book after confirming.

Edit Contact: Modify the details of an existing contact.

Exit: Safely exit the application.

🚀 Getting Started
To get a copy of this project up and running on your local machine, follow these steps.

Prerequisites
A C++ compiler (e.g., g++, clang++, or MSVC)

git (for cloning the repository)

Installation
Clone the Repository: Open your terminal and clone the repository. (You will need to replace YOUR_REPOSITORY_URL with your actual git repo URL after you create it on GitHub/GitLab.)

Bash

git clone YOUR_REPOSITORY_URL
Navigate to the Directory:

Bash

cd <repository-folder-name>
🛠️ Building and Running
Compile the Code: From inside the project directory, use your C++ compiler to build the executable.

Using g++ (common on macOS/Linux):

Bash

g++ main.cpp -o address_book
Using clang++:

Bash

clang++ main.cpp -o address_book
Using MSVC (in a Visual Studio Developer Command Prompt):

Bash

cl main.cpp /Fe:address_book.exe
Run the Application:

On macOS/Linux:

Bash

./address_book
On Windows:

Bash

.\address_book.exe
📋 How to Use
Once the application is running, you will see the main menu.

========== ADDRESS BOOK ==========
1. Add Contact
2. View All Contacts
3. Search Contact
4. Delete Contact
5. Edit Contact
6. Exit
==================================
Enter choice:
Enter a number (1-6) and press Enter to select an option.

Follow the on-screen prompts to manage your contacts.
