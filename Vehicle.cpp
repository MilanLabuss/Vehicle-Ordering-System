#include "Vehicle.h"
#include <iomanip>


void Vehicle::printVehicles()
{
    cout <<"\n\t" << "Vehicle Type" << "\t\t" << "Registration Num" << "\t" << "Make" << "\t\t" << "Model" << "\t\t" << "KMS Driven" << "\t  " << "Capacity" << "\t" << "Wheelchair" << "\t" << "  Status" <<"\n";
    cout << fixed << showpoint << setprecision(1);
    cout << "\n\t" << VehicleType << setw(29)<< Registration << setw(20) << Make << setw(16) << Model << setw(18) << totalVehicleKM<< setw(16) << Capacity << setw(16) << Wheelchair << setw(15) << VStatus <<"\n";
}

void Vehicle::VehicleDailyReport()
{
    cout << "\n\t" << "Vehicle Registration Number" << "\t\t" << "Daily Earnings " << "\t\t" << "Daily KMS" << "\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "\n\t" << Registration << setw(37) << "$" << vehcileDailyEarnings<< setw(22) << VehcileDailyKMS <<  "\n";

}





