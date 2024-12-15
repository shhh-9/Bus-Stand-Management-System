#include <iostream>
using namespace std;

// Maximum number of buses
const int MAX_BUSES = 10;

// Arrays to store bus information
string busNumbers[MAX_BUSES];
string destinations[MAX_BUSES];
string departureLocations[MAX_BUSES];  // New array for departure location
int totalSeats[MAX_BUSES];
int bookedSeats[MAX_BUSES];
string departureTimes[MAX_BUSES];
string arrivalTimes[MAX_BUSES];
int busCount = 0; // Number of buses added

// Function to add a new bus 
void addBus() {
    if (busCount >= MAX_BUSES) {
        cout << "Cannot add more buses. Maximum capacity reached!" << endl;
        return;
    }

    cout << "Enter bus number: ";
    cin >> busNumbers[busCount];
    cin.ignore();

    cout << "Enter destination: ";
    getline(cin, destinations[busCount]);

    cout << "Enter departure location: ";  // Prompt for departure location
    getline(cin, departureLocations[busCount]);  // Store departure location

    cout << "Enter total seats: ";
    cin >> totalSeats[busCount];

    bookedSeats[busCount] = 0; // Initially, no seats are booked

    // Input departure time
    cout << "Enter departure time (HH:MM): ";
    cin >> departureTimes[busCount];

    // Input arrival time
    cout << "Enter arrival time (HH:MM): ";
    cin >> arrivalTimes[busCount];

    busCount+=1;
    cout << "Bus added successfully!" << endl;
}

void showAvailableBuses() {   // Function to show the status of available buses
    if (busCount == 0) {
        cout << "No buses available!" << endl;
        return;
    }

    cout << "\nAvailable Buses:\n";
    for (int i = 0; i < busCount; i++) {
        cout << "Bus Number: " << busNumbers[i]
             << ", Destination: " << destinations[i]
             << ", Departure Location: " << departureLocations[i]  // Show departure location
             << ", Departure time: " << departureTimes[i] << endl;
    }
}

// Function to show available seats in a specific bus
void showAvailableSeats() {
    cout << "Enter bus number: ";
    string busNumber;
    cin >> busNumber;

    for (int i = 0; i < busCount; i++) {
        if (busNumbers[i] == busNumber) {
            cout << "Bus Number: " << busNumbers[i] << endl;
            cout << "Available Seats: " << totalSeats[i] - bookedSeats[i] << endl;
            return;
        }
    }

    cout << "Bus not found!" << endl;
}

// Function to allot seats to passengers
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

// Function to display the status of a specific bus
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
