template <typename T>
class Box {
public:
    Box(T val) : value(val) {}
    T getValue() const { return value; }
private:
    T value;
};

int main() {
    // 实例化一个存储int的Box
    Box<int> intBox(123);
    std::cout << intBox.getValue() << std::endl;  // 输出: 123
    
    // 实例化一个存储double的Box
    Box<double> doubleBox(3.14);
    std::cout << doubleBox.getValue() << std::endl;  // 输出: 3.14
    
    // 实例化一个存储string的Box
    Box<std::string> stringBox("C++");
    std::cout << stringBox.getValue() << std::endl;  // 输出: C++
}
