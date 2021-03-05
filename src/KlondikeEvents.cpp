/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "Klondike.hpp"
#include <map>

std::map<int, Card::Type> goalEmplacementMap = {
        {0, Card::Type::Losange},
        {1, Card::Type::Trefle},
        {2, Card::Type::Coeur},
        {3, Card::Type::Pique},
};

void Klondike::parameters()
{
    std::cout << "Not implemented yet !" << std::endl;
}

void Klondike::handNext()
{
    m_card_slide.play();
    if (m_hand_index == m_hand.size() - 1) {
        m_hand_index = 0;
        return;
    }
    m_hand_index++;
    m_ptr = nullptr;
}

void Klondike::selectHand()
{
    if (m_ptr || m_hand.empty())
        m_ptr = nullptr;
    else
        m_ptr = &m_hand;
}

void Klondike::selectGoal(unsigned int pos)
{
    if (m_ptr == nullptr)
        return;
    m_card_place.play();
    if (m_ptr == &m_hand) {
        if (m_hand[m_hand_index].get_value() == m_goal[pos][m_goal[pos].size() - 1].get_value() + 1 && m_hand[m_hand_index].get_type() == goalEmplacementMap[pos]) {
            m_goal[pos].push_back(m_hand[m_hand_index]);
            m_hand.erase(m_hand.begin() + m_hand_index);
            if (m_hand_index > 0)
                m_hand_index--;
            m_ptr = nullptr;
            return;
        }
        return;
    }
    else {
        if (m_ptr[0].size() - 1 != m_selector)
            return;
        if (m_ptr[0][m_selector].get_value() == m_goal[pos][m_goal[pos].size() - 1].get_value() + 1) {
            if (m_ptr[0][m_selector].get_type() == goalEmplacementMap[pos]) {
                m_goal[pos].push_back(m_ptr[0][m_selector]);
                m_ptr[0].pop_back();
                m_ptr = nullptr;
                return;
            }
        }
    }
}

void Klondike::handToPile(unsigned int x, unsigned int y)
{
    if (m_hand[m_hand_index].get_value() == m_pile[x][y].get_value() - 1 && m_hand[m_hand_index].get_color() != m_pile[x][y].get_color()) {
        m_pile[x].push_back(m_hand[m_hand_index]);
        m_hand.erase(m_hand.begin() + m_hand_index);
        if (m_hand_index > 0)
            m_hand_index--;
    }
    if (y == 0 && m_pile[x].empty() && m_hand[m_hand_index].get_value() == 13) {
        m_pile[x].push_back(m_hand[m_hand_index]);
        m_hand.erase(m_hand.begin() + m_hand_index);
        if (m_hand_index > 0)
            m_hand_index--;
    }
}

void Klondike::PileToPile(unsigned int x, unsigned int y)
{
    if (!m_pile[x].empty() && m_pile[x].size() - 1 != y)
        return;

    if (m_ptr[0][m_selector].get_value() == m_pile[x][y].get_value() - 1 && m_ptr[0][m_selector].get_color() != m_pile[x][y].get_color()) {
        while (m_selector != m_ptr[0].size()) {
            m_pile[x].push_back(m_ptr[0][m_selector]);
            m_ptr[0].erase(m_ptr[0].begin() + m_selector);
        }
    }
    if (y == 0 && m_pile[x].empty() && m_ptr[0][m_selector].get_value() == 13) {
        while (m_selector != m_ptr[0].size()) {
            m_pile[x].push_back(m_ptr[0][m_selector]);
            m_ptr[0].erase(m_ptr[0].begin() + m_selector);
        }
    }
}

void Klondike::action(unsigned int x, unsigned int y)
{
    if (m_ptr == nullptr) {
        m_ptr = &m_pile[x];
        m_selector = y;
        m_card_slide.play();
        return;
    }
    else if (m_ptr == &m_hand)
        handToPile(x, y);
    else
        PileToPile(x, y);
    m_ptr = nullptr;
    m_selector = 0;
    m_card_place.play();
}

bool Klondike::isCardValid(unsigned int x, size_t y)
{
    if (m_pile[x].size() <= y && m_ptr == nullptr)
        return false;
    if (m_pile[x][y].get_status() == true)
        return true;
    return false;
}

void Klondike::selectPile(unsigned int pos, int y)
{
    size_t card = 0;
    int i = 0;

    for (i = 350; card < m_pile[pos].size(); i += 40) {
        if (y > i && y < i + 40) {
            if (isCardValid(pos, card)) {
                action(pos, card);
                return;
            }
        }
        card++;
    }
    if (m_pile[pos].empty() && y > 350 && y < (350 + 190)) {
        if (isCardValid(pos, 0)) {
            action(pos, 0);
            return;
        }
    }
    card--;
    i -= 40;
    if (y > i && y < i + 190) {
        if (isCardValid(pos, card)) {
            action(pos, card);
            return;
        }
    }
}

void Klondike::game_event()
{
    sf::Event ev;
    while (m_window.pollEvent(ev)) {
        if (ev.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, ev.size.width, ev.size.height);
            m_window.setView(sf::View(visibleArea));
        }
        if (ev.type == sf::Event::Closed)
            m_window.close();
        else if (ev.type == sf::Event::MouseButtonReleased && ev.mouseButton.button == sf::Mouse::Left) {
            if (clickInRange(ev.mouseButton, sf::IntRect(1400, 50, 70, 70)))
                parameters();
            else if (clickInRange(ev.mouseButton, sf::IntRect(1400, 150, 70, 70)))
                reset();
            else if (clickInRange(ev.mouseButton, sf::IntRect(850, 50, 140, 200)))
                selectHand();
            else if (clickInRange(ev.mouseButton, sf::IntRect(1010, 50, 140, 200)))
                handNext();
            else if (clickInRange(ev.mouseButton, sf::IntRect(50, 50, 140, 200)))
                selectGoal(0);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + 160, 50, 140, 200)))
                selectGoal(1);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 2), 50, 140, 200)))
                selectGoal(2);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 3), 50, 140, 200)))
                selectGoal(3);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50, 50, 140, 2000)))
                selectPile(0, ev.mouseButton.y);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + 160, 50, 140, 2000)))
                selectPile(1, ev.mouseButton.y);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 2), 50, 140, 2000)))
                selectPile(2, ev.mouseButton.y);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 3), 50, 140, 2000)))
                selectPile(3, ev.mouseButton.y);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 4), 50, 140, 2000)))
                selectPile(4, ev.mouseButton.y);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 5), 50, 140, 2000)))
                selectPile(5, ev.mouseButton.y);
            else if (clickInRange(ev.mouseButton, sf::IntRect(50 + (160 * 6), 50, 140, 2000)))
                selectPile(6, ev.mouseButton.y);
            else
                m_ptr = nullptr;
        }
    }
}