#include "State.h"

void State::setNextState(State* state) {
    if(_nextState) delete _nextState;
    _nextState = state;
}

State* State::getNextState() {
    return _nextState;
}