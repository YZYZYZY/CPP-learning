#include <iostream>

class Complex{
    public:
    double real, imag;
    Complex(double r=0.0, double i=0.0): real(r), imag(i) {}

    // 重载运算符+,实现复数加法
    Complex operator+ (const Complex &c2) const {
        return Complex(real + c2.real, imag + c2.imag);
    }

    // 重载<<运算符，实现对复数的输出
    friend std::ostream& operator<< (std::ostream &out, const Complex &c){ // 友元函数? 
        out << c.real << "+" << c.imag << "i";
        return out;
    }
};

int main(){
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3 = c1 + c2;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;
    return 0;
}