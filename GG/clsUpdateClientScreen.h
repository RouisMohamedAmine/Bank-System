#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

class clsUpdateClientScreen :protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {

        cout << "\nEnter FirstName : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

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

public:
    
   static void SchowUpdateClient()
    {

       if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pUpdateClients))
       {
           return;
       }

       _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "Please Enter Your Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is not Found , Chose another one : ";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\nUpdate Client Info :\n";
        cout << "-----------------------------\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {

            cout << "\nClient Updated Successfully :-)\n";
            _PrintClient(Client1);

            break;

        }

        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {

            cout << "\nError Account was not Save because it's Empty\n";
            break;

        }

        }
    }

};

