/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "Tas.hpp"
#include <array>

Tas::Tas(Tas::State state) : std::vector<Card>()
{
    if (state == Empty)
        return;

    this->reserve(52);

    this->emplace_back(Card::Losange, 1, "resource/cards/cardDiamondsA.bmp");
    this->emplace_back(Card::Losange, 2, "resource/cards/cardDiamonds2.bmp");
    this->emplace_back(Card::Losange, 3, "resource/cards/cardDiamonds3.bmp");
    this->emplace_back(Card::Losange, 4, "resource/cards/cardDiamonds4.bmp");
    this->emplace_back(Card::Losange, 5, "resource/cards/cardDiamonds5.bmp");
    this->emplace_back(Card::Losange, 6, "resource/cards/cardDiamonds6.bmp");
    this->emplace_back(Card::Losange, 7, "resource/cards/cardDiamonds7.bmp");
    this->emplace_back(Card::Losange, 8, "resource/cards/cardDiamonds8.bmp");
    this->emplace_back(Card::Losange, 9, "resource/cards/cardDiamonds9.bmp");
    this->emplace_back(Card::Losange, 10, "resource/cards/cardDiamonds10.bmp");
    this->emplace_back(Card::Losange, 11, "resource/cards/cardDiamondsJ.bmp");
    this->emplace_back(Card::Losange, 12, "resource/cards/cardDiamondsQ.bmp");
    this->emplace_back(Card::Losange, 13, "resource/cards/cardDiamondsK.bmp");

    this->emplace_back(Card::Trefle, 1, "resource/cards/cardClubsA.bmp");
    this->emplace_back(Card::Trefle, 2, "resource/cards/cardClubs2.bmp");
    this->emplace_back(Card::Trefle, 3, "resource/cards/cardClubs3.bmp");
    this->emplace_back(Card::Trefle, 4, "resource/cards/cardClubs4.bmp");
    this->emplace_back(Card::Trefle, 5, "resource/cards/cardClubs5.bmp");
    this->emplace_back(Card::Trefle, 6, "resource/cards/cardClubs6.bmp");
    this->emplace_back(Card::Trefle, 7, "resource/cards/cardClubs7.bmp");
    this->emplace_back(Card::Trefle, 8, "resource/cards/cardClubs8.bmp");
    this->emplace_back(Card::Trefle, 9, "resource/cards/cardClubs9.bmp");
    this->emplace_back(Card::Trefle, 10, "resource/cards/cardClubs10.bmp");
    this->emplace_back(Card::Trefle, 11, "resource/cards/cardClubsJ.bmp");
    this->emplace_back(Card::Trefle, 12, "resource/cards/cardClubsQ.bmp");
    this->emplace_back(Card::Trefle, 13, "resource/cards/cardClubsK.bmp");

    this->emplace_back(Card::Coeur, 1, "resource/cards/cardHeartsA.bmp");
    this->emplace_back(Card::Coeur, 2, "resource/cards/cardHearts2.bmp");
    this->emplace_back(Card::Coeur, 3, "resource/cards/cardHearts3.bmp");
    this->emplace_back(Card::Coeur, 4, "resource/cards/cardHearts4.bmp");
    this->emplace_back(Card::Coeur, 5, "resource/cards/cardHearts5.bmp");
    this->emplace_back(Card::Coeur, 6, "resource/cards/cardHearts6.bmp");
    this->emplace_back(Card::Coeur, 7, "resource/cards/cardHearts7.bmp");
    this->emplace_back(Card::Coeur, 8, "resource/cards/cardHearts8.bmp");
    this->emplace_back(Card::Coeur, 9, "resource/cards/cardHearts9.bmp");
    this->emplace_back(Card::Coeur, 10, "resource/cards/cardHearts10.bmp");
    this->emplace_back(Card::Coeur, 11, "resource/cards/cardHeartsJ.bmp");
    this->emplace_back(Card::Coeur, 12, "resource/cards/cardHeartsQ.bmp");
    this->emplace_back(Card::Coeur, 13, "resource/cards/cardHeartsK.bmp");

    this->emplace_back(Card::Pique, 1, "resource/cards/cardSpadesA.bmp");
    this->emplace_back(Card::Pique, 2, "resource/cards/cardSpades2.bmp");
    this->emplace_back(Card::Pique, 3, "resource/cards/cardSpades3.bmp");
    this->emplace_back(Card::Pique, 4, "resource/cards/cardSpades4.bmp");
    this->emplace_back(Card::Pique, 5, "resource/cards/cardSpades5.bmp");
    this->emplace_back(Card::Pique, 6, "resource/cards/cardSpades6.bmp");
    this->emplace_back(Card::Pique, 7, "resource/cards/cardSpades7.bmp");
    this->emplace_back(Card::Pique, 8, "resource/cards/cardSpades8.bmp");
    this->emplace_back(Card::Pique, 9, "resource/cards/cardSpades9.bmp");
    this->emplace_back(Card::Pique, 10, "resource/cards/cardSpades10.bmp");
    this->emplace_back(Card::Pique, 11, "resource/cards/cardSpadesJ.bmp");
    this->emplace_back(Card::Pique, 12, "resource/cards/cardSpadesQ.bmp");
    this->emplace_back(Card::Pique, 13, "resource/cards/cardSpadesK.bmp");
}

Tas::Tas(const Tas& a) : std::vector<Card>(a)
{
    *this = a;
}

bool Tas::isOnList(std::array<int, 52> list, int nb, int max)
{
    for (int i = 0; i < max; i++) {
        if (list[i] == nb)
            return true;
    }
    return false;
}

void Tas::shuffle()
{
    Tas tmp;
    srand(time(NULL));
    int nb;
    int i = 0;
    std::array<int, 52> list;
    while (i != 52) {
        nb = (rand() % 52);
        if (isOnList(list, nb, i) == false) {
            list[i] = nb;
            i++;
        }
    }
    for (i = 0; i < 52; i++) {
        tmp.push_back(this->at(list[i]));
    }
    *this = tmp;
}

Tas& Tas::operator=(const Tas &a)
{
    this->clear();
    for (size_t i = 0; i < a.size(); i++)
        this->push_back(a[i]);
    return *this;
}

std::ostream& operator<<(std::ostream &flux, const Tas &a)
{
    for (size_t i = 0; i < a.size(); i++)
        flux << "Card : " << a[i].get_type() << " | value : " << a[i].get_value() << std::endl;
    return flux;
}