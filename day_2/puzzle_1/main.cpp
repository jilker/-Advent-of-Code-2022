#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
    std::ifstream myfile("data.txt");
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    std::string input;
    int points = 0;
    std::map<char, int> shape_score = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    std::map<char, int> a_round = {{'X', 3}, {'Y', 6}, {'Z', 0}};
    std::map<char, int> b_round = {{'X', 0}, {'Y', 3}, {'Z', 6}};
    std::map<char, int> c_round = {{'X', 6}, {'Y', 0}, {'Z', 3}};
    std::map<char, std::map<char,int>> round_score = {{'A',a_round},{'B',b_round},{'C',c_round}};

    while (getline(myfile, input)) {
        points += shape_score[input[2]] + round_score[input[0]][input[2]];
    }
    std::cout << "My total score would be -> " << points << std::endl;
    return 0;
}