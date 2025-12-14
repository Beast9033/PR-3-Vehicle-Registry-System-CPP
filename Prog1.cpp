#include <iostream>

using namespace std;

class Vehicle
{
protected:
    int vehicleId;
    int year;
    string manufacturer;
    string model;

public:
    static int total;

    Vehicle()
    {
        vehicleId = 0;
        manufacturer = "";
        model = "";
        year = 0;
        total++;
    }

    Vehicle(int v_vehicleId, string v_manufacturer, string v_model, int v_year)
    {
        vehicleId = v_vehicleId;
        manufacturer = v_manufacturer;
        model = v_model;
        year = v_year;
        total++;
    }

    virtual ~Vehicle() {}

    void setVehicleID(int id)
    {
        vehicleId = id;
    }

    void setManufacturer(string manufacture)
    {
        manufacturer = manufacture;
    }

    void setModel(string modelName)
    {
        model = modelName;
    }

    void setYear(int vehicleYear)
    {
        year = vehicleYear;
    }

    int getID()
    {
        return vehicleId;
    }

    virtual void displayVehicle()
    {
        cout << "Vehicle Id: " << vehicleId << endl;
        cout << "Vehicle Manufacturer: " << manufacturer << endl;
        cout << "Vehicle Model: " << model << endl;
        cout << "Vehicle Year: " << year << endl;
    }
};

int Vehicle::total = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car()
    {
        fuelType = "";
    }

    Car(int v_vehicleId, string v_manufacturer, string v_model, int v_year, string v_fuelType)
        : Vehicle(v_vehicleId, v_manufacturer, v_model, v_year)
    {
        fuelType = v_fuelType;
    }

    void displayVehicle()
    {
        Vehicle::displayVehicle();
        cout << "Fuel: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int v_vehicleId, string v_manufacturer, string v_model, int v_year, string v_fuelType, int v_batteryCapacity)
        : Car(v_vehicleId, v_manufacturer, v_model, v_year, v_fuelType)
    {
        batteryCapacity = v_batteryCapacity;
    }

    void displayVehicle()
    {
        Car::displayVehicle();
        cout << "Battery: " << batteryCapacity << " kWh" << endl;
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(int v_flightRange)
    {
        flightRange = v_flightRange;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(int v_vehicleId, string v_manufacturer, string v_model, int v_year, string v_fuelType, int v_flightRange)
        : Car(v_vehicleId, v_manufacturer, v_model, v_year, v_fuelType),
          Aircraft(v_flightRange) {}

    void displayVehicle()
    {
        Car::displayVehicle();
        cout << "Flight Range: " << flightRange << endl;
    }
};

class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportsCar(int v_vehicleId, string v_manufacturer, string v_model, int v_year, string v_fuelType, int v_batteryCapacity, int v_topSpeed)
        : ElectricCar(v_vehicleId, v_manufacturer, v_model, v_year, v_fuelType, v_batteryCapacity)
    {
        topSpeed = v_topSpeed;
    }

    void displayVehicle()
    {
        ElectricCar::displayVehicle();
        cout << "Top Speed: " << topSpeed << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan() : Car() {}

    Sedan(int v_vehicleId, string v_manufacturer, string v_model, int v_year, string v_fuelType)
        : Car(v_vehicleId, v_manufacturer, v_model, v_year, v_fuelType) {}
};

class SUV : public Car
{
public:
    SUV() : Car() {}

    SUV(int v_vehicleId, string v_manufacturer, string v_model, int v_year, string v_fuelType)
        : Car(v_vehicleId, v_manufacturer, v_model, v_year, v_fuelType) {}
};

class VehicleRegistry
{
private:
    Vehicle vehicles[100];
    int vehicleCount;

public:
    VehicleRegistry()
    {
        vehicleCount = 0;
    }

    void addVehicle(Vehicle vehicle)
    {
        if (vehicleCount < 100)
        {
            vehicles[vehicleCount] = vehicle;
            vehicleCount++;
            cout << endl << "Vehicle added successfully!" << endl;
        }
    }

    void displayAll()
    {
        if (vehicleCount == 0)
        {
            cout << endl << "No Vehicles!" << endl;
            return;
        }

        for (int i = 0; i < vehicleCount; i++)
        {
            vehicles[i].displayVehicle();
            cout << endl;
        }
    }

    void searchById(int id)
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicles[i].getID() == id)
            {
                vehicles[i].displayVehicle();
                cout << endl;
                return;
            }
        }
        cout << endl << "Vehicle not found!" << endl;
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << endl << "|-------- Vehicle Registry Menu --------|" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int vehicleType;
            cout << "Select Vehicle Type:" << endl;
            cout << "1. Car" << endl;
            cout << "2. Electric Car" << endl;
            cout << "3. Flying Car" << endl;
            cout << "4. Sports Car" << endl;
            cout << "5. Sedan" << endl;
            cout << "6. SUV" << endl;
            cin >> vehicleType;

            int id, year, flightRange, batteryCapacity, topSpeed;
            string manufacturer, model, fuelType;

            cout << "ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manufacturer;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;

            switch (vehicleType)
            {
            case 1:
                cout << "Fuel: ";
                cin >> fuelType;
                registry.addVehicle(Car(id, manufacturer, model, year, fuelType));
                break;

            case 2:
                cout << "Fuel: ";
                cin >> fuelType;
                cout << "Battery: ";
                cin >> batteryCapacity;
                registry.addVehicle(ElectricCar(id, manufacturer, model, year, fuelType, batteryCapacity));
                break;

            case 3:
                cout << "Fuel: ";
                cin >> fuelType;
                cout << "Range: ";
                cin >> flightRange;
                registry.addVehicle(FlyingCar(id, manufacturer, model, year, fuelType, flightRange));
                break;

            case 4:
                cout << "Fuel: ";
                cin >> fuelType;
                cout << "Battery: ";
                cin >> batteryCapacity;
                cout << "Top Speed: ";
                cin >> topSpeed;
                registry.addVehicle(SportsCar(id, manufacturer, model, year, fuelType, batteryCapacity, topSpeed));
                break;

            case 5:
                cout << "Fuel: ";
                cin >> fuelType;
                registry.addVehicle(Sedan(id, manufacturer, model, year, fuelType));
                break;

            case 6:
                cout << "Fuel: ";
                cin >> fuelType;
                registry.addVehicle(SUV(id, manufacturer, model, year, fuelType));
                break;

            default:
                cout << "Invalid Type!" << endl;
            }
            break;
        }

        case 2:
            registry.displayAll();
            break;

        case 3:
        {
            int searchId;
            cout << "Enter ID: ";
            cin >> searchId;
            registry.searchById(searchId);
            break;
        }

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice..." << endl;
        }

    } while (choice != 4);

    return 0;
}
