#include "Controller.h"

Controller::Controller(int n) : count(n) {
    keys = new int[n];
    actions = new int[n];
}

Controller::~Controller() {
    delete[] keys;
    delete[] actions;
}

Controller::Controller(const Controller& other)
    : count(other.count)
{
    keys = new int[count];
    actions = new int[count];

    for (int i = 0; i < count; ++i) {
        keys[i] = other.keys[i];
        actions[i] = other.actions[i];
    }
}

Controller& Controller::operator=(const Controller& other)
{
    if (this == &other) return *this;

    delete[] keys;
    delete[] actions;

    count = other.count;
    keys = new int[count];
    actions = new int[count];

    for (int i = 0; i < count; ++i) {
        keys[i] = other.keys[i];
        actions[i] = other.actions[i];
    }

    return *this;
}

void Controller::set(int index, int keyCode, int action) {
    if (index < 0 || index >= count)
        return;

    keys[index] = keyCode;
    actions[index] = action;
}

int Controller::getAction(int keyCode) const {

    for (int i = 0; i < count; i++) {
        if (keys[i] == keyCode)
            return actions[i];
    }
    return -1;
}
