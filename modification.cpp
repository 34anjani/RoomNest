#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// Hostel class
class Hostel {
private:
    string Name;
    int Rent, Beds;

public:
    Hostel(string name, int rent, int beds) : Name(name), Rent(rent), Beds(beds) {}

    string getName() { return Name; }
    int getRent() { return Rent; }
    int getBeds() { return Beds; }

    void reserveBed() {
        if (Beds > 0) {
            Beds--;
            updateHostelFile();
            cout << "\tBed Reserved Successfully!" << endl;
        } else {
            cout << "\tSorry, no beds available." << endl;
        }
    }

    void updateHostelFile() {
        ofstream out("C:\\Users\\Anjani\\Documents\\own_mini_project\\Hostel.txt");
        out << Name << " : " << Rent << " : " << Beds << endl;
        out.close();
    }

    void loadHostelData() {
        ifstream in("C:\\Users\\Anjani\\Documents\\own_mini_project\\Hostel.txt");
        if (in.is_open()) {
            string name;
            char colon;
            in >> name >> colon >> Rent >> colon >> Beds;
            Name = name;
            in.close();
        }
    }
};

// Function prototypes
void adminPanel(Hostel& hostel);
void studentPanel(Hostel& hostel, string studentName);
bool authenticate(string username, string password, string role);
bool hasReservedBed(const string& studentName);  // Check if student has reserved a bed
void markBedAsReserved(const string& studentName);  // Mark bed as reserved for the student

int main() {
    Hostel hostel("3star", 5000, 5);  // Example hostel
    hostel.loadHostelData();         // Load existing hostel data from file

    int choice;
    while (true) {
        system("cls");
        cout << "\t***************************************" << endl;
        cout << "\t   Welcome to Hostel Accommodation System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t1. Admin Login" << endl;
        cout << "\t2. Student Login" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "\tAdmin Login" << endl;
            string username, password;
            cout << "\tEnter Username: ";
            cin >> username;
            cout << "\tEnter Password: ";
            cin >> password;

            if (authenticate(username, password, "admin")) {
                cout << "\tLogin Successful! Redirecting to Admin Panel..." << endl;
                Sleep(2000);
                adminPanel(hostel);
            } else {
                cout << "\tInvalid Credentials! Please try again." << endl;
                Sleep(2000);
            }
        } else if (choice == 2) {
            system("cls");
            cout << "\tStudent Login" << endl;
            string username, password;
            cout << "\tEnter Username: ";
            cin >> username;
            cout << "\tEnter Password: ";
            cin >> password;

            if (authenticate(username, password, "student")) {
                cout << "\tLogin Successful! Redirecting to Student Panel..." << endl;
                Sleep(2000);
                studentPanel(hostel, username);
            } else {
                cout << "\tInvalid Credentials! Please try again." << endl;
                Sleep(2000);
            }
        } else if (choice == 3) {
            cout << "\tThank you for using the system. Goodbye!" << endl;
            break;
        } else {
            cout << "\tInvalid choice. Please try again." << endl;
            Sleep(2000);
        }
    }
    return 0;
}

// Function to authenticate user
bool authenticate(string username, string password, string role) {
    ifstream file("C:\\Users\\Anjani\\Documents\\own_mini_project\\users.txt");
    if (!file.is_open()) {
        cerr << "\tError opening users file!" << endl;
        return false;
    }

    string fileUsername, filePassword, fileRole;
    while (file >> fileUsername >> filePassword >> fileRole) {
        if (fileUsername == username && filePassword == password && fileRole == role) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function to check if a student has already reserved a bed
bool hasReservedBed(const string& studentName) {
    ifstream file("C:\\Users\\Anjani\\Documents\\own_mini_project\\reservations.txt");
    if (!file.is_open()) {
        cerr << "\tError opening reservations file!" << endl;
        return false;
    }

    string reservedStudent;
    while (file >> reservedStudent) {
        if (reservedStudent == studentName) {
            file.close();
            return true;  // Student has already reserved a bed
        }
    }

    file.close();
    return false;
}

// Function to mark a student as having reserved a bed
void markBedAsReserved(const string& studentName) {
    ofstream file("C:\\Users\\Anjani\\Documents\\own_mini_project\\reservations.txt", ios::app);
    if (file.is_open()) {
        file << studentName << endl;
        file.close();
    } else {
        cerr << "\tError opening reservations file!" << endl;
    }
}

// Admin Panel
void adminPanel(Hostel& hostel) {
    while (true) {
        system("cls");
        int choice;
        cout << "\tAdmin Panel" << endl;
        cout << "\t1. View Hostel Data" << endl;
        cout << "\t2. Log Out" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\tHostel Name: " << hostel.getName() << endl;
            cout << "\tRent: " << hostel.getRent() << endl;
            cout << "\tAvailable Beds: " << hostel.getBeds() << endl;
            system("pause");
        } else if (choice == 2) {
            cout << "\tLogging Out..." << endl;
            Sleep(2000);
            break;
        } else {
            cout << "\tInvalid choice. Please try again." << endl;
            Sleep(2000);
        }
    }
}

// Student Panel
void studentPanel(Hostel& hostel, string studentName) {
    system("cls");
    int choice;
    cout << "\tStudent Panel - Welcome, " << studentName << endl;

    // Check if the student has already reserved a bed
    if (hasReservedBed(studentName)) {
        cout << "\tYou have already reserved a bed." << endl;
        system("pause");
        return;
    }

    cout << "\t1. Reserve A Bed" << endl;
    cout << "\t2. Log Out" << endl;
    cout << "\tEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        hostel.reserveBed();
        markBedAsReserved(studentName);  // Mark the student as having reserved a bed
        cout << "\tThank you!" << endl;  // Thank you message
        Sleep(2000);  // Wait for 2 seconds before returning to the main menu
    } else if (choice == 2) {
        cout << "\tLogging Out..." << endl;
        Sleep(2000);  // Wait for 2 seconds before returning to the main menu
    } else {
        cout << "\tInvalid choice. Please try again." << endl;
        Sleep(2000);
    }
}
