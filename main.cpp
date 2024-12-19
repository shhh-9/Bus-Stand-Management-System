#include <iostream>
using namespace std;

// Maximum number of buses
const int maxBuses = 10;

// Maximum number of seats per bus
const int maxSeats = 40; 

// Arrays to store bus information
string busNumbers[maxBuses];
string destinations[maxBuses];
string departureLocations[maxBuses];  // Array for departure location
int totalSeats[maxBuses];  // Initialize all buses with 40 seats
int bookedSeats[maxBuses] = {0};  // Initialize all buses with 0 booked seats
string departureTimes[maxBuses];
string arrivalTimes[maxBuses];
int busCount = 0; // Number of buses added

// Function to add a new bus 
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

    cout << "Enter departure location: ";  // Prompt for departure location
    getline(cin, departureLocations[busCount]);  // Store departure location

    totalSeats[busCount] = maxSeats; // Set total seats for the new bus
    bookedSeats[busCount] = 0; // Initially, no seats are booked

    // Input departure time
    cout << "Enter departure time (HH:MM)[AM/PM]: ";
    cin >> departureTimes[busCount];

    // Input arrival time
    cout << "Enter arrival time (HH:MM)[AM/PM]: ";
    cin >> arrivalTimes[busCount];

    busCount += 1;
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
            cout << "Total Seats: " << totalSeats[i] << endl;
            cout << "Booked Seats: " << bookedSeats[i] << endl;
            cout << "Available Seats: " << totalSeats[i] - bookedSeats[i] << endl;

            // Show the seat arrangement in a 4x10 grid format (2x2 with aisle)
            cout << "Seat Status (2x2 with aisle arrangement):\n";
            int seatCount = 0;  // Reset seatCount here
            for (int row = 0; row < 10; row++) {  // 10 rows
                for (int col = 0; col < 2; col++) {  // Left side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  // Booked seat
                    } else {
                        cout << "[ ] ";  // Available seat
                    }
                    seatCount++;
                }
                cout << "  |  ";  
                for (int col = 0; col < 2; col++) {  // Right side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  // Booked seat
                    } else {
                        cout << "[ ] ";  // Available seat
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

            // Show the seat arrangement in a 4x10 grid format (2x2 with aisle)
            cout << "Seats Status\n";
            int seatCount = 0;  // Reset seatCount here
            for (int row = 0; row < 10; ++row) {  // 10 rows
                for (int col = 0; col < 2; ++col) {  // Left side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  // Booked seat
                    } else {
                        cout << "[ ] ";  // Available seat
                    }
                    seatCount++;
                }
                cout << "  |  ";  // Aisle
                for (int col = 0; col < 2; ++col) {  // Right side seats (2)
                    if (seatCount < bookedSeats[i]) {
                        cout << "[X] ";  // Booked seat
                    } else {
                        cout << "[ ] ";  // Available seat
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

