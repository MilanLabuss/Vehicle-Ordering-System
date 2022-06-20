#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <iomanip>

using namespace std;

class Vehicle
{
public:
    Vehicle (string Vtype,string RegNo, string mk, string mdl, int totalVlKM, int Cap, string Wchair, bool Vstatus)
    {
        Registration=RegNo;
        Make=mk;
        Model=mdl;
        totalVehicleKM=totalVlKM;
        Capacity=Cap;
        VehicleType=Vtype;
        Wheelchair=Wchair;
        VStatus=Vstatus;
    }

    void printVehicles();
    void updateAvailability(bool x)             //Funciton to update the Vehicles availability
    {
        VStatus=x;
    }
    void updateVehicleDetails(float f)          //Function to update the Vehicles details
    {
        totalVehicleKM+=f;
        VehcileDailyKMS+=f;
        vehcileDailyEarnings+=(f*6.50)+5;
    }
    void VehicleDailyReport();



protected:
    bool VStatus;          //availability status of the vehicleVehicle
    string Wheelchair;
    int Capacity;
    string Registration;
    string Vtype;
    string Make;
    string Model;
    float totalVehicleKM;
    string VehicleType;
    float VehcileDailyKMS=0;
    float vehcileDailyEarnings=0;


};

#endif // VEHICLE_H
