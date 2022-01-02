#ifndef MANAGER_H_
#define MANAGER_H_

#include <string>
#include <set>
#include "Employee.h"
#include "Citizen.h"


using std::string;
using std::set;


namespace mtm {

class Manager : public Citizen
{
    double salary;
    double score;
    set<Employee> employee_group;

    public:
        //c'tors and d'tors
        Manager() = default;
        Manager(int id, string first_name, string last_name, int birth_year, double score = 0, double salary = 0, set<Employee> employee_group = {});
        Manager(const Manager& mananger);
        ~Manager() = default;

        //getters and setters
        double getSalary();
        void setSalary(int raise);

        //methods
        void addEmployee(Employee* employee); //exception
        void removeEmployee(int id); //exception
        ostream& printShort(ostream& os);
        ostream& printLong(ostream& os);
        Citizen* clone() const override;

        //operators
        Manager& operator= (const Manager& manager);
        

};

}
#endif /* MANAGER_H_ */
