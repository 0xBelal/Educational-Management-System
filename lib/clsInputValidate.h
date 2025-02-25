//
// Created by Belal on 25-Feb-25.
//

#ifndef CLSINPUTVALIDATE_H
#define CLSINPUTVALIDATE_H

#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include <conio.h>
class clsInputValidate
{

public:


	static char ReadYes_Or_No_Q() {
		char ANS;
		cin >> ANS;
		ANS = clsString::UpperLetter(ANS);

		while (true)
		{
			switch (ANS)
			{case 'Y':
				return ANS;
			case 'N':
				return ANS;
			default:
				cout << "Invalid Answer, Enter Again : ";
				cin >> ANS;

				ANS = clsString::UpperLetter(ANS);
				break;
			}

		}
	}
	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}
	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}
	static float ReadFloatNumber() {
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		return Number;
	}
	static string ReadString() {
		string s;
		 getline(cin >> ws, s);
		 return s;
	}
	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}


	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}
	static string ReadPassword() {
		string password;
		char ch;

		//cout << "Enter Password: ";
		while (true) {
			ch = _getch();

			if (ch == '\r') {
				cout << endl;
				break;
			}
			else if (ch == '\b' && !password.empty()) {
				cout << "\b \b";
				password.pop_back();
			}
			else if (ch != '\b') {
				cout << '*';
				password.push_back(ch);
			}
		}

		return password;
	}
};


#endif //CLSINPUTVALIDATE_H
