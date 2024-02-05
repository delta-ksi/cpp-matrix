#include "Complex.h"

////////////////////////////////////////////////////////////
Complex::Complex() :
m_real(0),
m_imag(0)
{ }


////////////////////////////////////////////////////////////
Complex::Complex(double Real, double Imag) :
m_real(Real),
m_imag(Imag)
{ }


////////////////////////////////////////////////////////////
Complex::Complex(const Complex& Comp) :
m_real(Comp.m_real),
m_imag(Comp.m_imag)
{ }


////////////////////////////////////////////////////////////
Complex::Complex(double Var) :
m_real(Var),
m_imag(0)
{ }


////////////////////////////////////////////////////////////
Complex::Complex(int Var) :
m_real(Var),
m_imag(0)
{ }


////////////////////////////////////////////////////////////
double Complex::r() const
{ return m_real; }


////////////////////////////////////////////////////////////
double Complex::i() const
{ return m_imag; }


////////////////////////////////////////////////////////////
double Complex::abs() const
{ return sqrt(m_real * m_real + m_imag * m_imag); }


////////////////////////////////////////////////////////////
Complex Complex::c() const
{
	Complex result(m_real, -m_imag);
	return result;
}


////////////////////////////////////////////////////////////
Complex operator+(const Complex& LComp, const Complex& RComp)
{
	Complex result(LComp.r() + RComp.r(), LComp.i() + RComp.i());
	return result;
}


////////////////////////////////////////////////////////////
Complex operator-(const Complex& LComp, const Complex& RComp)
{
	Complex result(LComp.m_real - RComp.m_real, LComp.m_imag - RComp.m_imag);
	return result;
}


////////////////////////////////////////////////////////////
Complex operator*(const Complex& LComp, const Complex& RComp)
{
	Complex result(LComp.m_real * RComp.m_real - LComp.m_imag * RComp.m_imag, LComp.m_real * RComp.m_imag + LComp.m_imag * RComp.m_real);
	return result;
}


////////////////////////////////////////////////////////////
Complex operator/(const Complex& LComp, const Complex& RComp)
{
	double  mod2 = RComp.m_real * RComp.m_real + RComp.m_imag * RComp.m_imag;
	Complex result((LComp.m_real * RComp.m_real + LComp.m_imag * RComp.m_imag) / mod2, (LComp.m_real * RComp.m_imag - LComp.m_imag * RComp.m_real) / mod2);
	return result;
}


////////////////////////////////////////////////////////////
Complex& operator+= (const Complex& LComp, const Complex& RComp)
{
	Complex result(LComp.m_real + RComp.m_real, LComp.m_imag + RComp.m_imag);
	return result;
}


////////////////////////////////////////////////////////////
Complex& operator-= (const Complex& LComp, const Complex& RComp)
{
	Complex result(LComp.m_real - RComp.m_real, LComp.m_imag - RComp.m_imag);
	return result;
}


////////////////////////////////////////////////////////////
Complex& operator*= (const Complex& LComp, const Complex& RComp)
{
	Complex result(LComp.m_real * RComp.m_real - LComp.m_imag * RComp.m_imag, LComp.m_real * RComp.m_imag + LComp.m_imag * RComp.m_real);
	return result;
}


////////////////////////////////////////////////////////////
Complex& operator/= (const Complex& LComp, const Complex& RComp)
{
	double  mod2 = RComp.m_real * RComp.m_real + RComp.m_imag * RComp.m_imag;
	Complex result((LComp.m_real * RComp.m_real + LComp.m_imag * RComp.m_imag) / mod2, (LComp.m_real * RComp.m_imag - LComp.m_imag * RComp.m_real) / mod2);
	return result;
}


////////////////////////////////////////////////////////////
bool operator!= (const Complex& LComp, const Complex& RComp)
{
	if ((LComp.m_real == RComp.m_real) && (LComp.m_imag == RComp.m_imag))
		return false;
	else
		return true;
}


////////////////////////////////////////////////////////////
std::istream& operator>> (std::istream& in, Complex& z)
{
	std::cout << "\nEnter real part: ";
	in >> z.m_real;
	std::cout <<   "Enter imag part: ";
	in >> z.m_imag;

	return in;
}


////////////////////////////////////////////////////////////
std::ostream& operator<< (std::ostream& out, const Complex& z)
{
	out << std::setiosflags(std::ios::fixed)
		<< std::setiosflags(std::ios::showpoint)
		<< std::setprecision(2)
		<< std::setw(7)
		<< z.m_real;

	if (z.m_imag < 0) out << " - ";
	if (z.m_imag >= 0) out << " + ";

	out << abs(z.m_imag)
		<< "i";

	return out;
}