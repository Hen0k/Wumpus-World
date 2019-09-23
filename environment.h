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
    private:
        int player_start = 0;
        int grid_size = 4;
        std::vector<int> index_cont;
        std::vector<int> pits_cont;
        int wumpus_cont;
        int gold_cont;
        std::vector<int>::iterator it; 
        std::vector<int> stinch;
        std::vector<std::vector<int>> breeze;
        std::vector<int> glitter;
        std::vector<std::vector<char>> world;
    public:
        void set_index_cont(Environment &env);
        void set_rooms(Environment &env);
        void set_wumpus_position(Environment &env);
        void set_pits_position(Environment &env);
        void set_gold_position(Environment &env);
        void print_world(Environment &env);
        void set_stinch(Environment &env);
        void set_breeze(Environment &env);
        void set_glitter(Environment &env);
        std::vector<int> create_adjacent(int x);
        void set_agent();
};
#endif
