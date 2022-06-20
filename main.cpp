//Author: Milan Labus
//Date: 30/03/2021
//This program will take customer details and allocate a driver and vehicle for the fare
//for that customer. It will have options to view all active fares and to print
//a report at the end of the day for each drivers and vehicles kilometers driven
//as well as daily earnings


#include <iostream>
#include "Driver.h"
#include "Vehicle.h"
#include "Passenger.h"
#include <string>

using namespace std;

int VehicleChoice;                           //variable to store the choice of vehicle
int DriverChoice;                            //variable to store the choice of driver
int JourneyDistance;                         //variable to store the distance of the journey
const unsigned short numVehicles=11;         //The size of the Vehicles Array
const unsigned short numDrivers=6;           //The size of the Drivers Array
const unsigned short numPassengers=6;        //The size of the Passengers Array
int passengerNum;                            //passenger number in the passenger array
int Availability;                            //variable to store if there is a driver and vehicle available for the customer


int main()
{

//creating an object of the class vehicle and making an in object array of the constructor using the parameters
    Vehicle vehicle[numVehicles] =
    {
        Vehicle("Taxi", "12C4956", "Hyundai","i30 Tourer", 65172,4,"Y",true),
        Vehicle("Taxi", "14C89365", "Ford","Mondeo", 33892,4,"Y",true),
        Vehicle("Taxi", "15C46046", "VW","Passat", 23897,4,"Y",true),
        Vehicle("Taxi", "14C38492", "Nissan","Primera", 29418,4,"Y",true),
        Vehicle("Taxi", "10C99393", "Skoda","Octavia", 89678,4,"Y",true),
        Vehicle("Taxi", "15C2379", "Seat","Toledo", 12812,4,"Y",true),
        Vehicle("Bus", "10C37209", "Ace","Cougar", 28786,48,"Y",true),
        Vehicle("Bus", "11C882", "Daimler","Fleetline", 68893,48,"N",true),
        Vehicle("Minibus", "14C23908", "Ford","Transit", 18567,16,"Y",true),
        Vehicle("Minibus", "10C831", "Fiat","Ducato", 32986,16,"Y",true),
        Vehicle("Minibus", "13C82677", "Mercedes","Vario", 18567,20,"N",true),

    };


    Driver driver[numDrivers] =
    {
        Driver(1234567, "Tom Daly", "14 Green St., Cork",23231, "B",876543210,true),
        Driver(2345678, "Anne O'Brien", "'Beach View', Kinsale",11980,"D", 865432109,true),
        Driver(3456789, "James Twomey", "14, French St., Cork",18414,"D1", 854321098,true),
        Driver(4567890, "Mary O'Neill", "23 Castle Road, Youghal",12669, "B",898765432,true),
        Driver(5678901, "Brendan Brown", "98 Nuns Walk, Cork",23864,"D", 832109876,true),
        Driver(6789012, "Vincent Coy", "'Green Valley', Cobh",34196,"D1", 878901234,true)

    };


    Passenger passenger[numPassengers];    //an array object of the class passenger
    Passenger pas;                         //object of the class passenger



    unsigned short MenuChoice;             //the variable that will store the users menu choice
    do
    {

        cout << "\n\tPlease Select one of the Following" << "\n";
        cout << "\t1. Enter Fare Details" << "\n";
        cout << "\t2. View All Drivers" << "\n";
        cout << "\t3. View All Vehicles" << "\n";
        cout << "\t4. View all active Fares" << "\n";
        cout << "\t5. Return from Fare"<< "\n";
        cout << "\t6. Print Daily Report" << "\n";
        cout << "\t0. To exit the program" << "\n\t";

        while (!(cin >> MenuChoice))
        {
            cout << "\n\tError please Enter one of the options available: ";
            cin.clear();
            cin.ignore(132, '\n');
        }

        if(MenuChoice==1)
        {

            passenger[passengerNum].getCustomerDetails();

            cout << "\n\tEnter the vehicle: ";
            while (!(cin>> VehicleChoice) || (VehicleChoice>10))        //Enter the Vehicle for the fare
            {
                cout << "/n/tError please select one of the Vehicles Available: ";
                cin.clear();
                cin.ignore(132, '\n');
            }
            passenger[passengerNum].setVeh(VehicleChoice);              //Passing the Vehicle choice to the Passanger Class

            cout << "\n\tEnter the Driver: ";
            while (!(cin >> DriverChoice) || (DriverChoice>6))
            {
                cout << "/n/tError please select one of the Drivers Available: ";
                cin.clear();
                cin.ignore(132, '\n');

            }
            passenger[passengerNum].setDri(DriverChoice);


            cout << "\n\tPlease Enter the Journey Distance: ";
            while(!(cin >> JourneyDistance))
            {
                cout << "/n/tError please enter the journey in KM: ";
                cin.clear();
                cin.ignore(132, '\n');
            }


            passenger[passengerNum].printCustomerDetails();         //Printing the Details for this fare


            vehicle[VehicleChoice].updateAvailability(false);       //Making the Vehicle for this fare unavailable
            vehicle [VehicleChoice].printVehicles();

            driver[DriverChoice].updateAvailability(false);         //Making the Driver for this fare unavailable
            driver [DriverChoice].printDrivers();

            passengerNum++;


        }

        else if(MenuChoice==2)
        {

            for (unsigned short i = 0; i< numDrivers; i++)          //for loop to display all elements of the array driver
            {

                driver [i].printDrivers();

            }

        }
        else if(MenuChoice==3)
        {
            for (unsigned short i = 0; i<numVehicles; i++)          //for loop to Display all Vehicles
            {
                vehicle[i].printVehicles();
            }

        }


        else if(MenuChoice==4)
        {

            for (unsigned short i = 0; i<numPassengers; i++)        //View all active fares
            {
                passenger[i].printCustomerDetails();
            }

        }
        else if(MenuChoice==5)
        {
            int pasReturn;                                          //Variable to store which customer is completing the fare

            for (unsigned short i = 0; i<numPassengers; i++)
            {
                passenger[i].printCustomerDetails();
            }
            int DriverReturning;                                //Varibale to store which driver is returning from their fare
            int VehicleReturning;                               //Variable to store which vehicle is returning from their fare

            cout << "\n\tEnter which Passenger to return fare from 0-5: " ;

            while(!(cin >> pasReturn) || (pasReturn>5))
            {

                cout << "\n\tError please select one of the passengers available: ";
                cin.clear();
                cin.ignore(132, '\n');
            }

            DriverReturning=passenger[pasReturn].getDri();                      //the Driver of the returning passenger
            VehicleReturning=passenger[pasReturn].getVeh();                     //the Vehcile of the returning passenger
            driver[DriverReturning].updateAvailability(true);
            vehicle[VehicleReturning].updateAvailability(true);
            driver[DriverReturning].updateDriverDetails(JourneyDistance);       //Updating the kms and earnings for this driver
            vehicle[VehicleReturning].updateVehicleDetails(JourneyDistance);    //Updating the kms and earnings for this vehicle
            cout << "\n\tSuccessfully Completed Fare!" << "\n";

        }
        else if(MenuChoice==6)
        {

            for (unsigned short i = 0; i< numDrivers; i++)
            {

                driver [i].DriverDailyReport();              //printing the driver daily reports
                cout << "\n";


            }
            for(unsigned short i = 0; i< numVehicles; i++)

                vehicle[i].VehicleDailyReport();          //printing the vehicle daily reports

        }


        else if(MenuChoice==0)
        {
            cout << "\n\tThank you for using the program";      //this option exits the program
        }
        else
        {
            cout << "\n\tError in input";
        }


    }

    while (MenuChoice!=0);                      //keep showing the menu till the user types 0 to exit the program
}














