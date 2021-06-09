#pragma once

#include "Card.hpp"
#include <vector>
#include <iostream>

class Tas : public std::vector<Card>
{
private:
    bool isOnList(std::array<int, 52> list, int nb, int max);
public:
    enum State {Empty, Full};

    Tas(Tas::State state = Empty);
    Tas(const Tas& a);
    ~Tas() = default;
    void shuffle();

    Tas& operator=(const Tas &a);
};

std::ostream& operator<<(std::ostream &flux, const Tas &a);