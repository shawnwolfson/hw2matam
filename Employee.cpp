#include "skill.h"
#include "Employee.h"
#include "exceptions.h"
using std::endl;
using std::cout;
using namespace mtm;

Employee::Employee(int id, string first_name, string last_name, int birth_year) : 
    Citizen(id, first_name, last_name, birth_year), salary(0), score(0), skill_set()
{}

int Employee::getSalary() const
{
    return salary;
}

int Employee::getScore() const
{
    return score;
}

void Employee::learnSkill(const Skill skill)
{
    if (score < skill.getRequiredPoints()) {
        throw CanNotLearnSkill();
    }
    std::set<Skill>::iterator it;
    std::pair<std::set<Skill>::iterator,bool> set_result;
    set_result = skill_set.insert(skill);
    if (set_result.second == false)
    {
        throw SkillAlreadyLearned();
    }

}

void Employee::forgetSkill(const int skill_id)
{
    Skill temp(skill_id, " ", 0);
    unsigned int set_result = skill_set.erase(temp);
    if (set_result != 1) {
        throw DidNotLearnSkill();
    }
}

bool Employee::hasSkill(const int skill_id)
{
    Skill temp(skill_id, " ", 0);
    std::set<Skill>::iterator it;
    it = skill_set.find(temp);
    if (it != skill_set.end()) {
        return true;
    }
    return false;
}

void Employee::setSalary(const int wage)
{
    if ((salary + wage) < 0) {
        this->salary = 0;
        return;
    }
    this->salary += wage;
}

void Employee::setScore(const int points)
{
    if ((score + points) < 0) {
        this->score = 0;
        return;
    }
    this->score += points;
}

//**prints**//
ostream& Employee::printShort(ostream& os)
{
    os << getFirstName() << " " << getLastName() << endl << "Salary: " << salary << " "
         << "Score: " << score << endl;
    return os;
}

ostream& Employee::printLong(ostream& os)
{
    os << getFirstName() << " " << getLastName() << endl << "id - " << getId() << " birth_year - " << getBirthYear()
        << endl << "Salary: " << salary << " " << "Score: " << score << " " << "Skills:" << endl;
    std::set<Skill>::iterator it;
    for (it = skill_set.begin(); it != skill_set.end(); ++it) {
        os << *it; 
    }
    os << endl;
    return os;
}

Employee* Employee::clone() const
{
    return new Employee(*this);
}
