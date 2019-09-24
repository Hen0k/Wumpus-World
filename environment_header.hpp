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
        std::vector<int> glitter;
        
    public:
        std::vector<int> get_stinch;
        std::vector<std::vector<int>> get_breeze;
        std::vector<std::vector<char>> set_rooms(std::vector<int> pits,int w,int g);
        std::vector<int> set_index_cont();
        std::vector<int> set_pits_position(std::vector<int> index_cont);
        int set_wumpus_position(std::vector<int> index_cont);
        int set_gold_position(std::vector<int> index_cont);
        void print_world(std::vector<std::vector<char>> world);
        std::vector<int> set_stinch(int wumpus_cont);
        std::vector<std::vector<int>> set_breeze(std::vector<int> pits_cont);
        void set_glitter(Environment &env);
        bool check_stinch(int x);
        bool check_breeze(int x);
        void start(Environment &env);
};
#endif
