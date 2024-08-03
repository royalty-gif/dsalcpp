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

    template< typename T >
    static void merge(T array[], T helper[], int begin, int mid, int end, bool min2max = true) {
        int i = begin;
        int j = mid + 1;
        int k = begin;

        while( (i <= mid) && (j <= end) ) {
            if( min2max ? (array[i] < array[j]) : (array[i] > array[j]) ) {
                helper[k++] = array[i++];
            } else {
                helper[k++] = array[j++];
            }
        }

        while( i <= mid ) {
            helper[k++] = array[i++];
        }

        while( j <= end ) {
            helper[k++] = array[j++];
        }

        for(int i = begin; i < end; i++) {
            array[i] = helper[i];
        }
    }

    template< typename T >
    static void merge(T array[], T helper[], int begin, int end, bool min2max = true) {
        if( begin < end ) {
            int mid = (begin + end) / 2;

            merge(array, helper, begin, mid, min2max);
            merge(array, helper, mid+1, end, min2max);
            merge(array, helper, begin, mid, end, min2max);
        }
    }

    template< typename T >
    static int position(T array[], int begin, int end, bool min2max = true) {
        T pv = array[begin];

        while(begin < end) {

            while((begin < end) && (min2max ? (array[end] > pv) : (array[end] < pv))) {
                end--;
            }

            swap(array[begin], array[end]);

            while((begin < end) && (min2max ? (array[begin] <= pv) : (array[begin] >= pv))) {
                begin++;
            }

            swap(array[begin], array[end]);
        }

        array[begin] = pv;

        return begin;
    }

    template< typename T >
    static void quick(T array[], int begin, int end, bool min2max = true) {
        if(begin < end) {
            int pivot = position(array, begin, end, min2max);

            quick(array, begin, pivot-1, min2max);
            quick(array, pivot+1, end, min2max);
        }
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

    template< typename T >
    static void merge(T array[], int len, bool min2max = true) {
        T* helper = new T[len];

        if( helper != nullptr ) {
            merge(array, helper, 0, len-1, min2max);
        }

        delete[] helper;
    }

    template< typename T >
    static void quick(T array[], int len, bool min2max = true) {
        quick(array, 0, len-1, min2max);
    }
};

}


#endif