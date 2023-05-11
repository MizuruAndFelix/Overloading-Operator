#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;
class Fraction
{
private:
	int numerator_ = 0;
	int denominator_ = 0;
	int NumeratorDenominator1_ = 0;
	int NumeratorDenominator2_ = 0;
	void saveNumeratorDenominator12(const Fraction& other)
	{
		NumeratorDenominator1_ = this->numerator_ * other.denominator_;
		NumeratorDenominator2_ = other.numerator_ * this->denominator_;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator == (const Fraction& other)
	{
		saveNumeratorDenominator12(other);
		return NumeratorDenominator1_ == Fraction::NumeratorDenominator2_;
	}

	bool operator != (const Fraction& other)
	{
		return NumeratorDenominator1_ != NumeratorDenominator2_;
	}

	bool operator < (const Fraction& other)
	{
		return NumeratorDenominator1_ < NumeratorDenominator2_;
	}

	bool operator > (const Fraction& other)
	{
		return NumeratorDenominator1_ > NumeratorDenominator2_;
	}

	bool operator <= (const Fraction& other)
	{
		return NumeratorDenominator1_ <= NumeratorDenominator2_;
	}

	bool operator >= (const Fraction& other)
	{
		return NumeratorDenominator1_ >= NumeratorDenominator2_;
	}
};

int main()
{
	setlocale(LC_ALL, ".UTF8");
	setlocale(LC_ALL, "Russian"); 
	system("chcp 1251");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;
}