#include "agent_header.hpp"


int main()
{
    Agent agent;
    agent.start(agent);
    agent.percept_history = agent.make_percept_history();
    std::vector<bool> test = agent.sense(4, agent.get_stinch, agent.get_breeze);
    std::cout << std::endl
              << test.at(0) << " " << test.at(1) << std::endl;
    agent.fill_percept_history(agent.percept_history, test, 4);
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << agent.percept_history.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}