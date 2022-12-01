#include <bits/stdc++.h>

void includeInPodium(int candidate, std::array<int, 3>& podium) {
    if (podium[2] > candidate) {
        return;
    } else {
        podium[2] = candidate;
    }
    if (podium[1] > candidate) {
        return;
    } else {
        podium[2] = podium[1];
        podium[1] = candidate;
    }
    if (podium[0] > candidate) {
        return;
    } else {
        podium[1] = podium[0];
        podium[0] = candidate;
    }
}
int main(int argc, char const* argv[]) {
    std::ifstream myfile("data.txt");
    std::string input;
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
    }
    std::array<int, 3> podium = {0, 0, 0};
    int count = 0;
    while (getline(myfile, input)) {
        if (input.size() == 0) {
            includeInPodium(count, podium);
            count = 0;
            continue;
        }
        count += std::stoi(input);
    }
    std::cout << "Sum of max calories Top 3 elf -> " << std::accumulate(podium.begin(), podium.end(), (int)0) << std::endl;
    return 0;
}