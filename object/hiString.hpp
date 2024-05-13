#pragma once

#include "hiObject.hpp"
class HiString : public HiObject {
private:
    char * _value;
    int _length;

public:
    HiString(const char * x);
    HiString(const char * x, int length);

    const char * value() { return _value; }
    int length() { return _length; }
};