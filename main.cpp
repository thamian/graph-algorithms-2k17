#include "Controller/Controller.h"

int main() {
    Controller *controller = new Controller();
    controller->start();
    delete controller;

    return 0;
}
