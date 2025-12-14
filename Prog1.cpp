#include <iostream>

using namespace std;

class Vehicle
{
    protected:
        int Id;
        int year;
        string manufacturer;
        string model;

    public:
        static int total;
        Vehicle()
        {
            Id = 0;
            manufacturer = "";
            model = "";
            year = 0;
            total++;
        }
        Vehicle(int v_ID, string v_mfg, string v_mdl, int v_year)
        {
            Id = v_ID;
            manufacturer = v_mfg;
            model = v_mdl;
            year = v_year;
            total++;
        }
        virtual ~Vehicle()
        {}

        void setVehicleID(int id)
        {
            Id = id;
        }
        void setmanufacturer(string manufacture)
        {
            manufacturer = manufacture;
        }
        void setmodel(string Model)
        {
            model = Model;
        }
        void setyear(int Year)
        {
            year = Year;
        }

        int getID()
        {
            return Id;
        }

        virtual void displayVehicle()
        {
            cout << "Vehicle Id: " << Id << endl;
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

    Car(int v_id, string v_mfg, string v_mdl, int v_yr, string fuel)
        : Vehicle(v_id, v_mfg, v_mdl, v_yr)
    {
        fuelType = fuel;
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
    int battery_capacity;

public:
    ElectricCar() : Car()
    {
        battery_capacity = 0;
    }

    ElectricCar(int v_id, string v_mfg, string v_mdl, int v_yr, string fuel, int battery)
        : Car(v_id, v_mfg, v_mdl, v_yr, fuel)
    {
        battery_capacity = battery;
    }

    void displayVehicle()
    {
        Car::displayVehicle();
        cout << "Battery: " << battery_capacity << " kWh" << endl;
    }
};

class Aircraft
{
protected:
    int flight_range;

public:
    Aircraft()
    {
        flight_range = 0;
    }

    Aircraft(int f_range)
    {
        flight_range = f_range;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(int v_id, string v_mfg, string v_mdl, int v_yr, string fuel, int range)
        : Car(v_id, v_mfg, v_mdl, v_yr, fuel), Aircraft(range) {}

    void displayVehicle()
    {
        Car::displayVehicle();
        cout << "Flight Range: " << flight_range << endl;
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

    SportsCar(int v_id, string v_mfg, string v_mdl, int v_yr, string fuel, int battery, int speed)
        : ElectricCar(v_id, v_mfg, v_mdl, v_yr, fuel, battery)
    {
        topSpeed = speed;
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
    Sedan() : Car() {

    }
    Sedan(int v_id, string v_mfg, string v_mdl, int v_yr, string fuel)
        : Car(v_id, v_mfg, v_mdl, v_yr, fuel) {

        }
};

class SUV : public Car
{
public:
    SUV() : Car() {
        
    }
    SUV(int v_id, string v_mfg, string v_mdl, int v_yr, string fuel) 
    : Car(v_id, v_mfg, v_mdl, v_yr, fuel){
    
    }
};

class VehicleRegistry
{
private:
    Vehicle vehicles[100];
    int NumCount;

public:
    VehicleRegistry()
    {
        NumCount = 0;
    }

    void addVehicle(Vehicle vehical)
    {
        if (NumCount < 100)
        {
            vehicles[NumCount] = vehical;
            NumCount++;
            cout << endl << "Vehicle added sucessfully!" << endl;
        }
    }

    void displayAll()
    {
        if (NumCount == 0)
        {
            cout << endl << "No Vehicles!" << endl;
            return;
        }

        for (int i = 0; i < NumCount; i++)
        {
            vehicles[i].displayVehicle();
            cout << endl;
        }
    }

    void searchId(int id)
    {
        for (int i = 0; i < NumCount; i++)
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
    int Choice;

    do
    {
        cout << endl << "|-------- Vehicle Registry Menu --------|" << endl;
        cout << "1. for Add Vehicle" << endl;
        cout << "2. for View All Vehicles" << endl;
        cout << "3. for Search by ID" << endl;
        cout << "4. for Exit" << endl;
        cout << "------------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
        {
            int Vehicaltype;
            cout << "Select Your Vehical Type: " << endl;
            cout << "1. For Car." << endl;
            cout << "2. For Electric." << endl;
            cout << "3. For Flying." << endl;
            cout << "4. For Sports." << endl;
            cout << "5. For Sedan." << endl;
            cout << "6. For SUV." << endl;
            cout << "Your Selection: " << endl;
            cin >> Vehicaltype;

            int id, year, range, battery, speed;
            string manufacture, model, fuel;

            cout << "ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manufacture;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;

            switch (Vehicaltype)
            {
            case 1:
                cout << "Fuel: ";
                cin >> fuel;
                registry.addVehicle(Car(id, manufacture, model, year, fuel));
                break;

            case 2:
                cout << "Fuel: ";
                cin >> fuel;
                cout << "Battery: ";
                cin >> battery;
                registry.addVehicle(ElectricCar(id, manufacture, model, year, fuel, battery));
                break;

            case 3:
                cout << "Fuel: ";
                cin >> fuel;
                cout << "Range: ";
                cin >> range;
                registry.addVehicle(FlyingCar(id, manufacture, model, year, fuel, range));
                break;

            case 4:
                cout << "Fuel: ";
                cin >> fuel;
                cout << "Battery: ";
                cin >> battery;
                cout << "Top Speed: ";
                cin >> speed;
                registry.addVehicle(SportsCar(id, manufacture, model, year, fuel, battery, speed));
                break;

            case 5:
                cout << "Fuel: ";
                cin >> fuel;
                registry.addVehicle(Sedan(id, manufacture, model, year, fuel));
                break;

            case 6:
                cout << "Fuel: ";
                cin >> fuel;
                registry.addVehicle(SUV(id, manufacture,model, year, fuel));
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
            int ID;
            cout << endl << "Enter ID: ";
            cin >> ID;
            cout << endl;
            registry.searchId(ID);
            break;
            
        }

        case 4:
            
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice..." << endl;
        }

    }while(Choice!=4);


    return 0;
}