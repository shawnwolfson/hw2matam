
#include <vector>
#include <iostream>
#include <memory>

class BadInput
{};

//question 5.1
template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    //Bad input cases
    if((start < 0) || (start >= vec.size()))
    {
        throw BadInput();
    }
    if((stop < 0) || (stop > vec.size()))
    {
        throw BadInput();
    }
    if(step <= 0)
    {
        throw BadInput();
    }
    if(start >= stop)
    {
        std::vector<T> new_vector;
        return new_vector; //returns an empty new vector
    }

    //The function
    std::vector<T> new_vector;
    for(int index = start; index < stop; index += step )
    {
        new_vector.push_back(vec[index]);
    }
    return new_vector;
}


//question 5.2
class A {

public:
 std::vector<std::shared_ptr<int>> values;
 void add(int x) { 
     std::shared_ptr<int> ptr(new int(x));
     values.push_back(ptr);
     }
};


int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}

/*int main()
{
    std::vector<char> vec1{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> vec2 = slice(vec1, 1, 1, 5);
    for(size_t i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i];
    }
    cout << endl;
    try{
        vec1 = slice(vec1, -1, 1, 5);
    } catch(BadInput&)
    {
        cout << "start < 0" << endl;
    }

    try{
        vec1 = slice(vec1, 29, 1, 3);
    } catch(BadInput&)
    {
        cout << "start > vector.size()" << endl;
    }

    try{
        vec1 = slice(vec1, 0, 1, -2);
    } catch(BadInput&)
    {
        cout << "stop < 0" << endl;
    }

    try{
        vec1 = slice(vec1, 0, 1, 29);
    } catch(BadInput&)
    {
        cout << "stop > vector.size()" << endl;
    }

    try{
        vec1 = slice(vec1, 0, -2, 5);
    } catch(BadInput&)
    {
        cout << "step = -2 "<< endl;
    }
    vec2 = slice(vec1, 2, 2, 2);
    for(size_t i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i];
    }
    if(vec2.size() == 0)
    {
        cout<< "empty" << endl;
    }
    std::vector<int> vec3{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> vec4 = slice(vec3, 0, 1, 10);
    int number = vec4.size();
    cout<< number <<endl;
    for(size_t i = 0; i < vec4.size(); i++)
    {
    cout << vec4[i];
    }
    return 0;
}*/