#include <iostream>
using std::cin, std::cout, std::endl;

#include <string>
using std::string, std::to_string;

#include <unordered_map>
using std::unordered_map;

int main() {
    int total = 0;
    string roman;
    unordered_map<char, int> dict = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
    };

    cout << "Enter roman numeral: ";
    getline(std::cin, roman);

    for (int i = 0; i < roman.size(); i++) {
        if (i < roman.size()-1 && dict.at(roman[i+1]) > dict.at(roman[i])) {
            total -= dict.at(roman[i]);
        } else {
            total += dict.at(roman[i]);
        }
    }

    cout << total << endl;

    return 0;
}
