#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsMainScreen.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"


using namespace std;

class  clsCurrencyExchangeScreen :protected clsScreen
{

private:
    enum enCurrencyMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCalculator = 4, eShowMainMenue = 5,
    };

    static short ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1,5,"Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowCurrenciesListScreen()
    {

       clsCurrenciesListScreen::ShowCurrenciesListScreen();
       
    }

    static void _ShowFindCurrencyScreen()
    {

        clsFindCurrencyScreen::ShowFindCurrencyScreen();
        
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

    }

    static void _ShowCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _ShowMainMenueScreen()
    {
        //Main Menue will be here
    }

    static void _GoBackToCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Currency Menue...";
        system("pause>0");
        ShowCurrencyMenue();

    }

    static void _PerformCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case enCurrencyMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyMenueOptions::eCalculator:
        {
            system("cls");
            _ShowCalculatorScreen();
            _GoBackToCurrencyMenue();
            break;
        }


        case enCurrencyMenueOptions::eShowMainMenue:
        {

        }
        }
    }



public:


    static void ShowCurrencyMenue()
    {
        if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t   Currency Exchange Main Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((enCurrencyMenueOptions)ReadCurrencyMenueOption());
    }

};

