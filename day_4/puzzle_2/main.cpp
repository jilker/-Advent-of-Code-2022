#include <cstdint>
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
    int min_A = 0;
    int max_A = 0;
    int min_B = 0;
    int max_B = 0;
    int overlap = 0;
    while (getline(myfile, input)) {
        std::sscanf(input.c_str(), "%d-%d,%d-%d", &min_A, &max_A, &min_B, &max_B);
        // std::cout << min_A << " " << max_A << " " << min_B << " " << max_B << " " << std::endl;
        if (min_A <= min_B && max_A >= min_B || min_A >= min_B && max_A <= max_B || min_A <= max_B && max_A >= max_B )
            overlap++;
    }
    std::cout << overlap << std::endl;
}