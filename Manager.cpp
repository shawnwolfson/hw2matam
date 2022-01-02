#include "Manager.h"
#include "exceptions.h"
using namespace mtm;

bool findEmployeeById(std::set<Employee> employee_group, int id) //think of clone
{
    std::set<Employee>::iterator iterator;
    for(iterator = employee_group.begin(); iterator != employee_group.end(); ++iterator)
    {
        if(iterator.getId() == id)
        {
            return true;
        }
    }
    return false;
}

Employee* getEmployeeById(std::set<Employee> employee_group, int id)
{
    std::set<Employee>::iterator iterator;
    for(iterator = employee_group.begin(); iterator != employee_group.end(); ++iterator)
    {
        break;
    }
}



Manager::Manager(int id, string first_name, string last_name, int birth_year, double score, double salary, set<Employee> employee_group):
                 Citizen(id, first_name, last_name, birth_year), score(score), salary(salary), employee_group(employee_group) 
                {}


Manager::Manager(const Manager& manager):
                Citizen(manager), salary(manager.salary), score(manager.score)
                {
                    employee_group = manager.employee_group;
                }

void Manager::addEmployee(Employee* employee)
{
    if(!((this->employee_group.find(*employee)) == this->employee_group.end())) //this means the employee is already in the group
    {
        throw EmployeeAlreadyHired();
    }
    employee_group.insert(*employee);
}

void Manager::removeEmployee(int id) //comeback
{
    if(!findEmployeeById(this->employee_group, id))
    {
        throw EmployeeIsNotHired();
    }
}

double Manager::getSalary()
{
    return this->salary;
}

void Manager::setSalary(int raise)
{
    (this->salary) += raise;
}

ostream& Manager::printShort(ostream& os)
{
    os << this->getFirstName() << " " << this->getLastName() << endl;
    os << "Salary: " << this->salary << endl;
}
ostream& Manager::printLong(ostream& os)
{
    os << this->getFirstName() << " " << this->getLastName() << endl;
    os << "id - " << this->getId() << "birth_year = " << this->getBirthYear() << endl;
    os << "Salary: " << this->salary << endl;
    os << "Employees:" << endl;
    std::set<Employee>::iterator iterator;
    for(iterator = this->employee_group.begin(); iterator != this->employee_group.end(); ++iterator)
    {
        //clone?
        printShort(os); // what will happen?
        os << endl; //needed?
    }
}

Citizen* Manager::clone() const override
{

}
