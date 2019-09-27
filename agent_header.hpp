#include "environment.hpp"

class Agent : public Environment
{
public:
    int current_position = 0;
    int prev_position = 0;
    int arrow;
    void move();
    auto sense(int current_pos, std::vector<int> stinch, std::vector<std::vector<int>> breeze);
    void shoot();
    void grab();
    void fill_percept_history(std::vector<std::vector<bool>> &percept_history, std::vector<bool> sense, int current_pos);
    std::vector<std::vector<bool>> make_percept_history();
    std::vector<std::vector<bool>> percept_history;
    std::vector<int> move_direction(std::vector<int> ok);
    int set_arrowposition(int rand, int current_pos);
};