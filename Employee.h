#ifndef EMPLOYEE_H_
#ifndef EMPLOYEE_H_

#include "Skill.h"
#include "Citizen.h"
#include <set>
using std::set;

namespace mtm
{

class Employee : public Citizen
{
    int salary;
    int score;
    set<Skill> skill_set;

public:
    //c'tors, d'tor
    Employee(int id, string first_name, string last_name, int birth_year, int salary, int score);
    Employee(const Employee& employee);
    ~Employee() = default;
}

}
#endif /* EMPLOYEE_H_*/
