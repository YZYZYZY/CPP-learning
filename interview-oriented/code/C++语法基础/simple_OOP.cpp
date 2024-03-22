#include <iostream>
using namespace std;

//基类
class Animal{
    public:
        void eat(){
            cout << "This animal eats" << endl;
        }
        virtual void speak(){
            cout << "This animal speaks" << endl;
        }
};

//派生类
class Dog : public Animal{
    public:
        void eat(){
            cout << "Dog eats bone" << endl;
        }
        void speak() override{
            cout << "Dog barks" << endl;
        }
};

int main(){
    Dog mydog;
    mydog.eat();.//没有使用虚函数，但是也算运行时多态
    mydog.speak();

    Animal *p = &mydog;//运行时多态
    p->speak();

    return 0;
}