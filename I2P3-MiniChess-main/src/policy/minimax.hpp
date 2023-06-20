#pragma once
#include "../state/state.hpp"

class minimax{
public:
    static Move get_move(State *state, int depth);
    static int minimaxmove(State *state, int depth, bool maxiplayer);
};