#include "Klondike.hpp"

int main()
{
    try {
        Klondike app;
        return app.start();
    }
    catch (...) {
        return 84;
    }
}