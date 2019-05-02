#ifndef STRANGE_THINGS_H_INCLUDED
#define STRANGE_THINGS_H_INCLUDED

#include "init.h"

template<typename T>
std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}



#endif // STRANGE_THINGS_H_INCLUDED
