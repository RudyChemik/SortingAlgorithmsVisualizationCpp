#pragma once
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;
void selectionSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound);
#endif