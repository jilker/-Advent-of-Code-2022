#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#define characters 4
int main(int argc, char const* argv[]) {
    std::ifstream myfile("data.txt");
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    std::string input;
    std::set<char> marker;
    while (getline(myfile, input)) {
        for (auto it = input.begin(); it != input.end(); it++) {
            marker.insert(it, it + characters);
            // std::cout << marker.size() << std ::endl;
            if (marker.size() != characters) {
                marker.clear();
            } else {
                std::for_each(marker.begin(), marker.end(), [](auto& n) { std::cout << n; });
                std::cout << it - input.begin() + characters << std::endl;
                break;
            }
        }
    }
}