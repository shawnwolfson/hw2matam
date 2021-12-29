#ifndef SKILL_H_
#define SKILL_H_


//Implement a Skill class interface
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::endl;
using std::cout;

namespace mtm{
class Skill
{
    int skill_id;
    string skill_name;
    int points_to_acquire_skill;

public:
    //constructors
    Skill(int skill_id, string skill_name, int points_to_acquire_skill);
    Skill(const Skill& skill);
    ~Skill() = default;

    //getters
    int getId() const;
    string getName() const;
    int getRequiredPoints() const;


    //overloaded operators
    Skill& operator+= (const int points); 
    Skill& operator= (const Skill& skill);
    void operator++(int);
    bool operator< (const Skill skill_to_compare_with);
    bool operator> (const Skill skill_to_compare_with);
    bool operator== (const Skill skill_to_compare_with);
    bool operator<= (const Skill skill_to_compare_with);
    bool operator>= (const Skill skill_to_compare_with);
    bool operator!= (const Skill skill_to_compare_with);

    //class friends
    friend ostream& operator<< (ostream& os, const Skill skill);


};

ostream& operator<<(ostream& os, const Skill skill);
Skill operator+ (const Skill& skill, const int points); // needs to be a symmetrical operator
Skill operator+ (const int points, const Skill& skill); // needs to be a symmetrical operator


#endif /* SKILL_H_ */
}