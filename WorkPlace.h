#ifndef WORKPLACE_H_
#define WORKPLACE_H_

#include "Manager.h"



namespace mtm{

class Workplace: 
{

    int id;
    string name;
    int employee_salary;
    int manager_salary;
    set<Manager> managers_group;

    public:
        //c'tor
        Workplace(); //think of this

        //getters
        int getId() const;
        string getName() const;
        int getWorkersSalary() const;
        int getManagersSalary() const;

        //methods
        //hire employee??
        void hireManager(Manager* Manager);
        void fireEmployee(int employee_id, int manager_id);
        void fireManager(int id);
        friend ostream& operator<<(ostream& os, const Workplace workplace);
};

ostream& operator<<(ostream& os, const Workplace workplace);

}

#endif /* WORKPLACE_H_ */
