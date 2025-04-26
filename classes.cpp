#include <iostream>
using namespace std;

// Define a class named "Car"
class Car {
private:
    string brand;  // Private member variable
    int year;      // Private member variable

public:
    // Constructor to initialize the Car object
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    // Public member function to display car details
    void displayDetails() {
        cout << "Car Brand: " << brand << endl;
        cout << "Manufacturing Year: " << year << endl;
    }
};

int main() {
    // Create objects of the Car class
    Car car1("Toyota", 2020);
    Car car2("Honda", 2018);

    // Call member function to display details of each car
    cout << "Details of Car 1:" << endl;
    car1.displayDetails();

    cout << "\nDetails of Car 2:" << endl;
    car2.displayDetails();

    return 0;
}