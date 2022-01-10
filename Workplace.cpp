#include "Workplace.h"
#include "exceptions.h"


using namespace mtm;

void Workplace::emptyEmployeeGroup(int manager_id)
{
    Manager* manager = findManagerInWorkplace(manager_id);
    vector<int> id_array = manager->getEmployeesId();
    for(int index = 0; index < id_array.size(); ++index)
    {
        fireEmployee(id_array[index], id);
    }
}

Manager* Workplace::findManagerInWorkplace(int id) const
{
    Manager temp_manager(id, "", "", 0);
    set<Manager*>::iterator managers_it;
    managers_it = managers_group.find(&temp_manager);
    if(managers_it == managers_group.end())
    {
        throw ManagerIsNotHired();
    }
    return (*managers_it);
}

void Workplace::changeSalaryForAllEmployeesUnderManager(Manager* manager, int wage)
{
    if(manager->hasEmployees())
    {
        vector<int> id_array = manager->getEmployeesId();
        for(unsigned int index = 0; index < id_array.size(); ++index)
        {
            manager->setEmployeeSalary(id_array[index], wage);
        }
    } 
}
//c'tor
Workplace::Workplace(int id, string name, int employee_salary, int manager_salary, set<Manager*> managers_group) :
                    id(id), name(name), employee_salary(employee_salary), manager_salary(manager_salary), managers_group()
                    {}


int Workplace::getId() const
{
    return id;
}

string Workplace::getName() const
{
    return name;
}

int Workplace::getWorkersSalary() const
{
    return employee_salary;
}

int Workplace::getManagersSalary() const
{
    return manager_salary;
}

template<class T>
void Workplace::hireEmployee(T condition, Employee* employee, int manager_id)
{
    if(!(condition(employee)))
    {
        throw EmployeeNotSelected();
    }
    Manager* manager = findManagerInWorkplace(manager_id);
    manager->addEmployee(employee);
    employee->setSalary(employee_salary);
}


void Workplace::hireManager(Manager* manager)
{
    if(managers_group.count(manager))
    {
        throw ManagerAlreadyHired();
    }
    if((manager->getSalary()) > 0)
    {
        throw CanNotHireManager();
    }
    changeSalaryForAllEmployeesUnderManager(manager, employee_salary);
    manager->setSalary(manager_salary);
    managers_group.insert(manager);
}

void Workplace::fireEmployee(int employee_id, int manager_id)
{
    Manager* manager = findManagerInWorkplace(manager_id);
    manager->setEmployeeSalary(employee_id, -employee_salary);
    manager->removeEmployee(employee_id);
}

void Workplace::fireManager(int id)
{
    Manager* manager = findManagerInWorkplace(id);
    changeSalaryForAllEmployeesUnderManager(manager, -employee_salary);
    manager->setSalary(-manager_salary);
    managers_group.erase(manager);
}

ostream& mtm::operator<<(ostream& os, const Workplace workplace)
{
    set<Manager*>::iterator managers_it = workplace.managers_group.begin();
    if(managers_it == workplace.managers_group.end())
    {
        os << "Workplace name - " << workplace.getName() << endl;
        return os;
    }
    os << "Workplace name - " << workplace.getName() << " Groups:" << endl;
    for(; managers_it != workplace.managers_group.end(); ++managers_it)
    {
        os << "Manager ";
        (*managers_it)->printLong(os);
    }
    return os;
}

/*class Condition{
public:
    bool operator()(Employee* emp){
    return emp->getId()>0;
    }
};


int main()
{
    Workplace Meta(1,"Meta", 10000, 20000);
    Manager* m1 = new Manager(10,"Robert", "stark", 1980);
    Employee* e1 = new Employee(100, "John", "Williams", 2002);
    Meta.hireManager(m1);
    Condition condition;
    Meta.hireEmployee(condition, e1, m1->getId());
    cout << Meta << endl;
    Meta.fireManager(m1->getId());
    cout<< Meta << endl;
    cout<< "--salary--" << e1->getSalary() << endl;
    Meta.hireManager(m1);
    cout<< "--salary--" << e1->getSalary() << endl;
    delete m1;
    delete e1;
    return 0;
}*/

/*class Condition{
public:
    bool operator()(Employee* emp){
    return emp->getId()>0;
    }
};

class Condition2
{
    public:
    bool operator()(Employee* emp)
    {
        return emp->getBirthYear()>=2005;
    }
};

int main() {
    Workplace Meta(1,"Meta", 10000, 20000);
    Employee* e1 = new Employee(1, "John", "Williams", 2002);
    Employee* e2 = new Employee(2, "Alex", "Martinez", 2000);
    Manager* m1 = new Manager(1,"Robert", "stark", 1980);
    Meta.hireManager(m1);
    Condition condition;
    Meta.hireEmployee(condition,e1,m1->getId());
    Meta.hireEmployee(condition,e2,m1->getId());
    cout << Meta;
    Meta.fireManager(m1->getId());
    cout << Meta;
    cout << "------------------" << endl;
    cout << Meta.getId() << endl;
    cout << Meta.getName() << endl;
    cout << Meta.getWorkersSalary() << endl;
    cout << Meta.getManagersSalary() << endl;
    Manager* m2 = new Manager(7, "Max", "Pain", 1500);
    Meta.hireManager(m2);
    Condition2 condition2;
    Employee* e3 = new Employee(3, "shawn", "wolfson", 2005);
    Employee* e4 = new Employee(4, "sandy", "zag", 2000);
    Meta.hireEmployee(condition2 , e3, 7);
    try
    {
        Meta.hireEmployee(condition2 , e4, 7);
    } catch(EmployeeNotSelected& exc )
    {
        cout << "catch1" << endl;
    }
    cout << Meta;
    try{
        Meta.hireEmployee(condition2 , e3, 200);
    }
    catch(ManagerIsNotHired&)
    {
        cout << "catch2" << endl;
    }
    try
    {
        Meta.hireEmployee(condition2, e3, 7);
    }
    catch(EmployeeAlreadyHired&)
    {
        cout << "catch3" << endl;
    }
    try
    {
        Meta.hireManager(m2);
    }
    catch(ManagerAlreadyHired&)
    {
        cout << "catch4" << endl;
    }
    try
    {
        Meta.fireEmployee(4,7);
    }
    catch(EmployeeIsNotHired&)
    {
        cout << "catch5" << endl;
    }
    try
    {
        Meta.fireEmployee(3,100);
    }
    catch(ManagerIsNotHired&)
    {
        cout << "catch6" << endl;
    }
    try
    {
        Meta.fireManager(600);
    }
    catch(ManagerIsNotHired&)
    {
        cout << "catch7" << endl;
    }
    Workplace Google(2,"Google", 10000, 20000);
    try{
        Google.hireManager(m2);
    } catch(CanNotHireManager&) 
    {
        cout << "catch8" << endl;
    }
    //cout << "here" << endl;
    Meta.fireManager(m2->getId());
    cout << Meta<<endl;;
    cout << Google<<endl;;

    Meta.hireManager(m1);
    Meta.hireManager(m2);
    Meta.hireEmployee(condition, e1, m2->getId());
    cout << Meta <<endl;
    delete e1;
    delete e2;
    delete m1;
    delete m2;
    delete e3;
    delete e4;
    return 0;
}*/

