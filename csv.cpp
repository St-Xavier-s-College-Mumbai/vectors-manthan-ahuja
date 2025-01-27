#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string major;
    double gpa;
};

// Function to read student data from a CSV file
vector<Student> readCSV(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return students;
    }

    string line;
    getline(file, line); // Skip the header

    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        string temp;

        getline(ss, temp, ',');
        student.id = stoi(temp);

        getline(ss, student.name, ',');

        getline(ss, temp, ',');
        student.age = stoi(temp);

        getline(ss, student.major, ',');

        getline(ss, temp, ',');
        student.gpa = stod(temp);

        students.push_back(student);
    }

    file.close();
    return students;
}

// Function to display student details
void displayStudents(const vector<Student>& students) {
    cout << "Total Students: " << students.size() << "\n";
    for (const auto& student : students) {
        cout << student.id << ", " << student.name << ", " << student.age
             << ", " << student.major << ", " << fixed << setprecision(2) << student.gpa << "\n";
    }
}

// Function to filter students based on GPA > 3.0
vector<Student> filterStudentsByGPA(const vector<Student>& students) {
    vector<Student> filtered;
    for (const auto& student : students) {
        if (student.gpa > 3.0) {
            filtered.push_back(student);
        }
    }
    return filtered;
}

// Function to calculate the average age
double calculateAverageAge(const vector<Student>& students) {
    if (students.empty()) return 0.0;

    int totalAge = 0;
    for (const auto& student : students) {
        totalAge += student.age;
    }
    return static_cast<double>(totalAge) / students.size();
}

// Function to write filtered students to a new CSV file
void writeCSV(const string& filename, const vector<Student>& students) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not write to file " << filename << "\n";
        return;
    }

    file << "ID,Name,Age,Major,GPA\n";
    for (const auto& student : students) {
        file << student.id << "," << student.name << "," << student.age
             << "," << student.major << "," << fixed << setprecision(2) << student.gpa << "\n";
    }

    file.close();
}

int main() {
    const string inputFilename = "students.csv";
    const string outputFilename = "filtered_students.csv";

    // Read data from CSV
    vector<Student> students = readCSV(inputFilename);

    if (students.empty()) {
        cerr << "No data found in the file or unable to read the file." << endl;
        return 1;
    }

    // Display all students
    displayStudents(students);

    // Filter students based on GPA > 3.0
    vector<Student> filteredStudents = filterStudentsByGPA(students);

    // Display filtered students
    cout << "\nFiltered Students (GPA > 3.0):\n";
    displayStudents(filteredStudents);

    // Calculate and display average age
    double averageAge = calculateAverageAge(students);
    cout << "\nAverage Age: " << fixed << setprecision(2) << averageAge << "\n";

    // Write filtered students to a new CSV file
    writeCSV(outputFilename, filteredStudents);
    cout << "\nFiltered students written to " << outputFilename << "\n";

    return 0;
}
