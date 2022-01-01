#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace mtm{

class Exception : public std::exception
{};

class NegativePoints : public Exception
{};

}

#endif /* EXCEPTIONS_H_ */
