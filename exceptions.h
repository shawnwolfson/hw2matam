#include <exception>

namespace mtm{

class Exception 
{
    public:
        class Exceptions : public std::exception {};
        class NegativePoints : public Exceptions {};
        
};

}
