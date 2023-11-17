#pragma once
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;
void insertionSorts(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound);
#endif