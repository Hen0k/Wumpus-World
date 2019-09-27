#include "agent_header.hpp"

//0:wumpus 1:pit 2:gold 3:stinch 4:breeze 5:ok 6:visited
std::vector<std::vector<bool>> Agent::make_percept_history()
{
    std::vector<std::vector<bool>> percept_history;
    for (int i = 0; i < 16; i++)
    {
        std::vector<bool> row;
        for (int i = 0; i < 7; i++)
        {
            row.push_back(false);
        }
        percept_history.push_back(row);
    }
    percept_history.at(0).at(5) = true;
    percept_history.at(0).at(6) = true;
    return percept_history;
}
void Agent::fill_percept_history(std::vector<std::vector<bool>> &percept_history, std::vector<bool> sense, int current_pos)
{
    std::vector<int> adjacent = create_adjacent(current_pos);
    percept_history.at(current_pos).at(6) = true;
    if (sense.at(0) == true)
    {
        percept_history.at(current_pos).at(3) = true;
        for (int i = 0; i < adjacent.size(); i++)
        {
            if(percept_history.at(i).at(6) == false)
                percept_history.at(adjacent.at(i)).at(0) = true;
        }
    }
    if (sense.at(1) == true)
    {
        percept_history.at(current_pos).at(4) = true;
        for (int i = 0; i < adjacent.size(); i++)
        {
            if(percept_history.at(i).at(6) == false)
                percept_history.at(adjacent.at(i)).at(1) = true;
        }
    }
    if (!sense.at(0) && !sense.at(1))
    {
        for (int i = 0; i < adjacent.size(); i++)
        {
            std::cout << "Test" << std::endl;
            percept_history.at(adjacent.at(i)).at(5) = true;
        }
    }
}
int set_arrowposition(int rand, int current_pos)
{
    return rand - current_pos;
}
std::vector<int> move_direction(std::vector<int> ok, std::vector<std::vector<bool>> &percept_history)
{
    std::vector<int> unvisited_ok;
    for (int i = 0; i < ok.size(); i++)
    {
        if (percept_history.at(ok.at(i)).at(6) == false)
        {
            unvisited_ok.push_back(ok.at(i));
        }
    }
    return unvisited_ok;
}
void Agent::set_agent_position(std::vector<std::vector<char>> &world,int current_position,int prev_position)
{
    world.at(prev_position/4).at(prev_position%4) = '0';
    world.at(current_position/4).at(current_position%4) = '@';
}
void Agent::move(int &current_position,int &prev_position,std::vector<std::vector<bool>> &percept_history,int gold_cont)
{
    std::vector<int> adjacent = create_adjacent(current_position);
    std::vector<int> ok;
    std::vector<int> unvisited_ok;
    int random;
    srand(time(NULL));
    percept_history.at(current_position).at(6) == true; //Make current position visited
    for (int i = 0; i < adjacent.size(); i++)
    {
        if (percept_history.at(adjacent.at(i)).at(5) == true)
        {
            ok.push_back(adjacent.at(i)); //Add adjacent room to ok if ok field in percept history is true
        }
    }
    unvisited_ok = move_direction(ok,percept_history);
    if (!unvisited_ok.empty())
    {
        std::cout << "Test 2" << std::endl;
        random = rand() % unvisited_ok.size();
        arrow = set_arrowposition(unvisited_ok.at(random), current_position);
        prev_position = current_position;
        current_position += arrow;
    }
    else
    {
        random = rand() % ok.size();
        arrow = set_arrowposition(ok.at(random), current_position);
        prev_position = current_position;
        current_position += arrow;
    }
    std::cout << "Current Position == " << current_position << std::endl;
    ok.clear();
    if (current_position == gold_cont)
    {
        std::cout << "You got the gold!!!" << std::endl;
    }
}

auto Agent::sense(int current_pos, std::vector<int> stinch, std::vector<std::vector<int>> breeze)
{
    /*sense_cont.at(0) for stinch
     * sense_cont.at(1) for breeze*/
    std::vector<bool> sense_cont;
    sense_cont.push_back(false);
    sense_cont.push_back(false);
    std::vector<int>::iterator it;
    it = std::find(stinch.begin(), stinch.end(), current_pos);
    if (it != stinch.end())
    {
        sense_cont.at(0) = true;
    }
    for (int i = 0; i < breeze.size(); i++)
    {
        it = std::find(breeze.at(i).begin(), breeze.at(i).end(), current_pos);
        if (it != breeze.at(i).end())
        {
            sense_cont.at(1) = true;
            break;
        }
    }
    return sense_cont;
}


