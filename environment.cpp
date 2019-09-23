#include "environment.h"
void Environment::set_rooms(Environment &env){
    for(int i=0;i<4;i++){
        std::vector<char> push_vector;
        for(int j=0;j<4;j++){
            push_vector.push_back('0');
      }
      env.world.push_back(push_vector);
    }
}
void Environment::set_index_cont(Environment &env){
    srand(time(NULL));
    for(int i=0; i<5; i++){
        int pit = rand() % 15 + 1;
        env.it = std::find (env.index_cont.begin(), env.index_cont.end(), pit); 
        if (env.it != env.index_cont.end() || pit==4 ||pit==1) 
        { 
            i--;
        } 
        else{
            env.index_cont.push_back(pit);  
        }    
    }
}
void Environment::set_pits_position(Environment &env){
    srand(time(NULL));
    int index_cont_size = env.index_cont.size();
    for(int i=0; i<3; i++){
        int pit = rand() % index_cont_size;
        env.it = std::find (env.pits_cont.begin(), env.pits_cont.end(), env.index_cont.at(pit)); 
        if (env.it != env.pits_cont.end()) 
        { 
            i--;
        } 
        else{
            env.pits_cont.push_back(env.index_cont.at(pit)); 
            env.index_cont.erase(std::remove(env.index_cont.begin(), env.index_cont.end(), env.index_cont.at(pit)), env.index_cont.end()); 
            index_cont_size--;
        }    
       
    }
    for(int i=0;i<env.pits_cont.size();i++){
        int remainder = env.pits_cont.at(i) % 4;
        int div = (env.pits_cont.at(i) - remainder)/4;
        env.world.at(div).at(remainder) = 'p';
    }
}
void Environment::set_wumpus_position(Environment &env){
    env.wumpus_cont = env.index_cont.at(0);
    int remainder = env.wumpus_cont % 4;
    int div = (env.wumpus_cont - remainder)/4;
    env.world.at(div).at(remainder) = 'W';
}
void Environment::set_gold_position(Environment &env){
    env.gold_cont = env.index_cont.at(1);
    int remainder = env.gold_cont % 4;
    int div = (env.gold_cont - remainder)/4;
    env.world.at(div).at(remainder) = 'G';
}
void Environment::print_world(Environment &env){
    for(int i=3;i>=0;i--){
        for(int j=0;j<4;j++){
            std::cout<<env.world.at(i).at(j)<<" ";
       }
      std::cout<<std::endl;
    }
}  
std::vector<int> Environment::create_adjacent(int x){
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
void Environment::set_stinch(Environment &env){
     env.stinch = env.create_adjacent(env.wumpus_cont);
}

void Environment::set_breeze(Environment &env){
for(int j=0;j<env.pits_cont.size();j++){
        std::vector<int> pit_adj_cont = env.create_adjacent(env.pits_cont.at(j));
        env.breeze.push_back(pit_adj_cont);
        pit_adj_cont.clear();
    }
     
}
int main(){
    Environment env;
    env.set_rooms(env);
    env.set_index_cont(env);
    env.set_pits_position(env);
    env.set_wumpus_position(env);
    env.set_gold_position(env);
    env.print_world(env);
    env.set_stinch(env);
    env.set_breeze(env);
    std::cout<<std::endl;
    return 0;
}
