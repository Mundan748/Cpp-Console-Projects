#include <iostream>
#include <string>
using namespace std;

// Define struct for Student
struct Student {
    int rollNumber;
    string name;
    float marks[3]; // Marks for 3 subjects
    float average;
};

// Function to input student details
void inputStudentData(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cin.ignore(); // to clear newline character
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Enter marks for 3 subjects:\n";
        float total = 0;
        for (int j = 0; j < 3; ++j) {
            cout << "Subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
            total += students[i].marks[j];
        }
        students[i].average = total / 3;
    }
}

// Function to display student data
void displayStudentData(Student students[], int n) {
    cout << "\n--- Student Report ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nRoll Number: " << students[i].rollNumber << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Marks: ";
        for (int j = 0; j < 3; ++j) {
            cout << students[i].marks[j] << " ";
        }
        cout << "\nAverage: " << students[i].average;
        if (students[i].average >= 50)
            cout << " (Pass)\n";
        else
            cout << " (Fail)\n";
    }
}

int main() {
    int SIZE = 100;
    Student students[SIZE];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n > SIZE) {
        cout << "Limit exceeded. Max is " << SIZE << ".\n";
        return 0;
    }

    inputStudentData(students, n);
    displayStudentData(students, n);

    return 0;
}
