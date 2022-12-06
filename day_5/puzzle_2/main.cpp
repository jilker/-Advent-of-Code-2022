#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

int main(int argc, char const* argv[]) {
    std::ifstream myfile("data.txt");
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    std::string input;
    std::vector<std::string> vector_of_initial_stacks;
    std::vector<size_t> pos_piles;
    while (getline(myfile, input)) {
        if (input.size() == 0) {
            break;
        }
        vector_of_initial_stacks.push_back(input);
    }
    size_t pos;
    while ((pos = (vector_of_initial_stacks.end() - 1)->find(static_cast<char>('0' + pos_piles.size() + 1))) != std::string::npos) {
        pos_piles.push_back(pos);
    }
    vector_of_initial_stacks.pop_back();
    std::vector<std::stack<char>> stack_piles(pos_piles.size());
    for (auto line_input = vector_of_initial_stacks.rbegin(); line_input != vector_of_initial_stacks.rend(); line_input++) {
        for (int it = 0; it != pos_piles.size(); it++) {
            if (line_input->at(pos_piles[it]) != ' ')
                stack_piles[it].push(line_input->at(pos_piles[it]));
        }
    }
    std::for_each(stack_piles.begin(), stack_piles.end(), [](auto& n) { std::cout << n.top() << std::endl; });

    int amount_stack = 0;
    int from_pile = 0;
    int to_pile = 0;
    std::stack<char> crane;
    while (getline(myfile, input)) {
        std::cout << input << std::endl;
        std::sscanf(input.c_str(), "move %d from %d to %d", &amount_stack, &from_pile, &to_pile);
        for (auto unused = 0; unused < amount_stack; unused++) {
            crane.push(stack_piles[from_pile - 1].top());
            stack_piles[from_pile - 1].pop();
        }
        while (crane.size() != 0) {
            stack_piles[to_pile - 1].push(crane.top());
            crane.pop();
        }
    }
    std::for_each(stack_piles.begin(), stack_piles.end(), [](auto& n) { std::cout << n.top(); });
    std::cout << std::endl;
}