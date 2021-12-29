#include "Skill.h"
using namespace mtm;


Skill::Skill(int skill_id, string skill_name, int points_to_acquire_skill):
        skill_id(skill_id), skill_name(skill_name), points_to_acquire_skill(points_to_acquire_skill)
        {}

Skill::Skill(const Skill& skill) : skill_id(skill.skill_id), skill_name(skill.skill_name), points_to_acquire_skill(skill.points_to_acquire_skill)
        {}

int Skill::getId() const
{
    return this->skill_id;
}

string Skill::getName() const
{
    return this->skill_name;
}

int Skill::getRequiredPoints() const
{
    return this->points_to_acquire_skill;
}

bool Skill::operator< (const Skill skill_to_compare_with)
{
    return (this->getId() < skill_to_compare_with.getId() ? true : false);
}

bool Skill::operator> (const Skill skill_to_compare_with)
{
    return !(operator< (skill_to_compare_with));
}

bool Skill::operator== (const Skill skill_to_compare_with)
{
    return (this->getId() == skill_to_compare_with.getId()) ? true : false;
}

bool Skill::operator<= (const Skill skill_to_compare_with)
{
    return (operator< (skill_to_compare_with)) || (operator== (skill_to_compare_with));
}

bool Skill::operator>= (const Skill skill_to_compare_with)
{
    return (operator> (skill_to_compare_with)) || (operator== (skill_to_compare_with));
}

bool Skill::operator!= (const Skill skill_to_compare_with)
{
    return !(operator== (skill_to_compare_with));
}

void Skill::operator++ (int)
{
    this->points_to_acquire_skill += 1;
}

Skill& Skill::operator+=(const int points) //think of exception
{
    if(points < 0)
    {
        throw -1; //Exception::NegativePoints();
    }
    points_to_acquire_skill += points;
    return *this;
}

Skill mtm::operator+ (const Skill& skill, const int points) //think of exception
{
    if(points < 0)
    {
        throw -1; //Exception::NegativePoints();
    }
    Skill temp_skill(skill.getId(), skill.getName(), (skill.getRequiredPoints() + points));
    return temp_skill;
}

Skill mtm::operator+ (const int points, const Skill& skill) //think of exception
{
    if(points < 0)
    {
        throw -1; //Exception::NegativePoints();
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
    return os << skill.skill_name << endl;
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
    return 0;
}

