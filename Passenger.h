#ifndef PASSENGER_H
#define PASSENGER_H
#include<string>

#include <iostream>

using namespace std;


class Passenger
{
public:

    void getCustomerDetails();
    void printCustomerDetails()     //funciton to print the passengers details
    {
        cout << "\n\tName: " << Pname << "  TelNum: " << TelNo << " Address: " << PAddress
             << "  Number Passengers: " << NoPassengers << "  Wheelchair Requirement: " << WheelChairReq << " Vehicle Number: " << VehicleNumber << " Driver Number: " << DriverNumber << "\n";
    }

    void setVeh(int x)          //Setter for the passengers vehicle number
    {
        VehicleNumber=x;
    }

    int getVeh()            //getter for the passengers vehicle number
    {
        return VehicleNumber;
    }

    void setDri(int x)         //setter for the passengers vehicle number
    {
        DriverNumber=x;
    }

    int getDri()                //getter for the passengers vehicle number
    {
        return DriverNumber;
    }



protected:
    string Pname="empty";
    int TelNo=0;
    string PAddress="empty";
    int NoPassengers=0;
    int WheelChairReq=999;         //setting the wheelchair requirement as 999 instead of 0 because 0 is one of the options

private:
    int VehicleNumber=999;      //setting the VehicleNumber requirement as 999 instead of 0 because 0 is one of the options
    int DriverNumber=999;     //setting the DriverNumber requirement as 999 instead of 0 because 0 is one of the options


};

#endif // PASSENGER_H
