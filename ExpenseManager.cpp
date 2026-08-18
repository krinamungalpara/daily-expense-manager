#include<iostream>
#include<string>
using namespace std;

class ExpenseManager {

private:
    struct Expense {
        string name;
        string category;
        float amount;
    };

    Expense expenses[100];
    int count;
    int maxExpenses;

public:
    // Constructor
    ExpenseManager() {
        count = 0;
        maxExpenses = 100;
        cout << "Expense Manager Started.\n";
    }

    // Destructor
    ~ExpenseManager() {
        cout << "\nExpense Manager Closed.\n";
    }

    void addExpense();
    void viewExpenses();
    void totalExpenses();
    void highestExpense();
    void categoryTotal();
    void deleteExpense();
};


/* Add Expense */
void ExpenseManager::addExpense() {

    if (count >= maxExpenses) {
        cout << "\nStorage full! Cannot add more expenses.\n";
        return;
    }

    cout << "\nEnter Expense Name: ";
    cin >> expenses[count].name;

    cout << "Enter Category: ";
    cin >> expenses[count].category;

    cout << "Enter Amount: ";
    cin >> expenses[count].amount;

    // check if user entered text instead of number
    if (cin.fail()) {
        cout << "\nInvalid amount! Expense not added.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    count++;

    cout << "\nExpense added successfully!\n";
}


/* View Expenses */
void ExpenseManager::viewExpenses() {

    if (count == 0) {
        cout << "\nNo expenses recorded yet.\n";
        return;
    }

    cout << "\n------------- ALL EXPENSES -------------\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". Name: " << expenses[i].name << endl;
        cout << "   Category: " << expenses[i].category << endl;
        cout << "   Amount: Rs " << expenses[i].amount << endl;
        cout << "----------------------------------------\n";
    }
}


/* Total Spending */
void ExpenseManager::totalExpenses() {

    if (count == 0) {
        cout << "\nNo expenses available.\n";
        return;
    }

    float total = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    cout << "\nTotal Spending: Rs " << total << endl;
}


/* Highest Expense */
void ExpenseManager::highestExpense() {

    if (count == 0) {
        cout << "\nNo expenses available.\n";
        return;
    }

    float max = expenses[0].amount;
    int index = 0;

    for (int i = 1; i < count; i++) {
        if (expenses[i].amount > max) {
            max = expenses[i].amount;
            index = i;
        }
    }

    cout << "\nHighest Expense:\n";
    cout << "Name: " << expenses[index].name << endl;
    cout << "Category: " << expenses[index].category << endl;
    cout << "Amount: Rs " << expenses[index].amount << endl;
}


/* Category Total */
void ExpenseManager::categoryTotal() {

    if (count == 0) {
        cout << "\nNo expenses available.\n";
        return;
    }

    string searchCat;
    float total = 0;
    int matches = 0;
    cout << "\nEnter Category: ";
    cin >> searchCat;

    for (int i = 0; i < count; i++) {
        if (expenses[i].category == searchCat) {
            total += expenses[i].amount;
            matches++;
        }
    }

    if (matches > 0) {
        cout << "\nTotal in '" << searchCat << "' = Rs " << total << endl;
    } 
    else {
        cout << "\nNo expenses found in this category.\n";
    }
}


/* Delete Expense */
void ExpenseManager::deleteExpense() {

    if (count == 0) {
        cout << "\nNo expenses to delete.\n";
        return;
    }

    int num;

    cout << "\nEnter expense number to delete: ";
    cin >> num;

    if (num < 1 || num > count) {
        cout << "Invalid expense number.\n";
        return;
    }

    for (int i = num - 1; i < count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    count--;

    cout << "Expense deleted successfully!\n";
}


/* Main Function */
int main() {

    ExpenseManager manager;
    int choice;

    for (int i = 1; i > 0; i++) {

        cout << "\n\n========== DAILY EXPENSE MANAGER ==========\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Total Spending\n";
        cout << "4. Highest Expense\n";
        cout << "5. Category-wise Total\n";
        cout << "6. Delete Expense\n";
        cout << "7. Exit\n";
        cout << "-------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Please enter a number between 1 and 7.\n";
            continue;
        }

        if (choice == 1)
            manager.addExpense();

        else if (choice == 2)
            manager.viewExpenses();

        else if (choice == 3)
            manager.totalExpenses();

        else if (choice == 4)
            manager.highestExpense();

        else if (choice == 5)
            manager.categoryTotal();

        else if (choice == 6)
            manager.deleteExpense();

        else if (choice == 7) {
            cout << "\nThank you for using Expense Manager!\n";
            break;
        }
    }

    return 0;
}
