/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "Sound.hpp"

Sound::Sound(const std::string &path)
{
    if (!buffer.loadFromFile(path))
        throw std::exception();
    sound.setBuffer(buffer);
}

void Sound::setSound(const std::string &path)
{
    if (!buffer.loadFromFile(path))
        throw std::exception();
    sound.setBuffer(buffer);
}

void Sound::play()
{
    sound.play();
}