#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

class ScalarConverter {
    private:
        std::string _str;
        ScalarConverter();
        ScalarConverter(std::string toConvert);
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();
    public:
        ScalarConverter &operator=(const ScalarConverter &ScalarConverter);
        static void convert(std::string toConvert);
        std::string getToConvert();
        static bool isNum(std::string toIdentify);
        static bool isFloat(std::string toIdentify);
        static bool isChar(std::string toIdentify);
        static bool isDouble(std::string toIdentify);
        static void doubleConvert(std::string toConvert);
        static void intConvert(std::string toConvert);
        static void floatConvert(std::string toConvert);
        static void charConvert(std::string toConvert);
        static void displayChar(char c);
};

#endif