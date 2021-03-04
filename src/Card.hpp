/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#ifndef Card_H
#define Card_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tile.hpp"

class Card : public Tile
{
public:
    enum Color {Red, Black};
    enum Type {Losange, Trefle, Coeur, Pique};

    Card(Card::Type type, int value, const std::string &path_to_texture);
    Card(const Card& a);
    ~Card() override = default;

    Card::Color get_color() const {return m_color;};
    Card::Type get_type() const {return m_type;};
    int get_value() const {return m_value;};
    bool get_status() const {return m_status;};

    void set_color(Card::Color color) {m_color = color;};
    void set_type(Card::Type type) {m_type = type;};
    void set_value(int value) {m_value = value;};
    void set_status(bool status) {m_status = status;};

    Card& operator=(const Card &a);
    bool operator==(const Card &a) const;
    bool operator!=(const Card &a) const;
private:
    Card::Color m_color;
    Card::Type m_type;
    int m_value;
    bool m_status;
};

#endif