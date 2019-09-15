#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<vector>
#include<string>
#include<bits/stdc++.h> 
#include <algorithm>

class Environment{
    public:
        int player_start = 0;
        int grid_size = 4;
        std::vector<int> index_cont;
        std::vector<int> pits_cont;
        std::vector<int>::iterator it; 
        std::vector<std::vector<char>> world;
        void set_index_cont(Environment &env);
        void set_rooms(Environment &env);
        void set_wumpus_position(Environment &env);
        void set_pits_position(Environment &env);
        void set_gold_position(Environment &env);
        void set_agent();
};
#endif
