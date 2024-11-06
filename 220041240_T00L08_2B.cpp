#include<bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimitKg;

public:
    Vehicle(string plate, string manufacturer, double limit) : licensePlate(plate), manufacturer(manufacturer), carriageSizeLimitKg(limit) {}

    virtual void performMaintenance() = 0; // Pure virtual function for maintenance

};

class GasolineVehicle : public Vehicle {
protected:
    double fuelTankCapacity; // Liters
    string fuelType;

public:
    GasolineVehicle(string plate, string manufacturer, double limit, double tankCapacity, string fuel)
        : Vehicle(plate, manufacturer, limit), fuelTankCapacity(tankCapacity), fuelType(fuel) {}

    void performMaintenance() override {
        cout << "Gasoline Vehicle - maintenance" << endl;
    }
};

class ElectricVehicle : public Vehicle {
protected:
    double batteryCapacity; // kWh
    double chargingTime;    // minutes

public:
    ElectricVehicle(string plate, string manufacturer, double limit, double battery, double chargeTime)
        : Vehicle(plate, manufacturer, limit), batteryCapacity(battery), chargingTime(chargeTime) {}

    void performMaintenance() override {
        cout << "Electric Vehicle - maintenance" << endl;
    }
};

class Employee {
    protected:
        string name;
        int id;

    public:
        Employee(string name, int id) : name(name), id(id) {}

        virtual void introduce() = 0; // Pure virtual function for introducing employees

};

class Hybrid : public GasolineVehicle, public ElectricVehicle {
    private:
        int Effi;
    public:
        HybridVehicle(string plate, string manufacturer, double limit, double tankCapacity, string fuel, double battery, double chargeTime, double regenEfficiency)
        : GasolineVehicle(plate, manufacturer, limit, tankCapacity, fuel), ElectricVehicle(plate, manufacturer, limit, battery, chargeTime), Effi(efficiency) {}

        void performMaintenance() override {
        cout << "Hybrid Vehicle - maintenance" << endl;
        }
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(string plate, string manufacturer, double limit, double tankCapacity, string fuel)
        : GasolineVehicle(plate, manufacturer, limit, tankCapacity, fuel) {}

    void performMaintenance() override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasolineVehicle {
    private:
        int passengerCapacity;

    public:
        Car(string plate, string manufacturer, double limit, double tankCapacity, string fuel, int passengers)
            : GasolineVehicle(plate, manufacturer, limit, tankCapacity, fuel), passengerCapacity(passengers) {}

        void performMaintenance() override {
            cout << "Car - maintenance" << endl;
        }
};

class Employee {
    protected:
        string name;
        int id;

    public:
        Employee(string name, int id) : name(name), id(id) {}

        virtual void introduce() = 0;
        virtual ~Employee() = default;
};

class Manager : public Employee {
    public:
        Manager(string name, int id) : Employee(name, id) {}

        void introduce() override {
            cout << "Mr. " << name << endl;
        }
};

class Driver : public Employee {
    public:
        Driver(string name, int id) : Employee(name, id) {}
        void introduce() override {
        cout << name << endl;
        }
};

class Branch {
private:
    string branchName;
    vector<Motorcycle> motorcycles;
    vector<Car> cars;
    vector<Truck> trucks;
    vector<ElectricVehicle> electricVehicles;
    vector<HybridVehicle> hybridVehicles;
    vector<Manager> managers;
    vector<Driver> drivers;

public:
    Branch(string name) : branchName(name) {
        // Adding vehicles to the branch (initialization of 10 vehicles per type)
        for (int i = 0; i < 10; ++i) {
            motorcycles.push_back(Motorcycle("MC" + to_string(i + 1), "X", 100, 15, "Petrol"));
            cars.push_back(Car("Car" + to_string(i + 1), "Y", 300, 40, "Diesel", 5));
            trucks.push_back(Truck("Truck" + to_string(i + 1), "Z", 1000, 150, "Petrol", 2000));
            electricVehicles.push_back(ElectricVehicle("EV" + to_string(i + 1), "A", 300, 50, 120));
            hybridVehicles.push_back(HybridVehicle("Hybrid" + to_string(i + 1), "B", 500, 50, "Petrol", 100, 90, 75));
        }

        // Adding employees (10 managers, 30 drivers)
        for (int i = 0; i < 10; ++i) {
            managers.push_back(Manager("Manager" + to_string('A' + i), i + 1));
        }
        for (int i = 0; i < 30; ++i) {
            drivers.push_back(Driver("Driver" + to_string('A' + i), i + 1));
        }
    }

    void introduceEmployees() {
        cout << "Introducing Managers:" << endl;
        for (auto& manager : managers) {
            manager.introduce();
        }
        cout << "Introducing Drivers:" << endl;
        for (auto& driver : drivers) {
            driver.introduce();
        }
    }

    void performMaintenance() {
        // Perform maintenance on all vehicles
        for (auto& motorcycle : motorcycles) motorcycle.performMaintenance();
        for (auto& car : cars) car.performMaintenance();
        for (auto& truck : trucks) truck.performMaintenance();
        for (auto& ev : electricVehicles) ev.performMaintenance();
        for (auto& hybrid : hybridVehicles) hybrid.performMaintenance();
    }
};

int main(){
    return 0;
}
