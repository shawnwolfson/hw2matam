#include "Skill.h"
#include "exceptions.h"
using namespace mtm;

Skill::Skill(int id, string name, int points_to_acquire_skill):
        id(id), name(name), points_to_acquire_skill(points_to_acquire_skill)
        {}

Skill::Skill(const Skill& skill) : id(skill.id), name(skill.name), points_to_acquire_skill(skill.points_to_acquire_skill)
        {}

int Skill::getId() const
{
    return this->id;
}

string Skill::getName() const
{
    return this->name;
}

int Skill::getRequiredPoints() const
{
    return this->points_to_acquire_skill;
}

bool Skill::operator< (const Skill skill_to_compare_with) const
{
    return (this->getId() < skill_to_compare_with.getId() ? true : false);
}

bool Skill::operator> (const Skill skill_to_compare_with) const
{
    return (this->getId() > skill_to_compare_with.getId() ? true : false);
}

bool Skill::operator== (const Skill skill_to_compare_with) const
{
    return (this->getId() == skill_to_compare_with.getId()) ? true : false;
}

bool Skill::operator<= (const Skill skill_to_compare_with) const
{
    return (operator< (skill_to_compare_with)) || (operator== (skill_to_compare_with));
}

bool Skill::operator>= (const Skill skill_to_compare_with) const
{
    return (operator> (skill_to_compare_with)) || (operator== (skill_to_compare_with));
}

bool Skill::operator!= (const Skill skill_to_compare_with) const
{
    return !(operator== (skill_to_compare_with));
}

void Skill::operator++ (int)
{
    this->points_to_acquire_skill += 1;
}

Skill& Skill::operator+=(const int points) 
{
    if(points < 0)
    {
        throw NegativePoints();
    }
    points_to_acquire_skill += points;
    return *this;
}

Skill mtm::operator+ (const Skill& skill, const int points) 
{
    if(points < 0)
    {
        throw NegativePoints(); 
    }
    Skill temp_skill(skill.getId(), skill.getName(), (skill.getRequiredPoints() + points));
    return temp_skill;
}

Skill mtm::operator+ (const int points, const Skill& skill) 
{
    if(points < 0)
    {
        throw NegativePoints();
    }
    Skill result = skill + points;
    return result;
}

Skill& Skill::operator= (const Skill& skill)
{
    if(this == &skill)
    {
        return *this;
    }
    points_to_acquire_skill = skill.points_to_acquire_skill;
    return *this;
}

ostream& mtm::operator<< (ostream& os, const Skill skill)
{
    return os << skill.name << endl;
}


int main()
{
    Skill skill1(1, "fire", 0);
    Skill skill2(2, "water", 3);
    cout << skill1;
    cout << skill2;
    int id = skill1.getId();
    cout << "first id = " << id <<endl;
    string name = skill1.getName();
    cout << "first name = "<< name <<endl;
    int points1 = skill1.getRequiredPoints();
    cout << "first points1 = "<< points1 <<endl;
    bool false1 = skill1 > skill2;
    bool true1 = skill1 < skill2;
    bool false2 = (skill1 == skill2);
    bool false3 = skill1 >= skill2;
    bool true2 = skill1 <= skill2;
    bool true3 = skill1 != skill2;
    cout << "false1 = " << false1 <<endl;
    cout << "false2 = " << false2 <<endl;
    cout << "false3 = " << false3 <<endl;
    cout << "true1 = " << true1 <<endl;
    cout << "true2 = " << true2 <<endl;
    cout << "true3 = " << true3 <<endl;

    skill1++;
     
    points1 = skill1.getRequiredPoints();
    cout << "second points1 = "<< points1 <<endl;
    skill2 += 2;
    int points2 = skill2.getRequiredPoints();
    cout << "second points2 = " << points2 << endl;

    skill1 = skill2 + 1;
    
    points1 = skill1.getRequiredPoints();
    cout << "third points1 = " << points1 << endl;
    skill1 = 1 + skill2;
    points1 = skill1.getRequiredPoints();
    cout << "fourth points1 = " << points1 << endl;
    try{
        skill1 + -6;
    }
    catch (NegativePoints)
    {
        cout << "catch1" << endl;
    }
    try{
        -6 + skill1;
    }
    catch (NegativePoints)
    {
        cout << "catch2" << endl;
    }
    try{
        skill1 += -6;
    }
    catch (NegativePoints)
    {
        cout << "catch3" << endl;
    }

    return 0;
}
