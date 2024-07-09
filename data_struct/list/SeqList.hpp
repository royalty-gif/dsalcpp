/**
 *  @brief: 顺序线性表类模板
 */

#ifndef _SEQLIST_HPP_
#define _SEQLIST_HPP_

#include "Exception.hpp"
#include "List.hpp"

namespace dsalcpp
{

template < typename T > 
class SeqList : public List<T>
{
protected:
    T* array_;
    int length_;

public:
    bool insert(int i, const T& e) {
        bool ret = ( (0 <= i) && (i <= length_) ) && ( length_ < capacity() ); // O(n)

        if( ret ) {
            for(int j = length_-1; j >= i; j--) {
                array_[j+1] = array_[j];
            } 

            array_[i] = e;

            length_++;
        }

        return ret;
    }

    bool insert(const T& e) {
        return insert(length_, e);
    }

    bool remove(int i) {
        bool ret = (0 <= i) && (i < length_);

        if( ret ) {
            for(int j = i; j < length_-1; j++) {
                array_[j] = array_[j+1];
            }

            length_--;
        }

        return ret;
    }

    bool set(int i, const T& e) {
        bool ret = (0 <= i) && (i < length_);

        if( ret ) {
            array_[i] = e;
        }

        return ret;
    }

    bool get(int i, T& e) const {
        bool ret = (0 <= i) && (i < length_);

        if( ret ) {
            e = array_[i];
        }

        return ret;
    }

    int find(const T& e) const {
        int ret = -1;

        for(int i = 0; i < length_; i++) {
            if( array_[i] == e ) {
                ret = i;
                break;
            }
        }

        return ret;
    }

    int length() const {
        return length_;
    }

    void clear() {
        length_ = 0;
    }

    // 顺序存储线性表表提供数组访问方式
    T& operator[] (int i) {
        if( (0 <= i) && (i < length_) ) {
            return array_[i];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index i is invaild");
        }
    }

    T operator[] (int i) const {
        return (const_cast<SeqList<T>&>(*this))[i];
    }

    // 顺序存储空间的容量
    virtual int capacity() const = 0;
};

}

#endif