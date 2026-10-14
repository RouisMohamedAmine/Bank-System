#pragma once
#include<iostream>
#include<string>
#include "clsDate.h"
#include <cstdlib>
#include <ctime> 

using namespace std;

class clsUtil
{

public:
    static void Srand()
    {

        srand((unsigned)time(NULL));

    }

  static int RandomNumber(int From, int To)
   { 
       int randNum = rand() % (To - From + 1) + From;
       return randNum; 
   }

  enum enCharType {
      SmallLetter = 1,
      CapitalLetter = 2,
      Digit = 3,
      MixChar = 4
  };

  static enCharType RandomType()
  {
     int Random = RandomNumber(1, 4);
      return (enCharType)Random;

  }

  static char GetRandomCharacter(enCharType CharType)
  {

      switch (CharType)
      {
      case enCharType::SmallLetter:
      {

          return char(RandomNumber(97, 122));
          break;
      }
      case enCharType::CapitalLetter:
      {
          return char(RandomNumber(65, 90));
          break;
      }
      case enCharType::Digit:
      {

          return char(RandomNumber(48, 57));
          break;
      }
      case enCharType::MixChar:
      {
          enCharType randomType = RandomType();
          return  GetRandomCharacter(randomType);
          break;
      }

      }

      return '\0';

  }

 static string GenerateWord(enCharType CharType, short Length)
  {
      string Word; 

      for (int i = 1; i <= Length; i++)
      {
          Word = Word + GetRandomCharacter(CharType);
      }
      return Word;
  }

 static string GenerateKey(enCharType CharType,short Length)
 {
     string Key = ""; 

     Key = GenerateWord(CharType, Length) + "-";
     Key = Key + GenerateWord(CharType, Length) + "-";
     Key = Key + GenerateWord(CharType, Length) + "-";
     Key = Key + GenerateWord(CharType, Length);

     return Key;
 }

 static void GenerateKeys(short NumberOfKeys, enCharType CharType,short Length)
 {
     for (int i = 1; i <= NumberOfKeys; i++)
     {
         cout << "Key [" << i << "] : ";
         cout << GenerateKey(CharType,Length) << endl;

     }

 }

 static void Swap(int &a, int &b) 
 {
     int temp = a;
     a = b;
     b = temp;


 }

 static void SwapDouble(double& a, double& b)
 {
     double temp = a;
     a = b;
     b = temp;


 }

 static void SwapString(string &S1, string &S2)
 {
     string temp = S1;
     S1 = S2;
     S2 = temp;

 }

 static void ShuffleArray(int arr[100], int arrLength)
 {

     for (int i = 0; i < arrLength; i++)
     {
         int index1 = RandomNumber(1, arrLength) - 1;
         int index2 = RandomNumber(1, arrLength) - 1;
         Swap(arr[index1], arr[index2]);
     }

 }


 static void ShuffleArray(string arr[100], int arrLength)
 {

     for (int i = 0; i < arrLength; i++)
     {
         int index1 = RandomNumber(1, arrLength) - 1;
         int index2 = RandomNumber(1, arrLength) - 1;
         SwapString(arr[index1], arr[index2]);
     }

 }

 static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
 {

     for (int i = 0; i < arrLength; i++)
         arr[i] = RandomNumber(From, To);

 }

 static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Length)
 {

     for (int i = 0; i < arrLength; i++)
         arr[i] = GenerateWord(CharType, Length);

 }

 static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType, short Length)
 {

     for (int i = 0; i < arrLength; i++)
         arr[i] = GenerateKey(CharType, Length);

 }

 static string Tabs(short Length) 
 {
     string Tab = "";

     for (int i = 0; i < Length; i++) {
         Tab += " \t";
     }
     return Tab;

 }

static string EncryptText(string Text, short EncryptionKey)
 {
   
     for (int i = 0; i <= Text.length(); i++)
     {
         Text[i] = char((int)Text[i] + EncryptionKey);
     }
     return Text;
 }

 static string DecryptText(string Text, short EncryptionKey)
 {
     for (int i = 0; i <= Text.length(); i++)
     {
         Text[i] = char((int)Text[i] - EncryptionKey);
     }
     return Text; 
 }

 static string NumberToText(int number) {

     if (number == 0) {
         return "";
     }
     if (number >= 1 && number <= 19) {
         string arr[] = { "","One ","Two ","Three ","Four ","Five","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ",
                             "Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen " };
         return arr[number] + "";
     }
     if (number >= 20 && number <= 99) {
         string arr[] = { "","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninty " };
         return arr[number / 10] + NumberToText(number % 10);
     }
     if (number >= 100 && number <= 199) {
         return "One hundred " + NumberToText(number % 100);
     }
     if (number >= 200 && number <= 999) {
         return NumberToText(number / 100) + " Hundreds " + NumberToText(number % 100);
     }
     if (number >= 1000 && number <= 1999) {
         return "One thousend " + NumberToText(number % 1000);
     }
     if (number >= 2000 && number <= 999999) {
         return NumberToText(number / 1000) + " Thousends " + NumberToText(number % 1000);
     }
     if (number >= 2000 && number <= 999999)
     {
         return NumberToText(number / 1000) + " Thousands " +
             NumberToText(number % 1000);
     }
     if (number >= 1000000 && number <= 1999999)
     {
         return " One Million " + NumberToText(number % 1000000);
     }
     if (number >= 2000000 && number <= 999999999)
     {
         return NumberToText(number / 1000000) + " Millions " +
             NumberToText(number % 1000000);
     }
     if (number >= 1000000000 && number <= 1999999999)
     {
         return " One Billion " + NumberToText(number %
             1000000000);
     }
     else
     {
         return NumberToText(number / 1000000000) + " Billions " +
             NumberToText(number % 1000000000);
     }
 }

};

