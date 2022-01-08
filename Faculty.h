#ifndef FACULTY_H_
#define FACULTY_H_

#include "Skill.h"
#include "Employee.h"
#include "exceptions.h"
#include <iostream>

namespace mtm
{

class Condition
{
public:
    virtual bool operator()(Employee* employee) = 0;
};

template<class Condition>
class Faculty
{
    int id;
    Condition* condition;
    Skill skill;
    int points;

public:
    //c'tors, d'tor
    Faculty(int id, const Skill& skill, int points, Condition* condition);
    Faculty(const Faculty& faculty) = default;
    ~Faculty() = default;

    //getters
    Skill getSkill() const;
    int getid() const;
    int getAddedPoints() const;

    void teach(Employee* employee);
};


template<class Condition>
Faculty<Condition>::Faculty(int id, const Skill& skill, int points, Condition* condition) : id(id),
     skill(skill), points(points), condition(condition)
{}

template<class Condition>
Skill Faculty<Condition>::getSkill() const
{
    return skill;
}

template<class Condition>
int Faculty<Condition>::getid() const
{
    return id;
}

template<class Condition>
int Faculty<Condition>::getAddedPoints() const
{
    return points;
}

template<class Condition>
void Faculty<Condition>::teach(Employee* employee)
{
    bool temp = this->condition->operator()(employee);
    if (!temp)
    {
        throw EmployeeNotAccepted();
    }
    employee->learnSkill(this->skill);
    employee->setScore(this->points);
}

}
#endif /* FACULTY_H_ */