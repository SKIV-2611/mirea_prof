#include <iostream>
using namespace std;

class Polynomial2
{
private:
	//коэффициенты многочлена второй степени: coef0 + x * coef1 + x^2 * coef2
	double coef0;
	double coef1;
	double coef2;
public:
	//конструктор без параметров: Polynomial P;
	Polynomial2() { cout << "\nConstructor0 is working\n"; coef0 = coef1 = coef2 = 0; }
	Polynomial2(double c0, double c1, double c2) { 
		cout << "\nConstructor3 is working\n";
		coef2 = c2;
		coef1 = c1;
		coef0 = c0;
	}
	Polynomial2(double c) {
		cout << "\nConstructor1 is working\n";
		coef2 = 0;
		coef1 = 0;
		coef0 = c;
	}

	Polynomial2(double c0, double c1) {
		cout << "\nConstructor2 is working\n";
		coef0 = c0;
		coef1 = c1;
		coef2 = 0;
	}
	Polynomial2(const Polynomial2& p) {
		cout << "\nConstructor of copies is working\n";
		coef0 = p.coef0;
		coef1 = p.coef1;
		coef2 = p.coef2;
	}
	//деструктор
	~Polynomial2() { cout << "\nDestructor is working\n"; }

	//геттеры и сеттеры
	double getCoef0() { return coef0; }
	double getCoef1() { return coef1; }
	double getCoef2() { return coef2; }

	void setCoef0(double value) { coef0 = value; }
	void setCoef1(double value) { coef1 = value; }
	void setCoef2(double value) { coef2 = value; }

	//вывод

	void print() { cout << coef2 << "x^2 + " << coef1 << "x + " << coef0<< "\n"; }

	Polynomial2 operator +(Polynomial2 p1) {
		Polynomial2 result(coef0, coef1, coef2);
		result.coef0 += p1.coef0;
		result.coef1 += p1.coef1;
		result.coef2 += p1.coef2;
		return result;
	}
	Polynomial2 operator +(double c) {
		Polynomial2 result(*this);
		result.coef0 += c;
		return result;
	}
	Polynomial2 operator +=(Polynomial2 p) {
		coef0 += p.coef0;
		coef1 += p.coef1;
		coef2 += p.coef2;
		return *this;
	}
	Polynomial2 operator -(Polynomial2 p1) {
		Polynomial2 result(*this);
		result.coef0 -= p1.coef0;
		result.coef1 -= p1.coef1;
		result.coef2 -= p1.coef2;
		return result;
	}
	Polynomial2 operator -=(Polynomial2 p) {
		coef0 -= p.coef0;
		coef1 -= p.coef1;
		coef2 -= p.coef2;
		return *this;
	}
	Polynomial2 operator *(double c) {
		Polynomial2 result(*this);
		result.coef0 *= c;
		result.coef1 *= c;
		result.coef2 *= c;
		return result;
	}
	Polynomial2 operator -() {
		return Polynomial2(-coef0, -coef1, -coef2);
	}

	Polynomial2 operator ++(int) {

	}
	bool operator ==(Polynomial2 p) {
		return (coef0 == p.coef0) && (coef1 == p.coef1) && (coef2 == p.coef2);
	}

	bool operator !=(Polynomial2 p) {
		return coef0 != p.coef0 || coef1 != p.coef1 || coef2 != p.coef2;
	}
	friend Polynomial2 operator+(double c, Polynomial2 p2);

	double& operator[](int index) {
		switch (index) {
		    case 0: 
			    return coef0;
			case 1:
				return coef1;
			case 2:
				return coef2;
		}
	}
	double operator()(double x) {
		return x * x * coef2 + x * coef1 + coef0;
	}
};

Polynomial2 operator+(double c, Polynomial2 p2) {
	Polynomial2 result(p2);
	result.coef0 += c;
	return result;
}


int main()
{
	Polynomial2 p1 = Polynomial2();
	p1.setCoef0(1);
	p1.setCoef1(1);
	p1.setCoef2(1);
	cout << "p1 = ";
	p1.print();
	Polynomial2 p2 = Polynomial2(2);
	cout << "p2 = ";
	p2.print();
	Polynomial2 p3 = Polynomial2(1, 2, 3);
	cout << "p3 = ";
	p3.print();
	Polynomial2 p4 = p1 + p3;
	cout << "p4 = p1 + p3 = ";
	p4.print();
	Polynomial2 p5 = p4 * 5;
	cout << "p5 = 5p4 = ";
	p5.print();
	Polynomial2 p6 = p4 - p2;
	cout << "p6 = p4 - p2 = ";
	p6.print();
	p6 = p6 - p5;
	cout << "p6 = p6 - p5 = ";
	p6.print();
	return 0;
}