/**
 *  @brief: 链表类模板基类
 */

#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "Object.hpp"

namespace dsalcpp 
{

template < typename T >
class List : public Object
{
protected:
    List(const List<T>&);
    List<T>& operator=(const List<T>&);

public:
    List() {}
    virtual bool insert(const T& e) = 0;
    virtual bool insert(int i, const T& e) = 0;
    virtual bool remove(int i) = 0;
    virtual bool set(int i, const T& e) = 0;
    virtual bool get(int i, T& e) const = 0;
    virtual int find(const T& e) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;

    List<T>& self() {
        return *this;
    }
};

}

#endif