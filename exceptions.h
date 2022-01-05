#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace mtm{

class Exception : public std::exception
{};

class NegativePoints : public Exception
{};

class EmployeeAlreadyHired : public Exception
{};

class EmployeeIsNotHired : public Exception
{};

class EmployeeNotSelected : public Exception
{};

class ManagerIsNotHired : public Exception
{};

class ManagerAlreadyHired : public Exception
{};

class CanNotHireManager : public Exception
{};

class CanNotLearnSkill : public Exception
{};

class SkillAlreadyLearned : public Exception
{};

class DidNotLearnSkill : public Exception
{};

}

#endif /* EXCEPTIONS_H_ */
