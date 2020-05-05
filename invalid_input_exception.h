//
// Created by Diana Grigore on 03-May-20.
//

#ifndef TEMA_INVALID_INPUT_EXCEPTION_H
#define TEMA_INVALID_INPUT_EXCEPTION_H
#include <bits/exception.h>

class invalid_input_exception : public std :: exception {
    std::string msg;
public:
    invalid_input_exception(const std::string& msg) : msg(msg){}

    virtual const char* what() const noexcept override
    {
        return msg.c_str();
    }
};




#endif //TEMA_INVALID_INPUT_EXCEPTION_H
