#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

class clsDepositeScreen :protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        cout << "Please Enter The Account Number : ";
        string AccountNumber = clsInputValidate::ReadString();

        return AccountNumber;
    }

public:

    static void SchowDepositScreen()
    {

        _DrawScreenHeader("\tDeposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is not Found , Chose another one : ";
            AccountNumber = _ReadAccountNumber();

        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount;
        cout << "Please Enter Your Amount : ";
        Amount = clsInputValidate::ReadDblNumber();

        char Answer;

        cout << "Are You Sure Do You Want to  Performe tis Transactions y/n ? ";
        cin >> Answer;

        if (Answer == 'Y'|| Answer == 'y') 
        {
            Client1.Deposit(Amount);

            cout << "Amount Deposited Succesfully :-)" << endl;
            cout << "The new Balance Is : " << Client1.AccountBalance << endl;

        }

        else 
        {
            cout << "Operation Was Canceled \n";

        }

    }

};

