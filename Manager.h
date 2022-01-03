#ifndef MANAGER_H_
#define MANAGER_H_

#include <string>
#include "Employee.h"


using std::string;


namespace mtm {

class Manager : public Citizen
{
    double score;
    double salary;
    bool hired;
    set<Employee> employee_group;
    
    public:
        //c'tors and d'tors
        Manager() = default;
        Manager(int id, string first_name, string last_name, int birth_year, double score = 0, double salary = 0, bool hired = false, 
                set<Employee> employee_group = {}); 
        Manager(const Manager& mananger);
        ~Manager() = default;

        //getters and setters
        double getSalary();
        void setSalary(int raise);
        bool isHired();

        //methods
        void addEmployee(Employee* employee); 
        void removeEmployee(int id);
        Manager* clone() const override;

        //overriden methods
        ostream& printShort(ostream& os) override;
        ostream& printLong(ostream& os) override;
        
        //operators
        Manager& operator= (const Manager& manager);
        

};

}
#endif /* MANAGER_H_ */




