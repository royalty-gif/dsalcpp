/**
 *  @brief: 异常处理类
 */

#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include "Object.hpp"
#include <cstring>
#include <cstdlib>
#include <cstdio>

namespace dsalcpp
{

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception : public Object
{
protected:
    char* message_;
    char* localtion_;

    void init(const char* message, const char* file, int line) {
        message_ = (message ? strdup(message) : NULL);

        if( (file != NULL) && (line > 0) ) {
            char sl[16] = {0};

            // 整数转字符串
            snprintf(sl, sizeof(sl), "%d", line);

            localtion_ = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));

            if( localtion_ != NULL ) {
                localtion_ = strcpy(localtion_, file);
                localtion_ = strcat(localtion_, ":");
                localtion_ = strcat(localtion_, sl);
            }
        } else {
            localtion_ = NULL;
        }
    }

public:
    Exception(const char* message) {
        init(message, NULL, 0);
    }

    Exception(const char* file, int line) {
        init(NULL, file, line);
    }

    Exception(const char* message, const char* file, int line) {
        init(message, file, line);
    }

    Exception(const Exception& e) {
        message_ = strdup(e.message_);
        localtion_ = strdup(e.localtion_);
    }

    Exception& operator= (const Exception& e) {
        if( this != &e ) {
            free(message_);
            free(localtion_);

            message_ = strdup(e.message_);
            localtion_ = strdup(e.localtion_);
        }

        return *this;
    }

    virtual const char* message() const {
        return message_;
    }

    virtual const char* location() const {
        return localtion_;
    }

    virtual ~Exception() {
        free(message_);
        free(localtion_);
    }
};

// 算术异常
class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(0) { }
    ArithmeticException(const char* message) : Exception(message) { }
    ArithmeticException(const char* file, int line) : Exception(file, line) { }
    ArithmeticException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    ArithmeticException(const ArithmeticException& e) : Exception(e) { }

    ArithmeticException& operator= (const ArithmeticException& e) {
        Exception::operator=(e);
        return *this;
    }
};

// 空指针异常
class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(0) { }
    NullPointerException(const char* message) : Exception(message) { }
    NullPointerException(const char* file, int line) : Exception(file, line) { }
    NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    NullPointerException(const NullPointerException& e) : Exception(e) { }

    NullPointerException& operator= (const NullPointerException& e) {
        Exception::operator=(e);
        return *this;
    }
};

// 索引越界异常
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(0) { }
    IndexOutOfBoundsException(const char* message) : Exception(message) { }
    IndexOutOfBoundsException(const char* file, int line) : Exception(file, line) { }
    IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e) { }

    IndexOutOfBoundsException& operator= (const IndexOutOfBoundsException& e) {
        Exception::operator=(e);
        return *this;
    }
};

// 内存不足异常
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(0) { }
    NoEnoughMemoryException(const char* message) : Exception(message) { }
    NoEnoughMemoryException(const char* file, int line) : Exception(file, line) { }
    NoEnoughMemoryException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) { }

    NoEnoughMemoryException& operator= (const NoEnoughMemoryException& e) {
        Exception::operator=(e);
        return *this;
    }
};

// 非法参数异常
class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() : Exception(0) { }
    InvalidParameterException(const char* message) : Exception(message) { }
    InvalidParameterException(const char* file, int line) : Exception(file, line) { }
    InvalidParameterException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    InvalidParameterException(const InvalidParameterException& e) : Exception(e) { }

    InvalidParameterException& operator= (const InvalidParameterException& e) {
        Exception::operator=(e);
        return *this;
    }
};

// 非法操作异常
class InvalidOperationException : public Exception
{
public:
    InvalidOperationException() : Exception(0) { }
    InvalidOperationException(const char* message) : Exception(message) { }
    InvalidOperationException(const char* file, int line) : Exception(file, line) { }
    InvalidOperationException(const char* message, const char* file, int line) : Exception(message, file, line) { }

    InvalidOperationException(const InvalidOperationException& e) : Exception(e) { }

    InvalidOperationException& operator= (const InvalidOperationException& e) {
        Exception::operator=(e);
        return *this;
    }
};   

}

#endif