//下面的实例中，基类Shape被派生为两个类
#include <iostream>
using namespace std;

// 基类
class Shape
{
    protected:
        int width;
        int height;
    public:
        //构造函数
        Shape(int a=0, int b=0)
        {
            width = a;
            height = b;
        };
        //虚函数
        virtual int area()
        {
            cout << "Parent class area :" <<endl;
            return 0;
        };
};

// 派生类
class Rectangle: public Shape
{
    public:
        //构造函数 这是哪种写法？为什么要:Shape(a, b)? 初始化列表？
        Rectangle(int a=0, int b=0):Shape(a, b){}
        int area()
        {
            cout << "Rectangle class area :" <<endl;
            return (width * height);
        };
};

class Triangle: public Shape
{
    public:
        //构造函数
        Triangle(int a=0, int b=0):Shape(a, b){}
        int area()
        {
            cout << "Triangle class area :" <<endl;
            return (width * height / 2);
        };
};

int main()
{
    Shape *shape;
    //这里调用的是Shape的构造函数？怎么调用派生类自己的构造函数？
    Rectangle rec(10,7);
    Triangle  tri(10,5);

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();

    return 0;
}
