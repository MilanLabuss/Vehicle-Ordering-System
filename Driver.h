#ifndef DRIVER_H
#define DRIVER_H
#include <iomanip>
#include <iostream>

using namespace std;

class Driver
{
public:
    Driver (int dID, string dName, string dAddress,int tKM,string lType, int phoneNo,bool driveravailable)
    {
        DriverID=dID;
        DriverName=dName;
        DriverAddress=dAddress;
        totalKMDriven=tKM;
        licenceType=lType;
        PhoneNo=phoneNo;
        driverAvailable=driveravailable;


    }
    void printDrivers();

    void updateAvailability(bool z)     //updating the driver availability
    {
        driverAvailable=z;
    }
    void updateDriverDetails(float f)       //updating the drivers detailsDriver
    {
        totalKMDriven+=f;
        DriverDailyKMS+=f;
        DriverDailyEarnings+=(f*6.50)+5;
    }


    void DriverDailyReport();

protected:
    int DriverID;
    string DriverName;
    string DriverAddress;
    float totalKMDriven;
    string licenceType;
    int PhoneNo;
    bool driverAvailable;
    float DriverDailyKMS=0;
    float DriverDailyEarnings=0;



};

#endif // DRIVER_H
