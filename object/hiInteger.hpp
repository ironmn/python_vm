#pragma once

#include "hiObject.hpp"

class HiInteger : public HiObject {
private:
    int _value;

public: 
    HiInteger(int x) : _value(x) {}

    int value() { return _value; }
};