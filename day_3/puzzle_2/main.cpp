#include <fstream>
#include <iostream>
#include <set>

// ASCII CODE RULES!
// A = 65     a = 97
// a = (1 to 26) A = (27 to 52)
inline int priority_value(char _val) { return (int(_val) > 96) ? int(_val) - 96 : int(_val) - 38; }

int main(int argc, char const* argv[]) {
    std::ifstream myfile("data.txt");
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    std::string input;
    std::set<char> first_elf = {};
    std::set<char> repeated_items = {};
    int sum_item_values = 0;
    int number_elf = 0;
    while (getline(myfile, input)) {
        switch (number_elf) {
            case 0:
                first_elf.insert(input.begin(), input.end());
                number_elf++;
                break;
            case 1:
                for (char& item : input) {
                    if (first_elf.find(item) != first_elf.end()) {
                        repeated_items.insert(item);
                    }
                }
                number_elf++;
                break;
            case 2:
                for (char& item : input) {
                    if (repeated_items.find(item) != repeated_items.end()) {
                        sum_item_values += priority_value(item);
                        break;
                    }
                }
                first_elf.clear();
                repeated_items.clear();
                number_elf = 0;
                break;
            default:
                break;
        }
    }
    std::cout << sum_item_values << std::endl;
}