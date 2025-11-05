#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string correctPIN = "1234";
    int maxAttempts = 3;
    int attempts = maxAttempts;
    bool pinCorrect = false;
    double balance = 5250.75;
    int transactionCount = 0;
    
    cout << "\n";
    cout << "========================================" << endl;
    cout << "    BANK ATM PIN VALIDATOR SYSTEM      " << endl;
    cout << "         Welcome to SecureBank         " << endl;
    cout << "========================================" << endl;
    cout << "\n";
    
    // Main authentication loop
    while (attempts > 0 && !pinCorrect) {
        string enteredPIN;
        
        cout << "[Attempt " << (maxAttempts - attempts + 1) << "/" << maxAttempts << "]" << endl;
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPIN;
        cout << "\n";
        
        // Validate PIN length
        if (enteredPIN.length() != 4) {
            cout << "ERROR: PIN must be exactly 4 digits." << endl;
            attempts--;
            if (attempts > 0) {
                cout << "Attempts remaining: " << attempts << "\n" << endl;
            }
            continue;
        }
        
        // Validate all characters are digits
        bool allDigits = true;
        for (int i = 0; i < enteredPIN.length(); i++) {
            if (enteredPIN[i] < '0' || enteredPIN[i] > '9') {
                allDigits = false;
                break;
            }
        }
        
        if (!allDigits) {
            cout << "ERROR: PIN must contain only numeric digits (0-9)." << endl;
            attempts--;
            if (attempts > 0) {
                cout << "Attempts remaining: " << attempts << "\n" << endl;
            }
            continue;
        }
        
        // Check if PIN is correct
        if (enteredPIN == correctPIN) {
            cout << "PIN verified successfully!\n" << endl;
            pinCorrect = true;
            
            // Display welcome message
            cout << "========================================" << endl;
            cout << "         ACCESS GRANTED               " << endl;
            cout << "    Welcome back, Valued Customer!   " << endl;
            cout << "========================================" << endl;
            cout << "\n";
            
            // Display account menu
            bool inMenu = true;
            while (inMenu) {
                cout << "------------- ACCOUNT MENU -------------" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Withdraw Cash" << endl;
                cout << "3. Deposit Cash" << endl;
                cout << "4. View Mini Statement" << endl;
                cout << "5. Exit ATM" << endl;
                cout << "----------------------------------------" << endl;
                cout << "\nSelect an option (1-5): ";
                
                int choice;
                cin >> choice;
                cout << "\n";
                
                if (choice == 1) {
                    cout << "--- ACCOUNT BALANCE ---" << endl;
                    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
                    cout << "----------------------\n" << endl;
                    transactionCount++;
                } 
                else if (choice == 2) {
                    cout << "Enter withdrawal amount: $";
                    double amount;
                    cin >> amount;
                    cout << "\n";
                    
                    if (amount <= 0) {
                        cout << "ERROR: Amount must be greater than 0." << endl;
                        cout << "Transaction cancelled.\n" << endl;
                    }
                    else if (amount > balance) {
                        cout << "ERROR: Insufficient funds." << endl;
                        cout << "Available balance: $" << fixed << setprecision(2) << balance << "\n" << endl;
                    }
                    else {
                        balance -= amount;
                        cout << "--- WITHDRAWAL SUCCESSFUL ---" << endl;
                        cout << "Amount withdrawn: $" << fixed << setprecision(2) << amount << endl;
                        cout << "New balance: $" << fixed << setprecision(2) << balance << endl;
                        cout << "Please take your cash." << endl;
                        cout << "-----------------------------\n" << endl;
                        transactionCount++;
                    }
                } 
                else if (choice == 3) {
                    cout << "Enter deposit amount: $";
                    double amount;
                    cin >> amount;
                    cout << "\n";
                    
                    if (amount <= 0) {
                        cout << "ERROR: Amount must be greater than 0." << endl;
                        cout << "Transaction cancelled.\n" << endl;
                    }
                    else {
                        balance += amount;
                        cout << "--- DEPOSIT SUCCESSFUL ---" << endl;
                        cout << "Amount deposited: $" << fixed << setprecision(2) << amount << endl;
                        cout << "New balance: $" << fixed << setprecision(2) << balance << endl;
                        cout << "---------------------------\n" << endl;
                        transactionCount++;
                    }
                } 
                else if (choice == 4) {
                    cout << "--- MINI STATEMENT ---" << endl;
                    cout << "Account Balance: $" << fixed << setprecision(2) << balance << endl;
                    cout << "Transactions today: " << transactionCount << endl;
                    cout << "Account Status: ACTIVE" << endl;
                    cout << "----------------------\n" << endl;
                }
                else if (choice == 5) {
                    cout << "Thank you for using SecureBank ATM!" << endl;
                    cout << "Total transactions: " << transactionCount << endl;
                    cout << "Transactions completed successfully." << endl;
                    inMenu = false;
                } 
                else {
                    cout << "ERROR: Invalid option. Please select 1-5.\n" << endl;
                }
            }
            
        } else {
            attempts--;
            cout << "ERROR: Incorrect PIN." << endl;
            
            if (attempts > 0) {
                cout << "WARNING: Attempts remaining: " << attempts;
                if (attempts == 1) {
                    cout << " (LAST ATTEMPT)";
                }
                cout << "\n" << endl;
            }
        }
    }
    
    // Handle failed authentication
    if (!pinCorrect) {
        cout << "\n";
        cout << "========================================" << endl;
        cout << "          ACCESS DENIED              " << endl;
        cout << "    Maximum PIN attempts exceeded!  " << endl;
        cout << "   Your card has been temporarily   " << endl;
        cout << "   blocked for security purposes.   " << endl;
        cout << "                                    " << endl;
        cout << "   Please contact customer service: " << endl;
        cout << "   Phone: 1-800-SECURE-BANK         " << endl;
        cout << "========================================" << endl;
        cout << "\n";
    }
    
    // Display session summary
    cout << "========================================" << endl;
    cout << "        SESSION TERMINATED             " << endl;
    cout << "  Thank you for banking with us!      " << endl;
    cout << "========================================" << endl;
    cout << "\n";
    
    return 0;
}