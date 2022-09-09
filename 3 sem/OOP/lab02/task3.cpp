#include <iostream>
#include <cstring>
#include <cmath>

static long int max(long int x, long int y);
static long int min(long int x, long int y);

class Rational {
    public:
        Rational() : numerator(-1), denominator(-1) {};
        Rational(int num, int denom) : numerator(num), denominator(denom) {};

        friend Rational operator+(const Rational& rat1, const Rational& rat2);
        friend Rational operator-(const Rational& rat1, const Rational& rat2);
        friend Rational operator*(const Rational& rat1, const Rational& rat2);
        friend Rational operator/(const Rational& rat1, const Rational& rat2);
        friend std::ostream& operator<<(std::ostream& out, const Rational& rat);
        friend std::istream& operator>>(std::istream& in, Rational& rat);
        friend bool operator>(const Rational& rat1, const Rational& rat2);
        friend bool operator<(const Rational& rat1, const Rational& rat2);
        friend bool operator<=(const Rational& rat1, const Rational& rat2);
        friend bool operator>=(const Rational& rat1, const Rational& rat2);
        friend bool operator==(const Rational& rat1, const Rational& rat2);
        friend bool operator!=(const Rational& rat1, const Rational& rat2);
    private:
        long int numerator;
        long int denominator;

        void reduce();
};

Rational operator""_rat(const char* string, size_t size);

int main() {
    Rational num1 = {3, 5};
    Rational num2 = {3, 5};
    Rational num3 = {1, 15};
    Rational num4 = "10/17"_rat;

    std::cout << "+: " << num1 + num2 + num3 << std::endl;
    std::cout << "+: " << num4 + num4 << std::endl;
    std::cout << "-: " << num1 - num2 << std::endl;
    std::cout << "*: " << num1 * num2 << std::endl;
    std::cout << "/: " << num1 / num2 << std::endl;

    if (num1 == num2) {
        std::cout << num1 << " " << num2 << " " << "eq\n"; 
    }

    if (num1 <= num3) {
        std::cout << num1 << " " << num3 << " " << "!eq\n"; 
    }

    if (num1 > num3) {
        std::cout << num1 << " " << num3 << " " << ">\n"; 
    }

    if (num1 >= num2) {
        std::cout << num1 << " " << num2 << " " << "eq or >\n"; 
    }

    return 0;
}

Rational operator+(const Rational& rat1, const Rational& rat2) {
    long int commonDenominator = rat1.denominator * rat2.denominator;
    long int newNumerator = rat1.numerator * rat2.denominator + rat2.numerator * rat1.denominator;

    Rational result(newNumerator, commonDenominator);
    result.reduce();

    return result;
}

Rational operator-(const Rational& rat1, const Rational& rat2) {
    long int commonDenominator = rat1.denominator * rat2.denominator;
    long int newNumerator = rat1.numerator * rat2.denominator - rat2.numerator * rat1.denominator;

    Rational result(newNumerator, commonDenominator);
    result.reduce();

    return result;
}

Rational operator*(const Rational& rat1, const Rational& rat2) {
    Rational result(rat1.numerator * rat2.numerator, rat1.denominator * rat2.denominator);
    result.reduce();

    return result;
}

Rational operator/(const Rational& rat1, const Rational& rat2) {
    Rational result(rat1.numerator * rat2.denominator, rat1.denominator * rat2.numerator);
    result.reduce();

    return result;
}

std::ostream& operator<<(std::ostream& out, const Rational& rat) {
    out << rat.numerator << "/" << rat.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Rational& rat) {
    in >> rat.numerator;
    in >> rat.denominator;
    return in;
}

bool operator>(const Rational& rat1, const Rational& rat2) {
    return (rat1 - rat2).numerator > 0;
}

bool operator>=(const Rational& rat1, const Rational& rat2) {
    return (rat1 - rat2).numerator >= 0;
}

bool operator<(const Rational& rat1, const Rational& rat2) {
    return !(rat1 >= rat2);
}

bool operator<=(const Rational& rat1, const Rational& rat2) {
    return !(rat1 > rat2);
}

bool operator==(const Rational& rat1, const Rational& rat2) {
    return (rat1 - rat2).numerator == 0;
}

bool operator!=(const Rational& rat1, const Rational& rat2) {
    return !(rat1 == rat2);
}

void Rational::reduce() {
    long int oneWord = labs(numerator);
    long int twoWord = labs(denominator);

    if (oneWord == 0 || twoWord == 0)
        return;

    while ((max(oneWord, twoWord) % min(oneWord, twoWord)) != 0) {
        oneWord > twoWord ? oneWord = oneWord % twoWord : twoWord = twoWord % oneWord;
    }

    numerator /= min(oneWord, twoWord);
    denominator /= min(oneWord, twoWord);
}

Rational operator""_rat(const char* string, size_t size) {
    long int numerator = 0;
    long int denominator = 0;
    int i = 0;

    while (string[i] != '/') {
        numerator = numerator * 10 + (string[i] - 48);
        ++i;
    }

    ++i;
    while (string[i] != '\0') {
        denominator = denominator * 10 + (string[i] - 48);
        ++i;
    } 

    return Rational(numerator, denominator);
}

static long int max(long int x, long int y) {
    return x > y ? x : y;
}

static long int min(long int x, long int y) {
    return x < y ? x : y;
}