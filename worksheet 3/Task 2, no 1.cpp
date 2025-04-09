#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNumber;
    string color;

public:
    Vehicle() {}

    virtual void getDetails(const string &vehicleType) {
        cout << "Enter Registration Number of the " << vehicleType << ": ";
        cin >> regNumber;
        cout << "Enter Color of the " << vehicleType << ": ";
        cin >> color;
    }

    virtual void writeDetailsToFile() = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numSeats;

public:
    Car() {}

    void getDetails(const string &vehicleType) override {
        Vehicle::getDetails(vehicleType);
        cout << "Enter Number of Seats for the " << vehicleType << ": ";
        cin >> numSeats;
    }

    void writeDetailsToFile() override {
        ofstream file("car_details.txt", ios::app);
        if (file) {
            file << "Car Registration Number: " << regNumber << "\n";
            file << "Car Color: " << color << "\n";
            file << "Number of Seats: " << numSeats << "\n";
            file.close();
        } else {
            cout << "Error opening car_details.txt for writing.\n";
        }
    }
};

class Bike : public Vehicle {
private:
    float engineCapacity;

public:
    Bike() {}

    void getDetails(const string &vehicleType) override {
        Vehicle::getDetails(vehicleType);
        cout << "Enter Engine Capacity (in CC) for the " << vehicleType << ": ";
        cin >> engineCapacity;
    }

    void writeDetailsToFile() override {
        ofstream file("bike_details.txt", ios::app);
        if (file) {
            file << "Bike Registration Number: " << regNumber << "\n";
            file << "Bike Color: " << color << "\n";
            file << "Engine Capacity: " << engineCapacity << " CC\n";
            file.close();
        } else {
            cout << "Error opening bike_details.txt for writing.\n";
        }
    }
};

int main() {
    int choice;
    Vehicle* vehicle;
    string vehicleType;

    cout << "Choose the type of vehicle you want to add details to:\n";
    cout << "1. Car\n2. Bike\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        vehicleType = "Car";
        vehicle = new Car();
        vehicle->getDetails(vehicleType);
    } else if (choice == 2) {
        vehicleType = "Bike";
        vehicle = new Bike();
        vehicle->getDetails(vehicleType);
    } else {
        cout << "Invalid choice! Exiting.\n";
        return 1;
    }

    vehicle->writeDetailsToFile();

    cout << "Every details of the "<<vehicleType<<  " is saved successfully in the file named "<<vehicleType<<"_details !\n";

    delete vehicle;
    return 0;
}
