#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <cstdlib>  // For system()

using namespace std;

// Function to clear the screen
void clearScreen() {
    // Check platform and clear the screen accordingly
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); 
    #endif
}

// Parent class: Customer
class Customer {
protected:
    string name;
    int id;
    string address;

public:
    Customer() : name(""), id(0), address("") {}

    bool login() {
        string storedUsername = "customer";  
        string storedPassword = "rnh245";  

        string username, password;

        cout << "Enter username: ";
        cin >> username;
cout<<"\n"<<endl;
        cout << "              Enter password: ";
        cin >> password;

        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Invalid username or password. Please try again." << endl;
            return false;
        }
    }

    void inputDetails() {
        cin.ignore();
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter customer ID: ";
        cin >> id;

        cin.ignore();
        cout << "Enter customer address: ";
        getline(cin, address);
    }
     void updateDetails(){
	 
       int choice;
        cout << "\nUpdate Customer Details:\n";
        cout << "1. Update Name\n";
        cout << "2. Update ID\n";
        cout << "3. Update Address\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Clear the input buffer
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Name updated successfully!\n";
                break;

            case 2:
                cout << "Enter new ID: ";
                while (!(cin >> id) || id <= 0) {
                    cout << "Invalid ID! Please enter a positive integer: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                cout << "ID updated successfully!\n";
                break;

            case 3:
                cin.ignore();
                cout << "Enter new address: ";
                getline(cin, address);
                cout << "Address updated successfully!\n";
                break;

            default:
                cout << "Invalid choice! Returning to main menu.\n";
        }
    }

    void deleteDetails() {
        name = "";
        id = 0;
        address = "";
        cout << "Customer details have been deleted.\n";
    }


    void displayDetails() const {
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID: " << id << endl;
        cout << "Customer Address: " << address << endl;
    }

    // Getter methods for protected members
    string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }
};

// Parent class: BillCheck
class BillCheck {
protected:
    float amount;
    int unitsConsumed;

public:
    BillCheck() : amount(0), unitsConsumed(0) {}

    virtual void calculateAmount() {
    	retry_calculation:
        cout << "Enter Units Consumed (should be in integer): ";
        cin >> unitsConsumed;

        if (unitsConsumed <= 100) {
            amount = unitsConsumed * 12.21;
        } else if (unitsConsumed <= 200) {
            amount = (100 * 12.21) + ((unitsConsumed - 100) * 14.53);
        } else if (unitsConsumed <= 300) {
            amount = (100 * 12.21) + (100 * 14.53) + ((unitsConsumed - 200) * 31.51);
        } else if (unitsConsumed <= 400) {
            amount = (100 * 12.21) + (100 * 14.53) + (100 * 31.51) + ((unitsConsumed - 300) * 38.41);
        } if(unitsConsumed < 0) {
        	cout<<"Please Enter Positive Integer."<<endl;
        	goto retry_calculation;
        }
        else{
		
            cout << "Error: Too many units consumed! Please check your input.\n";
            goto retry_calculation;
        }
    }

    void displayAmount() const {
        cout << "Bill Amount: Rs. " << amount << endl;
    }

    float getAmount() const {
        return amount;
    }

    int getUnitsConsumed() const {
        return unitsConsumed;
    }
    void DisplaySlabs()const{
    	cout<<" 001-100 Units = Rs 12.21 "<<endl;
    	cout<<" 100-200 Units = Rs 14.53 "<<endl;
		cout<<" 200-300 Units = Rs 31.51 "<<endl;
		cout<<" 300-400 Units = Rs 38.41 "<<endl; 
	}
};

