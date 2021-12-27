#ifndef SKILL_H_
#define SKILL_H_


//Implement a Skill class interface
#include <string>
#include <iostream>
using std::string;
using std::ostream;

ostream& operator<<(ostream& os, const Skill skill);
bool operator< (const Skill first_skill, const Skill second_skill);
bool operator> (const Skill first_skill, const Skill second_skill);
bool operator== (const Skill first_skill, const Skill second_skill);
bool operator<= (const Skill first_skill, const Skill second_skill);
bool operator>= (const Skill first_skill, const Skill second_skill);
bool operator!= (const Skill first_skill, const Skill second_skill);

class Skill
{
    int skill_id;
    string skill_name;
    int points_to_acquire_skill;

public:
    Skill(int skill_id, int skill_name, int points_to_acquire_skill, int current_skill_strength);
    //need const constructor?
    //need default constructor?
    //need copy constructor?
    ~Skill();
    int getId();
    string getName();
    int getRequiredPoints();
    Skill operator++ (const int points); //this way we will only support right side ++, returns a class skill with updated points_to_acquire_skill.
    Skill operator+= (const int points); // if the input was negative number need to throw an exception.
    //האם צריך לתמוך בשרשור כמו בתרגול 7 שקופית 45?
    //exception!
    Skill operator+ (const int points); //if recieved negative number need to throw exception
    //exception!
    //what does this operator+ do?
    friend ostream& operator<< (ostream& os, const Skill skill);
    friend bool operator< (const Skill first_skill, const Skill second_skill);
    friend bool operator> (const Skill first_skill, const Skill second_skill);
    friend bool operator== (const Skill first_skill, const Skill second_skill);
    friend bool operator<= (const Skill first_skill, const Skill second_skill);
    friend bool operator>= (const Skill first_skill, const Skill second_skill);
    friend bool operator!= (const Skill first_skill, const Skill second_skill);
    
};













#endif /* SKILL_H_ */