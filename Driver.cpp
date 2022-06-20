#include "Driver.h"
#include <iostream>
#include <iomanip>

using namespace std;



void Driver::printDrivers()
{

    cout <<"\n\t" << "DriverID" << "\t" << "DriverName" << "\t\t" << "DriverAddress" << "\t\t" << "totalKMDriven" << "\t\t" << "licenceType" << "\t" << "PhoneNo" << "\t\t" << "Available" <<"\t" << "\n";
    cout << fixed << showpoint << setprecision(1);
    cout << "\n\t" << DriverID << setw(18) << DriverName << setw(30) << DriverAddress << setw(18) << totalKMDriven << setw(22) << licenceType << setw(19) << PhoneNo << setw(13) <<  driverAvailable << "\n";

}

void Driver::DriverDailyReport()
{
    cout << "\n\t" << "DriverID" << "\t" << "Daily Earnings" << "\t\t" << "Daily KMS" << "\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "\n\t" << DriverID << setw(14) << "$" <<  DriverDailyEarnings << setw(21) << DriverDailyKMS <<  "\n";

}






