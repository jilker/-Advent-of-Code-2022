#include <fstream>
#include <iostream>
#include <set>

int main(int argc, char const* argv[]) {
    std::ifstream myfile("data.txt");
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    std::string input;
    std::set<char> items_in_rusksack = {};
    int sum_item_values = 0;
    std::string first_compartment;
    std::string second_compartment;
    while (getline(myfile, input)) {
        first_compartment = input.substr(0, input.length() / 2);
        second_compartment = input.substr(input.length() / 2, input.length());
        items_in_rusksack.insert(first_compartment.begin(), first_compartment.end());
        for (char& item : second_compartment) {
            if (items_in_rusksack.find(item) != items_in_rusksack.end()) {
                // ASCII CODE RULES!
                // A = 65     a = 97
                // a = (1 to 26) A = (27 to 52)
                sum_item_values += (int(item) > 96) ? int(item) - 96 : int(item) - 38;
                break;
            }
        }
        items_in_rusksack.clear();
    }
    std::cout << sum_item_values << std::endl;
}