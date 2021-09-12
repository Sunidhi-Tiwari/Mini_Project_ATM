/* 
Mini Project - ATM

-> Check Balance
-> Cash Withdrawl
-> User Details
-> Update Mobile Number 

*/


#include<conio.h>
#include<iostream>
#include<string>

using namespace std;

class ATM
{
    private:
    long int account_number;    
    string name;
    int PIN;
    double balance;
    string mobile_number;

    public:
     
    void setData(long int account_number_a, string name_a, int PIN_a, double balance_a, string mobile_number_a )
    {
      account_number = account_number_a;
      name = name_a;
      PIN = PIN_a;
      balance = balance_a;
      mobile_number = mobile_number_a;    
    }
      
    long int GetAccountNumber()
    {
        return account_number;
    }

    string GetName()
    {
        return name;
    }

    int GetPIN()
    {
        return PIN;
    }

    double GetBalance()
    {
        return balance;
    }

    string GetMobileNumber()
    {
        return mobile_number;
    }


void SetMobile(string mob_prev, string mob_new)
{
    
        mobile_number = mob_new;
        cout<< endl << "Successfully updated Mobile Number ";
        getch();
    
}
    
void CashWithDraw(int amount_a)
{
    if (amount_a > 0 && amount_a < balance)
    {
        balance -= amount_a;
        cout << endl << "Please Collect you Cash ";
        cout << endl << "Availble Balace: " << balance;
        getch();
    }

    else 
    {
        cout << endl << "Invalid Input or Insuffcient Balance";
    }
}

};

int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNumber;

    system("cls");

    ATM user1;

    user1.setData(3489756, "John", 1037, 295000.15, "9123457890");

     

 
do 
{
    system("cls");

    cout<< endl << "***** ATM *****" << endl;
    cout << endl << "Enter your account number "; 
    cin >> enterAccountNumber;

    cout<< endl << "Enter PIN ";
    cin>> enterPIN;



if ((enterAccountNumber == user1.GetAccountNumber()) && (enterPIN == user1.GetPIN()))
{
     do
     { 
         int amount = 0;
         string OldMobileNumber, NewMobileNumber;
         
         system("cls");
         cout << endl << "***** ATM *****";
         cout << endl << "1. Check Balance";
         cout << endl << "2. Cash Withdraw";
         cout << endl << "3. Show User Details";
         cout << endl << "4. Update Mobile Number";
         cout << endl << "5. Exit"<< endl;

         cin >> choice;

        switch (choice)
        {
            case 1:
            cout << endl << "Your bank balance is : " << user1.GetBalance();
            getch();
            break;

            case 2:
            cout << endl << "Enter the amount: ";
            cin>> amount;
            user1.CashWithDraw(amount);
            break;

            case 3:
            cout<< endl << "*** User details are :-";
            cout << endl << " Account Number: " << user1.GetAccountNumber();
            cout << endl << " Name: " << user1.GetName();
            cout << endl << " Balance: " << user1.GetBalance();
            cout << endl << " Mobile Number: "<< user1.GetMobileNumber();
            getch();
            break;

            case 4:

            cout << endl << " Enter old mobile number: ";
            cin>> OldMobileNumber;
            if(OldMobileNumber == user1.GetMobileNumber())
            {
            cout << endl << "Enter new mobile number: ";
            cin>> NewMobileNumber;

            user1.SetMobile(OldMobileNumber, NewMobileNumber);
            }
            else 
            {
                cout<< endl << "Old mobile number is incorrect";
            }
            break; 

            case 5:
            exit(0);

            default:
            cout << endl << "Enter correct choice";
         }

          
        
     } while (1);
     
}
}while (1);

return 0;

}