#include "Manager.h"
#include "exceptions.h"
using namespace mtm;


Manager::Manager(int id, string first_name, string last_name, int birth_year, double score, double salary, bool hired, set<Employee> employee_group):
                 Citizen(id, first_name, last_name, birth_year), score(score), salary(salary), hired(hired) ,employee_group(employee_group) 
                {}


Manager::Manager(const Manager& manager):
                Citizen(manager), salary(manager.salary), score(manager.score), hired(hired)
                {
                    employee_group = manager.employee_group;
                }

void Manager::addEmployee(Employee* employee)
{
    if(!((this->employee_group.find(*employee)) == (this->employee_group.end()))) //this means the employee is already in the group
    {
        throw EmployeeAlreadyHired();
    }
    employee_group.insert(*employee);
}

void Manager::removeEmployee(int id) 
{
    if(!(mtm::findCitizenInGroupById<Employee>(this->employee_group, id)))
    {
        throw EmployeeIsNotHired();
    }
    set<Employee>::iterator iterator; // if we are here, employee must be in the group
    for(iterator = employee_group.begin(); iterator != employee_group.end(); ++iterator) 
    {
        if((*iterator).getId() == id)
        {
            this->employee_group.erase(*iterator);
        }
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

bool Manager::isHired()
{
    return this->hired;
}

ostream& Manager::printShort(ostream& os)
{
    os << this->getFirstName() << " " << this->getLastName() << endl;
    os << "Salary: " << this->salary << endl;
    return os;
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
    return os;
}

Manager* Manager::clone() const //is not complete
{
    Manager new_manager;
    return &new_manager;
}

