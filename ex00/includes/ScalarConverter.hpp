#include <iostream>
#include <cctype>
#include <iomanip>

class ScalarConverter {
    private:
        std::string _str;
    public:
        ScalarConverter();
        ScalarConverter(std::string toConvert);
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &ScalarConverter);
        static void convert(std::string toConvert);
        std::string getToConvert();
        static bool isNum(std::string toIdentify);
        static bool isFloat(std::string toIdentify);
        static bool isChar(std::string toIdentify);
        static void intConvert(std::string toConvert);
        static void floatConvert(std::string toConvert);
        static void charConvert(std::string toConvert);
        static void displayChar(char c);
};
