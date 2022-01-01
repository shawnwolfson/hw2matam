#include <exception>

namespace mtm{

class Exception : public std::exception
{};

class NegativePoints : public Exception
{};

}
