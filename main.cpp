#include <iostream>
#include <string>
using namespace std;

void banking_service()
{
       double account_balance = 0.0;
       double withdraw_amount;
       double deposit_amount;

       // options
       char opt;
       char x = 'y';

       while(x){
            cout << "\nSelect banking options below:\n";
            cout << "d -> Deposit Money.\n";
            cout << "w -> Withdraw Money\n";
            cout << "r -> Request Balance\n";
            cout << "q -> Quit\n";
            cout << "   >";
            cin >> opt;

            if(opt == 'w'){
                 cout << "Enter amount to withdraw: $";
                 cin >> withdraw_amount;
                 account_balance -= withdraw_amount;
            }else if(opt == 'd'){
                cout << "Enter amount to deposit: $";
                cin >> deposit_amount;
                account_balance += deposit_amount;
            }else if(opt == 'r'){
                cout << "Your balance is $"<<account_balance;
            }else if(opt == 'q'){
                break;
            }
            else{
                cout<<"Enter valid option(ie.d,w,r,q)";
            }

        }
}


int main()
{
    string user_id;
    string password;
    string id_input;
    string pass_input;
    char option = ' ';
    bool isloggedin = false;
    bool want= true;
    cout << "\nHi! Welcome to the ATM Machine!\n\n";

    while(isloggedin == false && want == true){
        cout << "\nPlease select an option from the menu below\n";
        cout << "l -> Login\n";
        cout << "c -> Create New Account\n";
        cout << "q -> Quit\n  > ";
        cin >> option;

        switch(option){
        case 'c':
            cout << "Please enter your user id: ";
            cin >> user_id;
            cout << "Please enter your password: ";
            cin >> password;

            cout << "Thank You! Your account as been created!\n\n";
            break;

        case 'l':
            if(user_id == "" && password == ""){
                cout << "Opps! Looks like you don't have an account with us. Please select option 'c' to create an account then continue.";
                continue;
            }else{
                cout << "Please enter your user id: ";
                cin >> id_input;
                cout << "Please enter your password: ";
                cin >> pass_input;

                 if(user_id == id_input && password == pass_input){
                    cout << "\nAccess Granted!";
                    isloggedin = true;
                    banking_service();
                }else{
                    cout << "***LOGIN FAILED!***\n\n";
                    continue;
                }
            }

        case 'q':
            cout << "\nThank You for using our services.\n";
            want = false;
            break;
        default:
            cout << "\nPlease enter valid options(eg.l,c,q)\n";

        }

    }

    cout << "Out of loop";

    return 0;
}


