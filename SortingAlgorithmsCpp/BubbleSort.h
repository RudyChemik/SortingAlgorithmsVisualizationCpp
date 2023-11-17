#pragma once
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;
void bubbleSorts(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound);
#endif