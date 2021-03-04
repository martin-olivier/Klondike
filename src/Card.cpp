/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "Card.hpp"

Card::Card(Card::Type type, int value, const std::string &path_to_texture) : Tile(path_to_texture)
{
    if (type == Losange || type == Coeur)
        m_color = Red;
    else
        m_color = Black;
    m_type = type;
    m_value = value;
    m_status = false;
}

Card::Card(const Card& a) : Tile(a.m_path) {
    m_color = a.m_color;
    m_type = a.m_type;
    m_value = a.m_value;
    m_status = a.m_status;
}

Card& Card::operator=(const Card &a)
{
    if (&a == this)
        return *this;
    m_color = a.m_color;
    m_type = a.m_type;
    m_value = a.m_value;
    m_status = a.m_status;
    setTexture(a.m_path);
    return *this;
}

bool Card::operator==(const Card &a) const
{
    return m_value == a.m_value;
}

bool Card::operator!=(const Card &a) const
{
    return !(*this == a);
}