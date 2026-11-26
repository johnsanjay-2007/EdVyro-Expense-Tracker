#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

struct Expense {
    string description;
    string category;
    double amount;
};

vector<Expense> expenses;

// Read and validate a positive amount
double readAmount() {
    string line;
    double amount;

    while (true) {
        cout << "Enter amount: Rs. ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> amount && !(ss >> extra) && amount > 0) {
            return amount;
        }

        cout << "Invalid amount! Please enter a positive number.\n";
    }
}

// Add a new expense
void addExpense() {
    Expense e;

    cout << "\nEnter description: ";
    getline(cin, e.description);

    while (e.description.empty()) {
        cout << "Description cannot be empty. Try again: ";
        getline(cin, e.description);
    }

    cout << "Enter category: ";
    getline(cin, e.category);

    while (e.category.empty()) {
        cout << "Category cannot be empty. Try again: ";
        getline(cin, e.category);
    }

    e.amount = readAmount();

    expenses.push_back(e);
    cout << "\nExpense added successfully!\n";
}

// Display all expenses
void listExpenses() {
    if (expenses.empty()) {
        cout << "\nNo expenses recorded yet.\n";
        return;
    }

    cout << "\n------ EXPENSE LIST ------\n";
    cout << fixed << setprecision(2);

    for (size_t i = 0; i < expenses.size(); i++) {
        cout << i + 1 << ". "
             << expenses[i].description
             << " | " << expenses[i].category
             << " | Rs. " << expenses[i].amount << "\n";
    }
}

// Calculate total for a category
void categoryTotal() {
    string category;
    double total = 0;
    bool found = false;

    cout << "\nEnter category: ";
    getline(cin, category);

    for (const Expense& e : expenses) {
        if (e.category == category) {
            total += e.amount;
            found = true;
        }
    }

    if (found) {
        cout << "Total for " << category
             << ": Rs. " << fixed << setprecision(2)
             << total << "\n";
    } else {
        cout << "No expenses found in this category.\n";
    }
}

// Calculate overall expenses
void overallTotal() {
    double total = 0;

    for (const Expense& e : expenses) {
        total += e.amount;
    }

    cout << "\nOverall Expense: Rs. "
         << fixed << setprecision(2) << total << "\n";
}

// Main menu
int main() {
    string choice;

    while (true) {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. List Expenses\n";
        cout << "3. Category Total\n";
        cout << "4. Overall Total\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        getline(cin, choice);

        if (choice == "1") {
            addExpense();
        } else if (choice == "2") {
            listExpenses();
        } else if (choice == "3") {
            categoryTotal();
        } else if (choice == "4") {
            overallTotal();
        } else if (choice == "5") {
            cout << "Thank you for using Expense Tracker!\n";
            break;
        } else {
            cout << "Invalid choice! Please enter 1 to 5.\n";
        }
    }

    return 0;
}