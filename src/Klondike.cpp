/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "Klondike.hpp"

Klondike::Klondike() : m_sound(true), m_hand(Tas::Full), m_ptr(nullptr), m_selector(0), m_hand_index(0)
{
    m_window.create(sf::VideoMode(1400, 900), "Klondike");
    m_window.setFramerateLimit(60);
    m_window.setKeyRepeatEnabled(false);

    m_app_icon.loadFromFile("resource/app_icon.bmp");
    m_window.setIcon(m_app_icon.getSize().x, m_app_icon.getSize().y, m_app_icon.getPixelsPtr());

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    m_window.setPosition(sf::Vector2i(desktop.width / 2 - m_window.getSize().x/2, desktop.height/2 - m_window.getSize().y/2));

    m_background.setTexture("resource/backgrounds/background.bmp");
    m_void_card.setTexture("resource/cards/no_card.bmp");
    m_as_bar.setTexture("resource/cards/as_cards.bmp");
    m_card_back.setTexture("resource/cards/card_back.bmp");
    m_selector_up.setTexture("resource/selector_up.bmp");
    m_selector_down.setTexture("resource/selector_down.bmp");
    m_sound_icon.setTexture("resource/icons/volume.png");
    m_refresh_icon.setTexture("resource/icons/refresh.bmp");
    m_win.setTexture("resource/win_sprite.bmp");

    m_card_place.setSound("resource/sounds/cardPlace.ogg");
    m_card_slide.setSound("resource/sounds/cardSlide.ogg");

    this->reset();
}

int Klondike::start()
{
    while (m_window.isOpen()) {
        game_event();
        this->showLastCards();
        m_window.clear(sf::Color::Black);
        this->draw();
        m_window.display();
        sf::sleep(sf::milliseconds(20));
    }
    return EXIT_SUCCESS;
}

bool Klondike::isGameWon()
{
    for (int i = 0; i < 4; i++) {
        if (m_goal[i][m_goal[i].size() - 1].get_value() != 13)
            return false;
    }
    return true;
}

void Klondike::draw()
{
    float rect_x = 50;
    float rect_y = 50;

    m_window.draw(m_background);

    for (int i = 0; i < 4; i++) {
        m_as_bar.setPosition(rect_x, rect_y);
        m_window.draw(m_as_bar);
        m_goal[i][m_goal[i].size() - 1].setPosition(rect_x, rect_y);
        m_window.draw(m_goal[i][m_goal[i].size() - 1]);
        rect_x += 160;
    }
    rect_x += 160;
    if (!m_hand.empty()) {
        m_hand[m_hand_index].setPosition(rect_x, rect_y);
        m_window.draw(m_hand[m_hand_index]);
    }
    rect_x += 160;
    m_void_card.setPosition(rect_x, rect_y);
    m_window.draw(m_void_card);
    if (!m_hand.empty()) {
        if (m_hand_index < m_hand.size() - 1) {
            m_card_back.setPosition(rect_x, rect_y);
            m_window.draw(m_card_back);
        }
    }
    rect_x = 50;
    rect_y = 350;
    for (int i = 0; i < 7; i++) {
        m_void_card.setPosition(rect_x, rect_y);
        m_window.draw(m_void_card);
        for (size_t j = 0; j < m_pile[i].size(); j++) {
            if (m_pile[i][j].get_status() == true) {
                m_pile[i][j].setPosition(rect_x, rect_y);
                m_window.draw(m_pile[i][j]);
            } else if (m_pile[i][j].get_status() == false) {
                m_card_back.setPosition(rect_x, rect_y);
                m_window.draw(m_card_back);
            }
            rect_y += 40;
        }
        rect_x += 160;
        rect_y = 350;
    }
    if (m_ptr == nullptr) {}
    else if (m_ptr == &m_hand) {
        rect_x = (50 + (160 * 5));
        rect_y = 50;
        m_selector_up.setPosition(rect_x, rect_y);
        m_window.draw(m_selector_up);
        rect_y += 160;
        m_selector_down.setPosition(rect_x, rect_y);
        m_window.draw(m_selector_down);
    } else {
        int i = 0;
        for (i = 0; i < 7; i++) {
            if (&m_pile[i] == m_ptr)
                break;
        }
        rect_x = (50 + (160 * i));
        rect_y = (350 + (40 * m_selector));
        m_selector_up.setPosition(rect_x, rect_y);
        m_window.draw(m_selector_up);
        rect_y += (160 + (40 * (m_ptr[0].size() - (m_selector + 1))));
        m_selector_down.setPosition(rect_x, rect_y);
        m_window.draw(m_selector_down);
    }

    if (isGameWon()) {
        m_win.setPosition(500, 500);
        m_window.draw(m_win);
    }

    rect_x = 1300;
    rect_y = 50;
    m_sound_icon.setPosition(rect_x, rect_y);
    m_window.draw(m_sound_icon);
    rect_y += 100;
    m_refresh_icon.setPosition(rect_x, rect_y);
    m_window.draw(m_refresh_icon);
}

void Klondike::reset()
{
    m_ptr = nullptr;
    m_selector = 0;
    m_hand_index = 0;
    Tas tmp(Tas::Full);
    m_hand = tmp;

    m_hand.shuffle();

    m_pile.clear();
    m_goal[0].clear();
    m_goal[1].clear();
    m_goal[2].clear();
    m_goal[3].clear();

    int max = 1;

    for (int i = 0; i < 7; i++, max++) {
        m_pile.emplace_back(Tas::Empty);
        for (int j = 0; j < max; j++) {
            m_pile[i].push_back(m_hand[m_hand.size() - 1]);
            m_hand.pop_back();
        }
        m_pile[i][m_pile[i].size() - 1].set_status(true);
    }
    m_goal[0].emplace_back(Card::Losange, 0, "resource/cards/no_card.bmp");
    m_goal[1].emplace_back(Card::Trefle, 0, "resource/cards/no_card.bmp");
    m_goal[2].emplace_back(Card::Coeur, 0, "resource/cards/no_card.bmp");
    m_goal[3].emplace_back(Card::Pique, 0, "resource/cards/no_card.bmp");
}

bool Klondike::clickInRange(sf::Event::MouseButtonEvent event, sf::IntRect rect)
{
    return rect.contains(event.x, event.y);
}

void Klondike::showLastCards()
{
    for (auto &tas : m_pile) {
        if (!tas.empty()) {
            tas[tas.size() - 1].set_status(true);
        }
    }
}
