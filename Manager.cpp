#include "Manager.h"
#include "exceptions.h"

using namespace mtm;

Manager::Manager(int id, string first_name, string last_name, int birth_year) : 
    Citizen(id, first_name, last_name, birth_year), salary(0), employees_group()
{}

int Manager::getSalary() const
{
    return salary;
}

void Manager::addEmployee(Employee* employee)
{
    unsigned int res = employees_group.count(employee);
    if (res) {
        throw EmployeeAlreadyHired();
    }

    employees_group.insert(employee);
}

void Manager::removeEmployee(int id)
{
    Employee temp(id, "", "", 0);
    if (!employees_group.count(&temp)) {
        throw EmployeeIsNotHired();
    }
    employees_group.erase(&temp);
}

void Manager::setSalary(int wage)
{
    this->salary += wage;
}

void Manager::setEmployeeSalary(int emp_id, int wage)
{
    Employee temp(emp_id, "", "", 0);
    unsigned int res = employees_group.count(&temp);
    if (!res) {
        throw EmployeeIsNotHired();
    }
    std::set<Employee*>::iterator it;
    it = employees_group.find(&temp);
    (*it)->setSalary(wage);
}

vector<int> Manager::getEmployeesId() const
{
    set<Employee*>::iterator iterator;
    vector<int> id_vector;
    for(iterator = employees_group.begin(); iterator != employees_group.end(); iterator++)
    {
      id_vector.push_back((*iterator)->getId());
    }
    return id_vector;
}

bool Manager::hasEmployees() const
{
    return !(employees_group.empty());
}
//**prints**//
ostream& Manager::printShort(ostream& os)
{
    os << getFirstName() << " " << getLastName() << endl << "Salary: " << salary << " " << endl;
    return os;
}

ostream& printLongAux(ostream& os, Employee emp)
{
    os << emp.getFirstName() << " " << emp.getLastName() << endl 
        << "Salary: " << emp.getSalary() << " " << "Score: " << emp.getScore() << endl;
    return os;
}

ostream& Manager::printLong(ostream& os)
{
    os << getFirstName() << " " << getLastName() << endl << "id - " << getId() << " birth_year - " << getBirthYear() 
        << endl << "Salary: " << salary << endl << "Employees:" << endl;
    std::set<Employee*>::iterator it;
    for (it=employees_group.begin(); it!=employees_group.end(); ++it) {
        printLongAux(os, (*(*it)));
    }
    return os;
}

Manager* Manager::clone() const
{
    return new Manager(*this);
}
