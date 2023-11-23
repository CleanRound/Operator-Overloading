#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cerr << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0.0) {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    friend ostream& operator<<(ostream& os, const Complex& comp) {
        os << comp.real << " + " << comp.imag << "i";
        return os;
    }
};

int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction sum_frac = frac1 + frac2;
    Fraction diff_frac = frac1 - frac2;
    Fraction prod_frac = frac1 * frac2;
    Fraction div_frac = frac1 / frac2;

    cout << "Fractions:" << endl;
    cout << "Sum: " << sum_frac << endl;
    cout << "Difference: " << diff_frac << endl;
    cout << "Product: " << prod_frac << endl;
    cout << "Quotient: " << div_frac << endl;
    cout << endl;

    Complex comp1(1.0, 2.0);
    Complex comp2(2.0, 3.0);

    Complex sum_comp = comp1 + comp2;
    Complex diff_comp = comp1 - comp2;
    Complex prod_comp = comp1 * comp2;
    Complex div_comp = comp1 / comp2;

    cout << "Complex:" << endl;
    cout << "Sum: " << sum_comp << endl;
    cout << "Difference: " << diff_comp << endl;
    cout << "Product: " << prod_comp << endl;
    cout << "Quotient: " << div_comp << endl;

    return 0;
}
