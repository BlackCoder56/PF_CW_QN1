#include <iostream>
#include <string>

using namespace std;

// Function to handle banking services like deposit, withdrawal, and balance check
void banking_service()
{
    double account_balance = 0.0;  // Variable to store the account balance
    double withdraw_amount;        // Variable to store the withdrawal amount
    double deposit_amount;         // Variable to store the deposit amount

    // Character variables to handle user options and loop control
    char opt;
    char x = 'y';

    // Loop to continuously provide banking options until the user chooses to quit
    while(x)
    {
        // Display the banking options to the user
        cout << "\nSelect banking options below:\n";
        cout << "d -> Deposit Money.\n";
        cout << "w -> Withdraw Money\n";
        cout << "r -> Request Balance\n";
        cout << "q -> Quit\n";
        cout << "   >";
        cin >> opt;  // Take the user's option input

        // Conditional statements to perform actions based on the user's input
        if(opt == 'w')
        {
            // Handle money withdrawal
            cout << "Enter amount to withdraw: $";
            cin >> withdraw_amount;
            account_balance -= withdraw_amount;  // Deduct the withdrawal amount from the balance
        }
        else if(opt == 'd')
        {
            // Handle money deposit
            cout << "Enter amount to deposit: $";
            cin >> deposit_amount;
            account_balance += deposit_amount;  // Add the deposit amount to the balance
        }
        else if(opt == 'r')
        {
            // Display the current account balance
            cout << "Your balance is $" << account_balance;
        }
        else if(opt == 'q')
        {
            // Exit the banking service loop
            break;
        }
        else
        {
            // Handle invalid input
            cout << "Enter valid option (i.e., d, w, r, q)";
        }
    }
}

// Main function to handle the ATM login and account creation process
int main()
{
    // Variables to store user credentials and input
    string user_id;
    string password;
    string id_input;
    string pass_input;

    // Character variable to store user menu option input
    char option = ' ';

    // Boolean variables to track login status and loop control
    bool isloggedin = false;
    bool want = true;

    // Welcome message for the ATM service
    cout << "\nHi! Welcome to the ATM Machine!\n\n";

    // Loop to continuously offer login, account creation, or quit options until successful login or quit
    while(isloggedin == false && want == true)
    {
        // Display the main menu options
        cout << "\nPlease select an option from the menu below\n";
        cout << "l -> Login\n";
        cout << "c -> Create New Account\n";
        cout << "q -> Quit\n  > ";
        cin >> option;  // Take the user's menu option input

        // Switch statement to handle the user's menu option input
        switch(option)
        {
            case 'c':
                // Handle account creation
                cout << "Please enter your user id: ";
                cin >> user_id;
                cout << "Please enter your password: ";
                cin >> password;

                cout << "Thank You! Your account has been created!\n\n";
                break;

            case 'l':
                // Handle login
                if(user_id == "" && password == "")
                {
                    // If no account exists, prompt the user to create one
                    cout << "Oops! Looks like you don't have an account with us. Please select option 'c' to create an account then continue.";
                    continue;
                }
                else
                {
                    // Prompt the user to enter login credentials
                    cout << "Please enter your user id: ";
                    cin >> id_input;
                    cout << "Please enter your password: ";
                    cin >> pass_input;

                    // Check if the entered credentials match the stored credentials
                    if(user_id == id_input && password == pass_input)
                    {
                        cout << "\nAccess Granted!";
                        isloggedin = true;  // Set the login status to true
                        banking_service();  // Call the banking service function
                    }
                    else
                    {
                        // Handle login failure
                        cout << "***LOGIN FAILED!***\n\n";
                        continue;
                    }
                }
                break;

            case 'q':
                // Handle quitting the ATM service
                cout << "\nThank You for using our services.\n";
                want = false;  // Set the loop control to false to exit the loop
                break;

            default:
                // Handle invalid input for the main menu
                cout << "\nPlease enter valid options (e.g., l, c, q)\n";
        }
    }

    cout << "Out of loop";  // Final message after exiting the loop

    return 0;  // Return 0 to indicate successful execution
}
