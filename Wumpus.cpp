#include "agent.hpp"


int main()
{
    Agent agent;
    agent.start(agent);
    agent.percept_history = agent.make_percept_history();
    agent.set_agent_position(agent.world,agent.current_position,agent.prev_position);
    agent.print_world(agent.world);
    while(1)
    {
    std::cout<<"press any key"<<std::endl;
    char c;
    std::cin>>c;
    std::vector<bool> sense = agent.sense(agent.current_position, agent.get_stinch, agent.get_breeze);
    agent.fill_percept_history(agent.percept_history, sense, agent.current_position);
    agent.move(agent.current_position,agent.prev_position,agent.percept_history,agent.gold_cont);
    agent.set_agent_position(agent.world,agent.current_position,agent.prev_position);
    agent.print_world(agent.world);
    }
    return 0;
}
