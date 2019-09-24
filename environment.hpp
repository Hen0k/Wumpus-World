#include "environment_header.hpp"


std::vector<std::vector<char>> Environment::set_rooms(std::vector<int> pits,int w,int g){
    std::vector<std::vector<char>> world;

    for(int i=0;i<4;i++){
        std::vector<char> push_vector;
        for(int j=0;j<4;j++){
            push_vector.push_back('0');
      }
      world.push_back(push_vector);
    }
    for(int i=0;i<pits.size();i++){
        world.at(pits.at(i) / 4).at(pits.at(i) % 4) = 'P'; 
    }
    world.at(w / 4).at(w % 4) = 'W'; 
    world.at(g / 4).at(g % 4) = 'G'; 
    return world;
}

std::vector<int> Environment::set_index_cont(){
    srand(time(NULL));
    std::vector<int> index_cont;
    std::vector<int>::iterator it; 
    for(int i=0; i<5; i++){
        int pit = rand() % 15 + 1;
        it = std::find (index_cont.begin(), index_cont.end(), pit); 
        if (it != index_cont.end() || pit==4 ||pit==1) 
        { 
            i--;
        } 
        else{
            index_cont.push_back(pit);  
        }    
    }
    return index_cont;
}
std::vector<int> Environment::set_pits_position(std::vector<int> index_cont){
    std::vector<int> pits_cont;
    pits_cont.push_back(index_cont.at(0));
    pits_cont.push_back(index_cont.at(1));
    pits_cont.push_back(index_cont.at(2));
    return pits_cont;
}
int Environment::set_wumpus_position(std::vector<int> index_cont){
    return index_cont.at(3);
}
int Environment::set_gold_position(std::vector<int> index_cont){
    return index_cont.at(4);
}
void Environment::print_world(std::vector<std::vector<char>> world){
    for(int i=3;i>=0;i--){
        for(int j=0;j<4;j++){
            std::cout<<world.at(i).at(j)<<" ";
       }
      std::cout<<std::endl;
    }
}  
 
std::vector<int> create_adjacent(int x){
    std::vector<int> adjacent;
    if(x < 12)
        adjacent.push_back(x + 4);                 
    if(x > 3)
        adjacent.push_back(x - 4);             
    if(x % 4 != 0)
        adjacent.push_back(x - 1);          
    if(x % 4!=3)
        adjacent.push_back(x + 1);     
    return adjacent;           
}
std::vector<int> Environment::set_stinch(int wumpus_cont){
     std::vector<int> stinch = create_adjacent(wumpus_cont);
     return stinch;
}

std::vector<std::vector<int>> Environment::set_breeze(std::vector<int> pits_cont){
    std::vector<std::vector<int>> breeze;
    for(int j=0;j<pits_cont.size();j++){
        std::vector<int> pit_adj_cont = create_adjacent(pits_cont.at(j));
        breeze.push_back(pit_adj_cont);
        pit_adj_cont.clear();
    }
    return breeze;  
}

void Environment::start(Environment &env){
    std::vector<int> index_cont = env.set_index_cont();
    std::vector<int> pits_cont = env.set_pits_position(index_cont);
    int wumpus_cont = env.set_wumpus_position(index_cont);
    int gold_cont = env.set_gold_position(index_cont);
    std::vector<std::vector<char>> world = env.set_rooms(pits_cont,wumpus_cont,gold_cont);
    env.print_world(world);
    env.get_stinch = env.set_stinch(wumpus_cont);
    env.get_breeze = env.set_breeze(pits_cont);
    std::cout<<std::endl;   
}

