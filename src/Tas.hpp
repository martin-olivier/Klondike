/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#ifndef Tas_H
#define Tas_H

#include "Card.hpp"
#include <vector>
#include <iostream>

class Tas : public std::vector<Card>
{
public:
    enum State {Empty, Full};

    explicit Tas(Tas::State state = Empty);
    Tas(const Tas& a);
    ~Tas() = default;
    void shuffle();

    Tas& operator=(const Tas &a);
};

std::ostream& operator<<(std::ostream &flux, const Tas &a);

#endif