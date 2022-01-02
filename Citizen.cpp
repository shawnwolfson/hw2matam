#include "Citizen.h"
using namespace mtm;

//**c'tors, d'tor**//
Citizen::Citizen(int id, string first_name, string last_name, int birth_year) : 
    id(id), first_name(first_name), last_name(last_name), birth_year(birth_year)
{}

Citizen::Citizen(const Citizen &citizen) : 
    id(citizen.id), first_name(citizen.first_name), last_name(citizen.last_name), birth_year(citizen.birth_year)
{}

//**getters**//
int Citizen::getId() const
{
    return this->id;
}

string Citizen::getFirstName() const
{
    return this->first_name;
}

string Citizen::getLastName() const
{
    return this->last_name;
}

int Citizen::getBirthYear() const
{
    return this->birth_year;
}

//**operators**//
/*Citizen& operator=(const Citizen& citizen)
{
    if(this == &citizen) {
        return *this;
    }
    id = citizen.id;
    first_name = citizen.first_name;
    last_name = citizen.last_name;
    birth_year = citizen.birth_year;
    return *this;
}*/

bool Citizen::operator<(const Citizen& citizen) const
{
    return ((this->getId() < citizen.getId()) ? true : false);
}

bool Citizen::operator>(const Citizen& citizen) const
{
    return ((this->getId() > citizen.getId()) ? true : false);
}

bool Citizen::operator==(const Citizen& citizen) const
{
    return ((this->getId() == citizen.getId()) ? true : false);
}

bool Citizen::operator<=(const Citizen& citizen) const
{
    return ((this->getId() <= citizen.getId()) ? true : false);
}

bool Citizen::operator>=(const Citizen& citizen) const
{
    return ((this->getId() >= citizen.getId()) ? true : false);
}

bool Citizen::operator!=(const Citizen& citizen) const
{
    return ((this->getId() != citizen.getId()) ? true : false);
}
