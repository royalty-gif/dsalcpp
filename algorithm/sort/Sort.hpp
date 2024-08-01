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
        // 表示第一个数是已经排好序的，因此只需要从后边的数值开始遍历
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

    template< typename T > 
    static void shell(T array[], int len, bool min2max = true) {
        // 将整个待排序的序列分割成若干个子序列分别进行插入排序，再对整个序列进行插入排序
        int d = len;

        do {
            d = d / 3 + 1;

            for(int i = d; i < len; i += d) {
                int k = i;
                T e = array[i];

                for(int j = i - d; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j -= d) {
                    array[j+d] = array[j];
                    k = j;
                }

                if( k != i ) {
                    array[k] = e;
                }
            }

        } while( d > 1 );
    }

    template< typename T > 
    static void bubble(T array[], int len, bool min2max = true) {
        bool exchange = true;

        for(int i = 0; i < len && exchange; i++) {
            exchange = false;

            for(int j = len - 1; j > i; j--) {
                if( min2max ? (array[j] < array[j-1]) : (array[j] > array[j-1]) ) {
                    swap(array[j], array[j-1]);
                    exchange = true;
                }
            }
        }
    }
};

}


#endif