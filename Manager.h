#ifndef MANAGER_H_
#define MANAGER_H_

#include "Citizen.h"
#include "Employee.h"
#include <set>
#include <iostream>
#include <vector>

using std::vector;
using std::ostream;
using std::string;
using std::set;
using std::endl;

namespace mtm
{

//*funcor*//
class setCompareFunction
{
public:
    bool operator()(const Employee* emp1, const Employee* emp2) const {
        return ((*emp1).getId() < (*emp2).getId());
    }
};


class Manager : public Citizen
{
    int salary;
    set<Employee*, setCompareFunction> employees_group;

public:
    //c'tors, d'tor
    Manager(int id, string first_name, string last_name, int birth_year);
    Manager(const Manager& manager) = default;
    ~Manager() = default;

    int getSalary() const;
    void setSalary(int wage);
    void addEmployee(Employee* employee);
    void removeEmployee(int id);
    void setEmployeeSalary(int emp_id, int wage);
    vector<int> getEmployeesId() const;
    bool hasEmployees() const;


    ostream& printShort(ostream& os) override;
    ostream& printLong(ostream& os) override;
    Manager* clone() const;

};



}
#endif /* MANAGER_H_ */
