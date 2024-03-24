class MyClass {
public:
    MyClass(int value) : value_(value) { }
    void printValue() const { std::cout << value_ << std::endl; }
private:
    int value_;
};

int main() {
    // 分配足够存储MyClass实例的内存
    char buffer[sizeof(MyClass)];

    // 使用placement new在buffer指定的地址上构造MyClass实例
    MyClass* instance = new (buffer) MyClass(42);

    // 使用对象
    instance->printValue();

    // 显式调用析构函数
    instance->~MyClass();

    return 0;
}
