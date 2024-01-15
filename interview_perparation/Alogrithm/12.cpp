//整数转罗马数字

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string intToRoman(int num) {
    const std::vector<std::pair<int, std::string>> valueSymbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string roman;
    for (const auto& valueSymbol : valueSymbols) {
        while (num >= valueSymbol.first) {
            num -= valueSymbol.first;
            roman += valueSymbol.second;
        }
    }
    return roman;
}

int main(){
    int num = 1994;
    cout << intToRoman(num) << endl;
    system("pause");
    return 0;
}