#pragma once
#include <iostream>
#include <string>

//reordered class layout - private and public sections and constructors/deconstructors for readability
//(private first then public)

class Data {
    private:
    int numID_;
    std::string name_;

    public:
    Data(int numID, const std::string& name) : numID_(numID), name_(name) {}

    bool operator==(const Data& other) const {
        return numID_ == other.numID_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Data& d) {
        return out << d.numID_ << " " << d.name_;
    }
};