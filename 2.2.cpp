#include <iostream>
 #include <string>
 #include <iomanip>  
 using namespace std;
 
 class Student {
 private:
     string rollNumber;
     string name;
     int marks[3];
     double average;
 
 public:
     Student(string roll = "Unknown", string n = "Default Name", int m1 = 0, int m2 = 0, int m3 = 0) 
         : rollNumber(roll), name(n) {
         marks[0] = m1;
         marks[1] = m2;
         marks[2] = m3;
         calculateAverage();  
 
     void calculateAverage() {
         double sum = 0;
         for (int i = 0; i < 3; ++i) {
             sum += marks[i];
         }
         average = sum / 3.0; 
     }
     void displayStudentInfo() {
         cout << "Roll Number: " << rollNumber << endl;
         cout << "Name: " << name << endl;
         cout << "Marks: ";
         for (int i = 0; i < 3; ++i) {
             cout << marks[i] << " ";
         }
         cout << endl;
         cout << "Average: " << fixed << setprecision(2) << average << endl;
     }
     string toString() {
         stringstream ss;
         ss << rollNumber << " | " << name << " | Marks: ";
         for (int i = 0; i < 3; ++i) {
             ss << marks[i] << " ";
         }
         ss << "| Average: " << fixed << setprecision(2) << average;
         return ss.str();
     }
 };
 void testSystem() {
     Student students[4];
     students[0] = Student();
     students[1] = Student("S001", "John Doe", 78, 82, 91);
     students[2] = Student("S002", "Jane Smith", 85, 76, 88);
     students[3] = Student("S003", "Mark Lee", 91, 94, 88);
     for (int i = 0; i < 4; ++i) {
         students[i].displayStudentInfo();
         cout << "students detalis are :" << endl;
     }
 }
 
 int main() {
     // Run the test system
     testSystem();
     return 0;
 }
