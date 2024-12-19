#include <iostream>
using namespace std;

//maximum number of buses
const int maxBuses = 10;

//maximum number of seats per bus
const int maxSeats = 40; 

//arrays to store bus information
string busNumbers[maxBuses];
string destinations[maxBuses];
string departureLocations[maxBuses];  //array for departure location
int totalSeats[maxBuses] = {maxSeats};  //all buses can only have 40 seats
int bookedSeats[maxBuses];
string departureTimes[maxBuses];
string arrivalTimes[maxBuses];
int busCount = 0; //number of buses added

//function to add a new bus 
void addBus() {
    if (busCount >= maxBuses) {
        cout << "Cannot add more buses. Maximum capacity reached!" << endl;
        return;
    }

    cout << "Enter bus number: ";
    cin >> busNumbers[busCount];
    cin.ignore();

    cout << "Enter destination: ";
    getline(cin, destinations[busCount]);

    cout << "Enter departure location: ";  //prompt for departure location
    getline(cin, departureLocations[busCount]);  //store departure location

    bookedSeats[busCount] = 0; //initially, no seats are booked

    //input departure time
    cout << "Enter departure time (HH:MM): ";
    cin >> departureTimes[busCount];

    //input arrival time
    cout << "Enter arrival time (HH:MM): ";
    cin >> arrivalTimes[busCount];

    busCount += 1;
    cout << "Bus added successfully!" << endl;
}

void showAvailableBuses() {   //function to show the status of available buses
    if (busCount == 0) {
        cout << "No buses available!" << endl;
        return;
    }

    cout << "\nAvailable Buses:\n";
    for (int i = 0; i < busCount; i++) {
        cout << "Bus Number: " << busNumbers[i]
             << ", Destination: " << destinations[i]
             << ", Departure Location: " << departureLocations[i]  //show departure location
             << ", Departure time: " << departureTimes[i] << endl;
    }
}

//function to show available seats in a specific bus
void showAvailableSeats() {
    cout << "Enter bus number: ";
    string busNumber;
    cin >> busNumber;

    for (int i = 0; i < busCount; i++) {
        if (busNumbers[i] == busNumber) {
            cout << "Bus Number: " << busNumbers[i] << endl;
            cout << "Total Seats: " << totalSeats[i] << endl;
            cout << "Booked Seats: " << bookedSeats[i] << endl;
            cout << "Available Seats: " << totalSeats[i] - bookedSeats[i] << endl;

            //show the seat arrangement in a 4x10 grid format (4 rows and 10 columns with an aisle)
            cout << "Seat Status:\n";
            int seatCount = 0;
            for (int row = 0; row < 10; row++) {  //10 rows
                for (int col = 0; col < 2; col++) {  //left side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  //booked seat
                    } else {
                        cout << "[ ] ";  //available seat
                    }
                    seatCount++;
                }
                cout << "  |  ";  
                for (int col = 0; col < 2; col++) {  //right side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  //booked seat
                    } else {
                        cout << "[ ] ";  //available seat
                    }
                    seatCount++;
                }
                cout << endl;
            }
            return;
        }
    }

    cout << "Bus not found!" << endl;
}

//function to allot seats to passengers
void allotSeat() {
    cout << "Enter bus number: ";
    string busNumber;
    cin >> busNumber;

    for (int i = 0; i < busCount; i++) {
        if (busNumbers[i] == busNumber) {
            int seatsToBook;
            cout << "Enter number of seats to book: ";
            cin >> seatsToBook;

            if (seatsToBook <= 0) {
                cout << "Invalid number of seats!" << endl;
                return;
            }

            if (bookedSeats[i] + seatsToBook > totalSeats[i]) {
                cout << "Not enough seats available! Only " 
                     << (totalSeats[i] - bookedSeats[i]) << " left." << endl;
            } else {
                bookedSeats[i] += seatsToBook;
                cout << "Seats booked successfully!" << endl;
            }
            return;
        }
    }

    cout << "Bus not found!" << endl;
}

//function to display the status of a specific bus
void showBusStatus() {
    cout << "Enter bus number: ";
    string busNumber;
    cin >> busNumber;

    for (int i = 0; i < busCount; i++) {
        if (busNumbers[i] == busNumber) {
            cout << "Bus Number: " << busNumbers[i] << endl;
            cout << "Destination: " << destinations[i] << endl;
            cout << "Departure Location: " << departureLocations[i] << endl;  // Show departure location
            cout << "Total Seats: " << totalSeats[i] << endl;
            cout << "Booked Seats: " << bookedSeats[i] << endl;
            cout << "Available Seats: " << totalSeats[i] - bookedSeats[i] << endl;
            cout << "Departure Time: " << departureTimes[i] << endl;
            cout << "Arrival Time: " << arrivalTimes[i] << endl;

            //show the seat arrangement in a 4x10 grid format (2x2 with aisle)
            cout << "Seats Status\n";
            int seatCount = 0;
            for (int row = 0; row < 10; ++row) {  //10 rows
                for (int col = 0; col < 2; ++col) {  //left side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  //booked seat
                    } else {
                        cout << "[ ] ";  //available seat
                    }
                    seatCount++;
                }
                cout << "  |  ";  //aisle
                for (int col = 0; col < 2; ++col) {  //right side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  //booked seat
                    } else {
                        cout << "[ ] ";  //available seat
                    }
                    seatCount++;
                }
                cout << endl;
            }
            return;
        }
    }

    cout << "Bus not found!" << endl;
}

int main() {
    bool ison = true;
    while (ison) {
        cout << "\nBus Stand Management System\n";
        cout << "1. Add New Bus\n";
        cout << "2. Show Available Buses\n";
        cout << "3. Show Available Seats in a Bus\n";
        cout << "4. Allot Seats to Passenger\n";
        cout << "5. Show Bus Status\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                showAvailableBuses();
                break;
            case 3:
                showAvailableSeats();
                break;
            case 4:
                allotSeat();
                break;
            case 5:
                showBusStatus();
                break;
            case 6:
                cout << "Thank you for using the Bus Stand Management System!" << endl;
                ison = false;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
