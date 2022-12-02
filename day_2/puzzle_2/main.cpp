#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
    std::ifstream myfile("data.txt");
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    std::string input;
    int points = 0;
    std::map<char, int> shape_score = {{'A', 1}, {'B', 2}, {'C', 3}};
    std::map<char, int> round_score = {{'X', 0}, {'Y', 3}, {'Z', 6}};

    std::map<char, char> a_round = {{'X', 'C'}, {'Y', 'A'}, {'Z', 'B'}};
    std::map<char, char> b_round = {{'X', 'A'}, {'Y', 'B'}, {'Z', 'C'}};
    std::map<char, char> c_round = {{'X', 'B'}, {'Y', 'C'}, {'Z', 'A'}};
    std::map<char, std::map<char,char>> round_ends = {{'A',a_round},{'B',b_round},{'C',c_round}};
    

    while (getline(myfile, input)) {
        points += shape_score[round_ends[input[0]][input[2]]] + round_score[input[2]];
    }
    std::cout << "My total score would be -> " << points << std::endl;
    return 0;
}