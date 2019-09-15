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

void Environment::set_stinch(Environment &env){
     env.stinch.push_back(env.wumpus_cont + 4);
     env.stinch.push_back(env.wumpus_cont - 4);
     env.stinch.push_back(env.wumpus_cont + 1);
     env.stinch.push_back(env.wumpus_cont - 1);
     int size = 4;
     for(int i=0;i<size;i++){
         if(env.stinch.at(i) < 0 || env.stinch.at(i) > 15){
             env.stinch.erase(std::remove(env.stinch.begin(), env.stinch.end(), env.stinch.at(i)), env.stinch.end());
             size--;
         }
         if(env.wumpus_cont % 4==0 && env.stinch.at(i)%4==3){
             env.stinch.erase(std::remove(env.stinch.begin(), env.stinch.end(), env.stinch.at(i)), env.stinch.end());
             size--;
         }
         if((env.wumpus_cont+1) % 4==0 && env.stinch.at(i)%4==0){
             env.stinch.erase(std::remove(env.stinch.begin(), env.stinch.end(), env.stinch.at(i)), env.stinch.end());
             size--;
         }
         
     }
     std::cout<<"Stinch:"<<std::endl;
     for(int t=0;t<env.stinch.size();t++){
        std::cout<<env.stinch.at(t)<<" ";
     }
     std::cout<<std::endl;
}

void Environment::set_breeze(Environment &env){
    
    
    for(int j=0;j<env.pits_cont.size();j++){
        std::vector<int> pit_adj_cont;
        pit_adj_cont.push_back(env.pits_cont.at(j) - 4);
        pit_adj_cont.push_back(env.pits_cont.at(j) + 4);
        pit_adj_cont.push_back(env.pits_cont.at(j) - 1);
        pit_adj_cont.push_back(env.pits_cont.at(j) + 1);
        
        int size = pit_adj_cont.size();
        
        for(int i=0;i<size;i++){
         if(pit_adj_cont.at(i) < 0 || pit_adj_cont.at(i) > 15){
            pit_adj_cont.erase(std::remove(pit_adj_cont.begin(), pit_adj_cont.end(), pit_adj_cont.at(i)), pit_adj_cont.end());
            size--;i--;
            continue;
         }
         if(env.pits_cont.at(j) % 4==0 && pit_adj_cont.at(i)%4==3){
             pit_adj_cont.erase(std::remove(pit_adj_cont.begin(), pit_adj_cont.end(), pit_adj_cont.at(i)), pit_adj_cont.end());
             size--;i--;
             continue;
         }
         if((env.pits_cont.at(j)+1) % 4==0 && pit_adj_cont.at(i)%4==0){
             pit_adj_cont.erase(std::remove(pit_adj_cont.begin(), pit_adj_cont.end(), pit_adj_cont.at(i)), pit_adj_cont.end());
             size--;i--;
             continue;
         }
         
     }
        env.breeze.push_back(pit_adj_cont);
        pit_adj_cont.clear();
    }
     std::cout<<"Breeze:"<<std::endl;
     for(int j=0;j<env.breeze.size();j++){
     for(int t=0;t<env.breeze.at(j).size();t++){
        std::cout<<env.breeze.at(j).at(t)<<" ";
     }
      std::cout<<std::endl;
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
