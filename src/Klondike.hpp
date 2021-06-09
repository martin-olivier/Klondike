#pragma once

#include "Tas.hpp"
#include "Tile.hpp"
#include "Sound.hpp"
#include <array>

class Klondike
{
private:
    sf::RenderWindow m_window{};
    sf::Image m_app_icon{};

    Tile m_background{};
    Tile m_void_card{};
    Tile m_as_bar{};
    Tile m_card_back{};
    Tile m_selector_up{};
    Tile m_selector_down{};
    Tile m_sound_icon{};
    Tile m_refresh_icon{};
    Tile m_win{};

    Sound m_card_place{};
    Sound m_card_slide{};

    bool m_sound;

    Tas m_hand;
    std::vector<Tas> m_pile{};
    std::array<Tas, 4> m_goal{};

    Tas *m_ptr;
    size_t m_selector;
    size_t m_hand_index;
public:
    Klondike();
    ~Klondike() = default;
    Klondike(const Klondike &) = delete;
    Klondike &operator=(const Klondike &) = delete;
    static bool clickInRange(sf::Event::MouseButtonEvent event, sf::IntRect rect);
    void reset();
    void game_event();
    void switchSound();
    void draw();
    void showLastCards();
    int start();

    void handNext();

    void selectHand();
    void selectGoal(unsigned int pos);
    void selectPile(unsigned int pos, int y);

    bool isCardValid(unsigned int x, size_t y);

    void action(unsigned int x, unsigned int y);

    void handToPile(unsigned int x, unsigned int y);
    void PileToPile(unsigned int x, unsigned int y);

    bool isGameWon();

    static constexpr size_t npos = -1;
};