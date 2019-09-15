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
    int remainder = env.index_cont.at(0) % 4;
    int div = (env.index_cont.at(0) - remainder)/4;
    env.world.at(div).at(remainder) = 'W';
}
void Environment::set_gold_position(Environment &env){
    int remainder = env.index_cont.at(1) % 4;
    int div = (env.index_cont.at(1) - remainder)/4;
    env.world.at(div).at(remainder) = 'G';
}
int main(){
    Environment env;
    env.set_rooms(env);
    env.set_index_cont(env);
    env.set_pits_position(env);
    env.set_wumpus_position(env);
    env.set_gold_position(env);
    for(int i=3;i>=0;i--){
        for(int j=0;j<4;j++){
            std::cout<<env.world.at(i).at(j)<<" ";
      }
      std::cout<<std::endl;
    }
  
     std::cout<<std::endl;
    return 0;
}