// Derived class: Payment
class Payment : public Customer, public BillCheck {
public:
    void makePayment() {
        cout << "Choose payment method (C for Cash, O for Online): ";
        char choice;
        cin >> choice;

        if (choice == 'C' || choice == 'c') {
            cout << "Pay your bill at the nearest bank.\n";
        } else if (choice == 'O' || choice == 'o') {
            cout << "Your payment method is online! " << endl;
            cout << "Choose your online payment source:" << endl;
            cout << "1: Askari Bank\n2: UBL\n3: HBL\n4: Meezan Bank\n5: JazzCash\n6: EasyPaisa\n";
            int option;
            cin >> option;

            string accountNumber;
            float paymentAmount;

            switch (option) {
                case 1:
                    cout << "You chose Askari Bank.\n";
                    break;
                case 2:
                    cout << "You chose UBL.\n";
                    break;
                case 3:
                    cout << "You chose HBL.\n";
                    break;
                case 4:
                    cout << "You chose Meezan Bank.\n";
                    break;
                case 5:
                    cout << "You chose JazzCash.\n";
                    
                    break;
                case 6:
                    cout << "You chose EasyPaisa.\n";
                    break;
                default:
                    cout << "Invalid payment source selected.\n";
                    return;
            }

            cout << "Enter your Account Number (should contain 14 digits):";
            cin >> accountNumber;
            
            while (accountNumber.length() != 14) {
            cout << "Incorrect account number! The account number must be exactly 14 digits. Please try again: ";
            cin >> accountNumber;
        }
            cout << "Enter amount to transfer: ";
            cin >> paymentAmount;

            if (paymentAmount >= amount) {
                cout << "Payment of Rs. " << paymentAmount << " has been successfully paid via " << accountNumber << "!\n";

                // Save the payment details in the file
                ofstream outFile("bill_history.txt", ios::app);  // Open file in append mode
                if (outFile.is_open()) {
                    outFile << "Customer: " << getName() << " | Units: " << unitsConsumed 
                            << " | Amount: Rs. " << amount << endl;
                    outFile.close();
                } else {
                    cout << "Error opening file to save payment details.\n";
                }

                cout << "---------------Rs" << paymentAmount << "----------------" << endl;
                
cout << "                                              /" << endl;
cout << "                                             /" << endl;
cout << "                                            /" << endl;
cout << "                                           /" << endl;
cout << "                                          /" << endl;
cout << "                                         /" << endl;
cout << "                                        /" << endl;
cout << "                                 \\     /" << endl;
cout << "                                  \\   /" << endl;
cout << "                                   \\ /" << endl;
cout << "                                    v " << endl;

            } else {
                cout << "Payment failed. Insufficient amount entered.\n";
            }
        } else {
            cout << "Invalid payment method selected.\n";
        }
    }

    void displayBillHistory() const {
        ifstream inFile("bill_history.txt");  // Open file for reading

        if (inFile.is_open()) {
            string line;
            cout << "Bill History:\n";
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "No bill history available or file could not be opened.\n";
        }
    }

    void displayAfterDueDateAmount() const {
        cout << "Amount After Due Date (Including Rs. 1000 Fine): Rs. " << (amount + 1000) << endl;
    }
};

// Function to display due date


// Main Function
int main() {
	 cout << "\033[1m";
	
    cout << "\n\t\t\t\t ------------------------------ \t\t\t\t";
    cout << "\n\t\t\t\t | ELECTRICITY BILLING SYSTEM | \t\t\t\t";
    cout << "\n\t\t\t\t ------------------------------ \t\t\t";
    cout << "\n\n"; 
     cout << "\033[1m";
    cout << "                            __          __  _                            " << endl;
    cout<<setw(20) << "                            \\ \\        / / | |                           " << endl;
    cout<<setw(20) << "                             \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___   " << endl;
    cout<<setw(20) << "                              \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\  " << endl;
    cout<<setw(20) << "                               \\  /\\  /  __/ | (_| (_) | | | | | |  __/  " << endl;
    cout<<setw(20) << "                                \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  " << endl;
    cout<<"\n"<<endl;
    
    cout << "\033[1m";

    cout << "\n\n";
    Customer c;
    bool loggedIn = false;

    // Try to log in twice
    for (int attempt = 0; attempt < 2; ++attempt) {
        if (c.login()) {
            loggedIn = true;
            clearScreen(); // Clear screen after successful login
            break; // Exit the loop if login is successful
        }
    }

    if (!loggedIn) {
        cout << "Exiting due to unsuccessful login attempts.\n";
        return 0;
    }

    // Menu for electricity billing system
    Payment p;
    BillCheck b;
    while (true) {
        int option;
        main_menu:
        cout << "\n1. Enter Customer Details\n";
        cout << "2. View Customer Details\n";
        cout << "3. Calculate Bill\n";
        cout << "4. Make Payment\n";
        cout << "5. View Bill History\n";
        cout << "6. Display Bill After Due Date\n";
        cout << "7. Display Slabs\n";
        cout << "8. Updation\n";
        cout << "9. Deletion\n";
        cout << "10. Exit\n";
        cout << "Choose an option: ";
        cin >> option;
         if (cin.fail() || option < 1 || option > 10) {
        cout << "Invalid option! Please try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        goto main_menu;  // Jump back to the menu
    }
        
        clearScreen();

        switch (option) {
            case 1:
                c.inputDetails();
                break;
            case 2:
                c.displayDetails();
                break;
            case 3:
                p.calculateAmount();
                p.displayAmount();
                break;
            case 4:
                p.makePayment();
                break;
            case 5:
                p.displayBillHistory();
                break;
            case 6:
                p.displayAfterDueDateAmount();
                break;
            case 7:
            	 b.DisplaySlabs();
            	
            	break;
            case 8:
                c.updateDetails();
                break;
		    case 9:
                c.deleteDetails();
                break;    
            case 10:
                cout << "Exiting program.\n";
                return 0;
            default:
               cout << "Unexpected error occurred. Returning to the menu.\n";
            goto main_menu;
        }
    }

    return 0;
}

