#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _str("empty") {
}

ScalarConverter::ScalarConverter(std::string toConvert) {
    this->_str = toConvert;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    this->_str = copy._str;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other) {
        this->_str = other._str;
    }
    return *this;
}

std::string ScalarConverter::getToConvert() {
    return this->_str;
}

bool ScalarConverter::isFloat(std::string toIdentify) {
    bool has_decimal_point = false;

    if (toIdentify[toIdentify.length() - 1] == 'f') {
        toIdentify.erase(toIdentify.length() - 1);
    }
    for (int i = 0; toIdentify[i]; i++) {
        if (toIdentify[i] == '.') {
            if (has_decimal_point) {
                return false;
            }
            has_decimal_point = true;
        }
        else if (!std::isdigit(toIdentify[i]) && !(i == 0 && toIdentify[i] == '-')) {
            return false;
        }
    }
    return has_decimal_point;
}

bool ScalarConverter::isNum(std::string toIdentify) {
    for (int i = 0; toIdentify[i]; i++) {
        if (!std::isdigit(toIdentify[i]) && !(i == 0 && toIdentify[i] == '-')) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isChar(std::string toIdentify) {
    if ((toIdentify.length() > 1) || !(std::isprint(toIdentify[0]))) {
        return false;
    }
    return true;
}

bool ScalarConverter::isDouble(std::string toIdentify) {
    bool has_decimal_point = false;

    if (toIdentify[toIdentify.length() - 1] == 'f') {
        return false;
    }

    for (int i = 0; toIdentify[i]; i++) {
        if (toIdentify[i] == '.') {
            if (has_decimal_point) {
                return false;
            }
            has_decimal_point = true;
        } else if (!std::isdigit(toIdentify[i]) && !(i == 0 && toIdentify[i] == '-')) {
            return false;
        }
    }
    return has_decimal_point;
}

void ScalarConverter::displayChar(char toDisplay) {
    if (std::isprint(toDisplay)) {
        std::cout << "char: " << toDisplay << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::doubleConvert(std::string toConvert) {
    try {
        std::istringstream iss(toConvert);
        double doubleValue;
        iss >> doubleValue;
        if (iss.fail()) {
            throw std::invalid_argument("Invalid argument");
        }
        if (doubleValue < 32 || doubleValue > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: " << static_cast<char>(doubleValue) << std::endl;
        }
        std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}

void ScalarConverter::intConvert(std::string toConvert) {
    try {
        int intValue = 0;
        std::stringstream test;
        test << toConvert;
        test >> intValue;
        if (intValue < 32 || intValue > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: " << static_cast<char>(intValue) << std::endl;
        }
        std::cout << "int: " << intValue << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}

void ScalarConverter::floatConvert(std::string toConvert) {
    try {
        // Remove the 'f' suffix if present
        std::string processedStr = toConvert;
        if (toConvert[toConvert.length() - 1] == 'f') {
            processedStr = toConvert.substr(0, toConvert.length() - 1);
        }

        std::istringstream iss(processedStr);
        float floatValue;
        iss >> floatValue;
        if (iss.fail()) {
            throw std::invalid_argument("Invalid argument");
        }
        if (floatValue < 32 || floatValue > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: " << static_cast<char>(floatValue) << std::endl;
        }
        std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}

void ScalarConverter::charConvert(std::string toConvert) {
    try { 
        char charValue = toConvert[0];
        displayChar(charValue);
        std::cout << "int: " << static_cast<int>(charValue) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<int>(charValue)  << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(charValue) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}

void ScalarConverter::convert(std::string toConvert) {
    if (toConvert == "nan" || toConvert == "-inf" || toConvert == "+inf" || toConvert == "inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << toConvert << "f" << std::endl;
        std::cout << "double: " << toConvert << std::endl;
        return;
    }
    if (isFloat(toConvert)) {
        floatConvert(toConvert);
        return;
    }
    if (isNum(toConvert)) {
        intConvert(toConvert);
        return;
    }
    if (isChar(toConvert)) {
        charConvert(toConvert);
        return;
    }
    if (isDouble(toConvert)) {
        doubleConvert(toConvert);
        return;
    }
    std::cout << "Error: could not determine type of input" << std::endl;
}