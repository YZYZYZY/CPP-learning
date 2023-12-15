#include <iostream>

using namespace std;

double division(int a, int b){
    if(b==0){
        //在这里没有指定异常的类型啊？为什么就是onst char*？
        throw "Division by zero condition!";
    }
    return (a/b);
}

int main(){
    int x = 50;
    int y = 0;
    double z = 0;

    try{
        z = division(x, y);
        cout << z << endl;
        //为什么是用const char*而不是char*?不是用string？
    }catch(const char* msg){
        cerr << msg << endl;//cerr是什么？专门用来输出错误信息的？自己抛出的错误与系统错误有区别吗？
    }
    system("pause");
    return 0;
}
