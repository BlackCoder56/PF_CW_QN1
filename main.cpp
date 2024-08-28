#include <iostream>
#include <string>
using namespace std;

void banking_service(){
    double account_bal = 0;
    cout << "\nSelect banking service: ";
    cout <<"\n-> Deposit Money";
    cout <<"\n-> Withdraw Money";
    cout <<"\n-> Request Balance";
    cout <<"\n-> Quit";
    cout <<"\n > ";
    cin >> account_bal;
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
        cout << "l-> Login\n";
        cout << "c-> Create New Account\n";
        cout << "q-> Quit\n> ";
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
            cout << "Thank You for using our services.\n";
            want = false;
            break;
        default:
            cout << "Please enter valid options(eg.l,c,q)\n";
        }


    }

    cout << "Out of loop";

    return 0;
}


