#include "Employee.h"
using namespace mtm;

Employee::Employee(int id, string first_name, string last_name, int birth_year, int salary, int score) : 
    Citizen(id, first_name, last_name, birth_year), salary(salary), score(score)
{}

Employee::Employee(const Employee& employee) : 
    Citizen(Employee& employee), salary(employee.salary), score(employee.score)
