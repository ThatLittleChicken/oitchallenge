#include <iostream>
using std::cin, std::cout, std::endl;

#include <string>
using std::string, std::to_string;

#include <unordered_map>
using std::unordered_map;

int main() {
    string input;
    string roman;
    unordered_map<int, char> dict = {
            {1000, 'M'},
            {500, 'D'},
            {100, 'C'},
            {50, 'L'},
            {10, 'X'},
            {5, 'V'},
            {1, 'I'}
    };

    cout << "Enter decimal: ";
    getline(cin, input);

    int len = input.size();
    int num = stoi(input);

    for (int i = 0; i < len ; i++) {
        int zeros = pow(10,len - i - 1);
        int n = num / zeros;

        if (n == 0) {
            continue;
        } else if (n == 9) {
            roman += dict.at(zeros);
            roman += dict.at(zeros*10);
            n = 0;
        } else if (n == 4) {
            roman += dict.at(zeros);
            roman += dict.at(zeros*5);
            n = 0;
        } else if (n >= 5) {
            roman += dict.at(zeros*5);
            n -= 5;
        }
        for (; n > 0; n--) {
            roman += dict.at(zeros);
        }
        num = num % zeros;
    }

    cout << roman << endl;

    return 0;
}
