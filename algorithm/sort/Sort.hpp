/**
 *  @brief: 排序算法
 */

#ifndef _SORT_HPP_
#define _SORT_HPP_

#include "Array.hpp"
#include "Object.hpp"

namespace dsalcpp
{

class Sort : public Object
{
private:
    Sort();
    Sort(const Sort&);
    Sort& operator=(const Sort&);

    template< typename T >
    static void swap(T& a, T& b) {
        T t = a;
        a = b;
        b = t;
    }

public:
    template< typename T >
    static void select(T array[], int len, bool min2max = true) {
        for(int i = 0; i < len; i++) {
            int min = i;

            for(int j = i+1; j < len; j++) {
                if( min2max ? (array[j] < array[min]) : (array[j] > array[min]) ) {
                    min = j;
                }
            }

            if( min != i ) {
                swap(array[i], array[min]);
            }
        }
    }

    template< typename T >
    static void insert(T array[], int len, bool min2max = true) {
        for(int i = 1; i < len; i++) {
            int k = i;
            T e = array[i];

            for(int j = i - 1; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j--) {
                array[j+1] = array[j];
                k = j;
            }

            if( k != i ) {
                array[k] = e;
            }
        }
    }
};

}


#endif