#include <iostream>

template <typename T>
class fractionType {
private:
    T numerator;
    T denominator;


public:
    // Constructor
    fractionType(T num = 0, T denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // Overloaded arithmetic operators
    fractionType<T> operator+(const fractionType<T>& other) const {
        return fractionType<T>((numerator * other.denominator) + (other.numerator * denominator),
            denominator * other.denominator);
    }

    fractionType<T> operator-(const fractionType<T>& other) const {
        return fractionType<T>((numerator * other.denominator) - (other.numerator * denominator),
            denominator * other.denominator);
    }

    fractionType<T> operator*(const fractionType<T>& other) const {
        return fractionType<T>(numerator * other.numerator, denominator * other.denominator);
    }

    fractionType<T> operator/(const fractionType<T>& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            exit(EXIT_FAILURE);
        }
        return fractionType<T>(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded relational operators
    bool operator==(const fractionType<T>& other) const {
        return (numerator * other.denominator) == (other.numerator * denominator);
    }

    bool operator!=(const fractionType<T>& other) const {
        return !(*this == other);
    }

    bool operator<(const fractionType<T>& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    bool operator<=(const fractionType<T>& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const fractionType<T>& other) const {
        return !(*this <= other);
    }

    bool operator>=(const fractionType<T>& other) const {
        return !(*this < other);
    }

    // Overloaded stream insertion and extraction operators
    friend std::ostream& operator<<(std::ostream& os, const fractionType<T>& fraction);
    friend std::istream& operator>>(std::istream& is, fractionType<T>& fraction);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const fractionType<T>& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, fractionType<T>& fraction) {
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;

    if (fraction.denominator == 0 || slash != '/') {
        std::cerr << "Error: Invalid fraction format." << std::endl;
        exit(EXIT_FAILURE);
    }

    return is;
}

int main() {
    // Demonstration of franctionType<T> class
    fractionType<int> frac1, frac2;

    std::cout << "Enter fraction 1 (numerator/denominator): ";
    std::cin >> frac1;

    std::cout << "Enter fraction 2 (numerator/denominator): ";
    std::cin >> frac2;

    std::cout << "\nFraction 1: " << frac1 << std::endl;
    std::cout << "Fraction 2: " << frac2 << std::endl;

    std::cout << "\nArithmetic Operations:" << std::endl;
    std::cout << "Sum: " << frac1 + frac2 << std::endl;
    std::cout << "Difference: " << frac1 - frac2 << std::endl;
    std::cout << "Product: " << frac1 * frac2 << std::endl;
    std::cout << "Quotient: " << frac1 / frac2 << std::endl;

    std::cout << "\nRelational Operations:" << std::endl;
    std::cout << "Equality: " << (frac1 == frac2 ? "true" : "false") << std::endl;
    std::cout << "Inequality: " << (frac1 != frac2 ? "true" : "false") << std::endl;
    std::cout << "Less than: " << (frac1 < frac2 ? "true" : "false") << std::endl;
    std::cout << "Less than or equal to: " << (frac1 <= frac2 ? "true" : "false") << std::endl;
    std::cout << "Greater than: " << (frac1 > frac2 ? "true" : "false") << std::endl;
    std::cout << "Greater than or equal to: " << (frac1 >= frac2 ? "true" : "false") << std::endl;

    return 0;
}
