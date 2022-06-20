#include "Passenger.h"
#include <string>
#include "Vehicle.h"
#include <iostream>

using namespace std;

void Passenger::getCustomerDetails()
{

    cout << "\n\t Please Enter your name: ";
    cin >> Pname;


    cout << "\n\t Please Enter your telephone number: ";
    while(!(cin >> TelNo))               //while loop to validate user input
    {
        cout << "\n\tError please enter a Phone number! ";
        cin.clear();
        cin.ignore(400, '\n');
    }

    cout << "\n\t Please Enter your Address: ";
    cin >> PAddress;


    cout << "\n\t Please Enter the number of Passengers: ";
    while(!(cin >> NoPassengers)|| NoPassengers>=49)
    {
        cout << "\n\tError the number of passangers can only be 48 or lower! ";
        cin.clear();
        cin.ignore(100, '\n');

    }

    cout << "\n\tIf you require a wheelchair type 1 for yes or 0 for No: ";
    while (!(cin >> WheelChairReq) || (WheelChairReq>1))

    {
        cout << "Error: 1 or 0 must be entered: ";
        cin.clear();
        cin.ignore(132, '\n');
    }




}

