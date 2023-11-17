#include "SharedFunctions.h"
#include <iostream>
using namespace std;

sf::SoundBuffer createSwapSound() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("swap.wav")) {
        cerr << "Failed" << endl;
    }
    return buffer;
}

void drawBars(sf::RenderWindow& window, vector<int>& bars, int sortingColumn, bool sorted) {
    window.clear();

    for (size_t i = 0; i < bars.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, bars[i]));

        if (sorted && i >= 0 && i <= sortingColumn) {
            bar.setFillColor(sf::Color::Blue);
        }
        else if (i == sortingColumn) {
            bar.setFillColor(sf::Color::Red);
        }

        bar.setPosition(i * barWidth, windowHeight - bars[i]);
        window.draw(bar);
    }

    window.display();
}
