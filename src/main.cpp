/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

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