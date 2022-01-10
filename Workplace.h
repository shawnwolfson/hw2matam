#ifndef WORKPLACE_H_
#define WORKPLACE_H_

#include "Manager.h"



namespace mtm{

class setCompareFunctionManager
{
public:
    bool operator()(const Manager* man1, const Manager* man2) const {
        return ((*man1).getId() < (*man2).getId());
    }
};

class Workplace 
{

    int id;
    string name;
    int employee_salary;
    int manager_salary;
    set<Manager*, setCompareFunctionManager> managers_group;

    public:
        //c'tor
        Workplace() = default;
        Workplace(int id, string name, int employee_salary, int manager_salary, set<Manager*> managers_group = {});
        Workplace(const Workplace& workplace) = default;
        //getters
        int getId() const;
        string getName() const;
        int getWorkersSalary() const;
        int getManagersSalary() const;

        //methods
        template<class T>
        void hireEmployee(T condition, Employee* employee, int manager_id);
        void hireManager(Manager* Manager);
        void fireEmployee(int employee_id, int manager_id);
        void fireManager(int id);
        void emptyEmployeeGroup(int manager_id);

        //class friends
        friend ostream& operator<<(ostream& os, const Workplace workplace);
};

ostream& operator<<(ostream& os, const Workplace workplace);

}

#endif /* WORKPLACE_H_ */
