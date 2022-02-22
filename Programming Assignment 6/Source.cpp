#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string convertToBase(int num, int base); //converts a decimal number to a base n number
string convertToString(int num); //converts each individual number into a string

int main()
{
	int num, base; //integers to hold the decimal number, and the base to be converted to
	string result; //string to hold the coverted string

	//gets the user input
	cout << "Enter a decimal number: ";
	cin >> num;
	cout << "Enter a base to convert to: ";
	cin >> base;

	//makes sure the user enters a valid base number
	while (base < 2 || base > 36)
	{
		cout << "Invalid base. Enter a base between 2 and 36: ";
		cin >> base;
	}

	//converts the decimal number and outputs it to the console
	cout << endl;
	cout << num << " converted to base " << base << " is: " 
		        << convertToBase(num, base) << endl;

	return 0;
}

//converts a decimal number to a base n number
string convertToBase(int num, int base)
{
	string result = ""; //temporary string to hold a string to be added to the final
	int temp = num; //temp to hold if the original number was negative

	//if the number is 0, any other base will also be 0
	if (num == 0)
	{
		result = "0"; //sets result to 0 and returns it
		return result;
	}
	//else, the number is greater than 0
	if (num > 0 || num < 0)
	{
		//if the number is negative, turn that number into a positive to do the calculations
		if (num < 0)
			num = abs(num);
		//if the number is less than the base, there will be no remainder so just add num converted to the string to the result
		if (num < base)
			result.insert(0, convertToString(num));
		//else, there is a remainder, so add the remainder converted to the string to the result
		else
		{
			result.insert(0, convertToString(num % base));
			result.insert(0, convertToBase(num / base, base)); //recursive call that divides by the base
		}
		//if the original number was negative, add a negative sign to the beginning
		if (temp < 0)
		{
			result.insert(0, "-");
		}
		return result; //returns the final string
	}
}

//converts a number to its appropriate string character based on the base value
string convertToString(int num)
{
	switch (num) 
	{
		case 0:
			return "0";
			break;
		case 1:
			return "1";
			break;
		case 2:
			return "2";
			break;
		case 3:
			return "3";
			break;
		case 4:
			return "4";
			break;
		case 5:
			return "5";
			break;
		case 6:
			return "6";
			break;
		case 7:
			return "7";
			break;
		case 8:
			return "8";
			break;
		case 9:
			return "9";
			break;
		case 10:
			return "A";
			break;
		case 11:
			return "B";
			break;
		case 12:
			return "C";
			break;
		case 13:
			return "D";
			break;
		case 14:
			return "E";
			break;
		case 15:
			return "F";
			break;
		case 16:
			return "G";
			break;
		case 17:
			return "H";
			break;
		case 18:
			return "I";
			break;
		case 19:
			return "J";
			break;
		case 20:
			return "K";
			break;
		case 21:
			return "L";
			break;
		case 22:
			return "M";
			break;
		case 23:
			return "N";
			break;
		case 24:
			return "O";
			break;
		case 25:
			return "P";
			break;
		case 26:
			return "Q";
			break;
		case 27:
			return "R";
			break;
		case 28:
			return "S";
			break;
		case 29:
			return "T";
			break;
		case 30:
			return "U";
			break;
		case 31:
			return "V";
			break;
		case 32:
			return "W";
			break;
		case 33:
			return "X";
			break;
		case 34:
			return "Y";
			break;
		case 35:
			return "Z";
			break;
	}
}



