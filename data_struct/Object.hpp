/**
 *  @brief: 这是所有数据结构的基类
 */


#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <cstdlib>

namespace dsalcpp 
{

class Object
{
public:
    void* operator new (size_t size) throw() {
        return malloc(size);
    }

    void operator delete (void* p) {
        return free(p);
    }

    void* operator new[] (size_t size) throw() {
        return malloc(size);
    }

    void operator delete[] (void* p) {
        return free(p);
    }

    bool operator == (const Object& obj) {
        return (this == &obj);
    }

    bool operator != (const Object& obj) {
        return (this != &obj);
    }

    virtual ~Object() = 0;
};


}

#endif