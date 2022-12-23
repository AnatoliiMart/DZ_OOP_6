#include<iostream>
#include<Windows.h>

class ComplexNumb
{
public:
	ComplexNumb() : Re(0), Im(0) {} 
	ComplexNumb(int re, int im): Re(re), Im(im){}
	ComplexNumb& operator +(const ComplexNumb& obj)
	{
		this->Re += obj.Re;
		this->Im += obj.Im;
		return *this;
	}
	ComplexNumb& operator *(const ComplexNumb obj)
	{
		int ReTmp = this->Re;
		int ImTmp = this->Im;
		this->Re = (ReTmp * obj.Re) - (ImTmp * obj.Im);
		this->Im = (ImTmp * obj.Re) + (ReTmp * obj.Im);
		return *this;
	}

	friend std::istream& operator >> (std::istream& is, ComplexNumb& obj);
	friend std::ostream& operator << (std::ostream& os, const ComplexNumb& obj);
	~ComplexNumb()
	{

	}
private:
	int Re;
	int Im;
};
std::istream& operator>>(std::istream& is, ComplexNumb& obj)
{
	std::cout << "Enter the real part of complex numb: ";
	is >> obj.Re;
	std::cout << std::endl;
	
	std::cout << "Enter the imagine part of complex numb: ";
	is >> obj.Im;
	std::cout << std::endl;

	return is;
}
std::ostream& operator << (std::ostream& os, const ComplexNumb& obj)
{
	os << obj.Re << "+" << obj.Im << "i" << std::endl;
	return os;
}
int main()
{
	ComplexNumb obj (44, 56);
	std::cout << "First complex number: " << obj;

	ComplexNumb obj1(35, 17);
	std::cout << "Second complex number: " << obj1;

	obj * obj1;
	std::cout << "Multiplication result: " << obj;
	std::cout << "---------------------------------" << std::endl;
	ComplexNumb obj2(12, 33);
	std::cout << "First complex number: " << obj2;

	ComplexNumb obj3(11, 11);
	std::cout << "Second complex number: " << obj3;

	obj2 + obj3; 
	std::cout << "Addition result: " << obj2;
	return 0;
}

