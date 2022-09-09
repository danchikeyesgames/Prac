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
    private:
        long int numerator;
        long int denominator;

        void reduce();
};

int main() {
    Rational num1 = {3, 5};
    Rational num2 = {3, 5};
    Rational num3 = {1, 15};

    std::cout << "+: " << num1 + num2 + num3 << std::endl;
    std::cout << "-: " << num1 - num2 << std::endl;
    std::cout << "*: " << num1 * num2 << std::endl;
    std::cout << "/: " << num1 / num2 << std::endl;

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

static long int max(long int x, long int y) {
    return x > y ? x : y;
}

static long int min(long int x, long int y) {
    return x < y ? x : y;
}