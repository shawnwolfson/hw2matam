#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <string>
#include <iostream>
#include <set>
using std::set;
using std::string;
using std::ostream;
using std::endl;
using std::cout;

namespace mtm
{

class Citizen
{
    int id;
    string first_name;
    string last_name;
    int birth_year;

public:
    //c'tors, d'tor
    Citizen(int id, string first_name, string last_name, int birth_year);
    Citizen() = default;
    Citizen(const Citizen& citizen);
    virtual ~Citizen() {}

    //getters
    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    int getBirthYear() const;

    //operators
    Citizen& operator=(const Citizen& citizen) = default;
    bool operator<(const Citizen& citizen) const;
    bool operator>(const Citizen& citizen) const;
    bool operator==(const Citizen& citizen) const;
    bool operator<=(const Citizen& citizen) const;
    bool operator>=(const Citizen& citizen) const;
    bool operator!=(const Citizen& citizen) const;

    virtual ostream& printShort(ostream& os);
    virtual ostream& printLong(ostream& os);
    virtual Citizen* clone() const = 0;
    virtual bool findCitizenInGroupById(set<Citizen> group, const int id);
    };
}
#endif /* CITIZEN_H_*/
