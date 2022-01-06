#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <string>
#include <iostream>
#include <set>
using std::set;
using std::string;
using std::ostream;

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
    Citizen(const Citizen& citizen) = default;
    virtual ~Citizen() = default;

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

    virtual ostream& printShort(ostream& os) = 0;
    virtual ostream& printLong(ostream& os) = 0;
    virtual Citizen* clone() const = 0;
};

}
#endif /* CITIZEN_H_ */
