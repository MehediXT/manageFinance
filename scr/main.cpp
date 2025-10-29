#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ------------------------------
// Transaction Class
// ------------------------------
class Transaction {
public:
    string type;      // Income or Expense
    double amount;
    string category;
    string note;

    void inputTransaction() {
        cout << "\n----- Add New Transaction -----\n";
        cout << "Type (Income / Expense): ";
        cin >> type;
        cout << "Amount: ";
        cin >> amount;
        cout << "Category: ";
        cin >> category;
        cin.ignore();
        cout << "Note: ";
        getline(cin, note);

        // TODO: Add input validation (no negative amount, no empty type/category)
        // TODO: Add date & time field for each transaction
    }

    void displayTransaction(int index) const {
        cout << index + 1 << ". " << type
             << " | Amount: " << amount
             << " | Category: " << category
             << " | Note: " << note << "\n";

        // TODO: Display date/time once added
        // TODO: Add color formatting for better readability
    }
};

// ------------------------------
// Finance Manager Class
// ------------------------------
class FinanceManager {
private:
    vector<Transaction> transactions;

public:
    void addTransaction() {
        Transaction t;
        t.inputTransaction();
        transactions.push_back(t);
        cout << "Transaction added successfully!\n";

        // TODO: Save the new transaction to a file (for data persistence)
    }

    void showTransactions() {
        if (transactions.empty()) {
            cout << "\nNo transactions yet.\n";
            // TODO: Suggest user to add a new transaction
            return;
        }

        cout << "\n----- Transaction History -----\n";
        for (int i = 0; i < transactions.size(); i++) {
            transactions[i].displayTransaction(i);
        }

        // TODO: Add sorting or filtering by type, category, or date
        // TODO: Add search feature (search by keyword or category)
    }

    void showBalance() {
        double income = 0, expense = 0;
        for (auto &t : transactions) {
            if (t.type == "Income" || t.type == "income")
                income += t.amount;
            else if (t.type == "Expense" || t.type == "expense")
                expense += t.amount;
        }

        double balance = income - expense;

        cout << "\n----- Balance Summary -----\n";
        cout << "Total Income : " << income << endl;
        cout << "Total Expense: " << expense << endl;
        cout << "Current Balance: " << balance << endl;

        // TODO: Add percentage breakdown (e.g., expenses as % of income)
        // TODO: Add budget warning (if expenses > certain limit)
    }

    // Future planned updates
    // -----------------------
    // TODO: Implement editTransaction() to modify existing records
    // TODO: Implement deleteTransaction() to remove a record
    // TODO: Implement saveToFile() and loadFromFile() functions
    // TODO: Add login system with username and password
};

// ------------------------------
// Main Program
// ------------------------------
int main() {
    FinanceManager manager;
    int choice;

    cout << "Welcome to Personal Finance Manager!\n";

    while (true) {
        cout << "\n==============================\n";
        cout << "     Personal Finance App     \n";
        cout << "==============================\n";
        cout << "1. Add Transaction\n";
        cout << "2. View All Transactions\n";
        cout << "3. View Balance\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            manager.addTransaction();
        }
        else if (choice == 2) {
            manager.showTransactions();
        }
        else if (choice == 3) {
            manager.showBalance();
        }
        else if (choice == 4) {
            cout << "\nThank you for using the app. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }

        // TODO: Add option to save data after every operation
        // TODO: Clear screen or pause for better user experience
    }

    // TODO: Auto-save all transactions before exit
    // TODO: Add loading previous data on startup
    return 0;
}