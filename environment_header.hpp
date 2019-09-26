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
        /*set the pits, the wumpus and the gold to the 4x4 room*/
        std::vector<std::vector<char>> set_rooms(std::vector<int> pits,int w,int g);
        
        /*pick 5 random numbers from 0-16*/
        std::vector<int> set_index_cont();
        
        /*choose the pits position from the 5 random numbers*/
        std::vector<int> set_pits_position(std::vector<int> index_cont);
        
        /*choose the wumpus position from the 5 random numbers*/
        int set_wumpus_position(std::vector<int> index_cont);
        
        /*choose the gold position from the 5 random numbers*/
        int set_gold_position(std::vector<int> index_cont);
        
        /*print out the environment*/
        void print_world(std::vector<std::vector<char>> world);
        
        /*get the stinch rooms*/
        std::vector<int> set_stinch(int wumpus_cont);
        
        /*get the breeze rooms*/
        std::vector<std::vector<int>> set_breeze(std::vector<int> pits_cont);
        
        /*start playing the game*/
        void start(Environment &env);
        
        /*variable for storing stinch rooms*/
        std::vector<int> get_stinch;
        
        /*variable for storing breeze rooms*/
        std::vector<std::vector<int>> get_breeze;

        /*variable for gold room*/
        int gold_cont;

        /*variable for containing the whole environment*/
        std::vector<std::vector<char>> world;
        
};
#endif
