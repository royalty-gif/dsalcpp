/**
 *  @brief: 静态顺序线性表
 */

#ifndef _STATICLIST_HPP_
#define _STATICLIST_HPP_

#include "SeqList.hpp"

namespace dsalcpp
{

template < typename T, int N >
class StaticList : public SeqList<T>
{
protected:
    T space_[N];
public:
    StaticList() {  // 指定父类成员的具体值
        this->array_ = space_;
        this->length_ = 0;
    }

    int capacity() const {
        return N;
    }
};

}

#endif