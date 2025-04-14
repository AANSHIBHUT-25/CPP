#include <iostream>
 #include <string>
 using namespace std;
 class Employee {
 private:
     string name;
     double basicSalary;
     double bonus;
 
 public:
     Employee(string empName, double basicSal, double empBonus = 5000.0) {
         name = empName;
         basicSalary = basicSal;
         bonus = empBonus;
     }
     inline double calculateTotalSalary() const {
         return basicSalary + bonus;
     }
     void displayEmployeeDetails() const {
         cout << "Employee Name: " << name << endl;
         cout << "Basic Salary: " << basicSalary << endl;
         cout << "Bonus: " << bonus << endl;
         cout << "Total Salary: " << calculateTotalSalary() << endl;
     }
     void setBonus(double empBonus) {
         bonus = empBonus;
     }
 };
 void displayAllEmployees(Employee employees[], int numEmployees) {
     for (int i = 0; i < numEmployees; i++) {
         employees[i].displayEmployeeDetails();
     }
 }
 
 int main() {
     const int MAX_EMPLOYEES = 3;  
     Employee employees[MAX_EMPLOYEES];
     employees[0] = Employee("Alice Johnson", 55000); 
     employees[1] = Employee("Bob Smith", 60000, 7000); 
     employees[2] = Employee("Charlie Brown", 45000); 
     displayAllEmployees(employees, MAX_EMPLOYEES);
     return 0;
 }
