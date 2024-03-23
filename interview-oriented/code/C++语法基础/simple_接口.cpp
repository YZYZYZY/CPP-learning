#include <iostream>
using namespace std;


class Shape{
public:
    virtual void draw() = 0;//纯虚函数
    virtual ~Shape(){}//虚析构函数
};

class Circle:public Shape{
public:
    void draw(){
        cout<<"draw a circle"<<endl;
    }
};

class Rectangle:public Shape{
public:
    void draw(){
        cout<<"draw a rectangle"<<endl;
    }
};


int main(){
    Shape *shape1 = new Circle();
    Shape *shape2 = new Rectangle();
    shape1->draw();
    shape2->draw();
    delete shape1;
    delete shape2;
    return 0;
}