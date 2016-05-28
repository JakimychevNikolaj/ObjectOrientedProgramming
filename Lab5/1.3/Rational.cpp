#include "Rational.h"
#include <utility>
#include <stdexcept>
#include <stdlib.h>


CRational::CRational(int numerator, int denominator)
        : m_numerator(numerator)
        , m_denominator(denominator)
{
    if (denominator < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
    Normalize();
}

int CRational::GetNumerator() const
{
    return m_numerator;
}

int CRational::GetDenominator() const
{
    return m_denominator;
}

void CRational::Normalize()
{
    const int gcd = GCD(abs(m_numerator), m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
    while (b != 0)
    {
        std::swap(a, b);
        b = b % a;
    }
    return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
CRational const CRational::operator -(CRational const &rat) const
{
    auto copyRightVal = rat;
    auto copyLeftVal = *this;//std::pair<int, int>(m_numerator, m_denominator);
    copyRightVal.m_numerator *= m_denominator;
    copyRightVal.m_denominator *= m_denominator;
    copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    copyLeftVal.m_numerator -= copyRightVal.m_numerator;
    auto mostLarDiv = GCD(copyLeftVal.m_numerator, copyLeftVal.m_denominator);
    return { copyLeftVal.m_numerator / int(mostLarDiv), copyLeftVal.m_denominator / int(mostLarDiv) };
}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const CRational::operator <(CRational const &rat) const
{
    auto copyRightVal = rat;
    auto copyLeftVal = *this;//std::pair<int, int>(m_numerator, m_denominator);
    copyRightVal.m_numerator *= m_denominator;
    copyRightVal.m_denominator *= m_denominator;
    copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    return copyLeftVal.m_numerator < copyRightVal.m_numerator;
}

bool const CRational::operator >(CRational const &rat) const
{
    auto copyRightVal = rat;
    auto copyLeftVal = *this;//std::pair<int, int>(m_numerator, m_denominator);
    copyRightVal.m_numerator *= m_denominator;
    copyRightVal.m_denominator *= m_denominator;
    copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    return copyLeftVal.m_numerator > copyRightVal.m_numerator;
}

bool const CRational::operator <=(CRational const &rat) const
{
    auto copyRightVal = rat;
    auto copyLeftVal = *this;//std::pair<int, int>(m_numerator, m_denominator);
    copyRightVal.m_numerator *= m_denominator;
    copyRightVal.m_denominator *= m_denominator;
    copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    return copyLeftVal.m_numerator <= copyRightVal.m_numerator;
}

bool const CRational::operator >=(CRational const &rat) const
{
    auto copyRightVal = rat;
    auto copyLeftVal = *this;//std::pair<int, int>(m_numerator, m_denominator);
    copyRightVal.m_numerator *= m_denominator;
    copyRightVal.m_denominator *= m_denominator;
    copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
    return copyLeftVal.m_numerator >= copyRightVal.m_numerator;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока
//////////////////////////////////////////////////////////////////////////



