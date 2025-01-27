#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string major;
    double gpa;
};
vector<Student> readCSV(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return students;
    }

    string line;
    getline(file, line); /

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
void displayStudents(const vector<Student>& students) {
    cout << "Total Students: " << students.size() << "\n";
    for (const auto& student : students) {
        cout << student.id << ", " << student.name << ", " << student.age
             << ", " << student.major << ", " << fixed << setprecision(2) << student.gpa << "\n";
    }
}
void displayStudents(const vector< Student>& students) {
    cout << "Total Students: " studnets.size() << "\n";
    for (const auto)
}
