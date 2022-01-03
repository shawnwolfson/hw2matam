#include "WorkPlace.h"
#include "exceptions.h"
using namespace mtm;

//c'tor


int Workplace::getId() const
{
    return this->id;
}

string Workplace::getName() const
{
    return this->name;
}

int Workplace::getWorkersSalary() const
{
    return this->employee_salary;
}

int Workplace::getManagersSalary() const
{
    return this->manager_salary;
}

void Workplace::hireManager(Manager* manager)
{
    if(!((this->managers_group.find(*manager)) == (this->managers_group.end()))) //this means the employee is already in the group
    {
        throw ManagerAlreadyHired();
    }
    if(manager->isHired())
    {
        throw CanNotHireManager();
    }
    this->managers_group.insert(*manager);
}

void Workplace::fireEmployee(int employee_id, int manager_id)
{
    if(!(mtm::findCitizenInGroupById<Manager>(this->managers_group, id)))
    {
        throw ManagerIsNotHired();
    }

}
