#pragma once
class Controller {
private:
    int* keys = nullptr;
    int* actions = nullptr;
    int count = 0;

public:
    Controller(int n);
    ~Controller();

    Controller(const Controller& other);
    Controller& operator=(const Controller& other);

    void set(int index, int keyCode, int action);
    int getAction(int keyCode) const;
};
