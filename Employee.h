#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Skill.h"
#include "Citizen.h"
#include <set>
#include <iostream>
using std::ostream;
using std::string;
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
    Employee(int id, string first_name, string last_name, int birth_year);
    Employee(const Employee& employee) = default;
    ~Employee() = default;

    int getSalary() const;
    int getScore() const;
    void learnSkill(const Skill skill);
    void forgetSkill(const int skill_id);
    bool hasSkill(const int skill_id);
    void setSalary(const int wage);
    void setScore(const int points);

    ostream& printShort(ostream& os) override;
    ostream& printLong(ostream& os) override;
    Employee* clone() const;
};

}
#endif /* EMPLOYEE_H_ */
