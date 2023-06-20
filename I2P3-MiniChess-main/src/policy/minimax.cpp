#include <cstdlib>
#include <iostream>
#include <math.h>
#include <limits.h>

#include "../state/state.hpp"
#include "./random.hpp"
#include "./minimax.hpp"

using namespace std;

/**
 * @brief use minimax get a legal action
 * 
 * @param state Now state
 * @param depth depth of tree
 * @return bestmove 
 */
Move get_move(State *state, int depth){
    if(!state->legal_actions.size()){
        state->get_legal_actions();
    }
    auto actions = state->legal_actions;
    Move bestmove = actions[0];
    int maxeval;

    for(auto i: actions){
        auto next = state->next_state(i);
        if(state->player){
            maxeval = INT_MAX;
            int score = minimax::minimaxmove(next, depth - 1, false);
            if(score < maxeval){
                maxeval = score;
                bestmove = i;
            }
        }else{
            maxeval = INT_MIN;
            int score = minimax::minimaxmove(next, depth-1, true);
            if(score > maxeval){
                maxeval = score;
                bestmove = i;
            }
        }
    }
    return bestmove;

}

/**
 * @brief use minimax get a legal action
 * 
 * @param state Now state
 * @param depth depth of tree
 * @return min/max eval
 */

// TO IMPLEMENT MINIMAX

int minimaxmove(State *state, int depth, bool maxiplayer){

    //if no depth or anything, do nothing
    if(depth == 0 || state->get_legal_actions().empty() || state->game_state == WIN || state->game_state == DRAW){
        if(state->score){
            return state->score
        }
        return state->evaluate();
    }
    //from rand code
    if(!state->legal_actions.size()){
        state->get_legal_actions();
    }

    auto actions = state->legal_actions;
    
    //if it is us then do maxeval
    if(maxiplayer){
        int maxeval = INT_MIN;
        state->get_legal_actions();
        for(auto it : actions){
            auto gonext = state->next_state(it);
            int score = minimax(gonext, depth-1, false);
            maxeval = max(maxeval, score);
        }
        return maxeval;
    }else{

        //if not, min eval
        int mineval = INT_MAX;
        state->get_legal_actions();
        for(auto it : actions){
            auto gonext = state->next_state(it);
            int score = minimax(gonext, depth-1, true);
            mineval = min(mineval, score);
        }
        return mineval;
    }
}

