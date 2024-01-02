#include <iostream>
#include <exception>
using namespace std;

//通过继承exception类来自定义异常类为什么要用struct而不是class？
struct MyException : public exception{
    //这些都是什么意思？函数用throw()声明了异常类型？
    const char* what() const throw(){
        return "C++ Exception";
    }
};

int main(){
    try{
        throw MyException();
    }catch(MyException& e){
        cout << "MyException caught" << endl;
        cout << e.what() << endl;
    }catch(exception& e){
        //其他的异常类都是继承exception类的？
        //这里的exception& e是什么意思？是把e当成了一个exception类的对象？
        //为什么这里的e.what()是不一样的？
        cout << "Other exception" << endl;
    }
    system("pause");
    return 0;
}