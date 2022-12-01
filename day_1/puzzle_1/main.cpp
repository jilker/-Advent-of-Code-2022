#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
    std::ifstream myfile("data.txt");
    std::string input;
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
    }
    int max = 0;
    int count = 0;
    while (getline(myfile, input)) {
        if (input.size() == 0) {
            if (max < count) {
                max = count;
            }
            count = 0;
            continue;
        }
        count += std::stoi(input);
    }
    std::cout << "Max calories elf -> " << max << std::endl;
    return 0;
}