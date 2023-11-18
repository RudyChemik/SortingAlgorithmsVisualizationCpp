#pragma once
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;

int partition(vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::Sound& swapSound);
void quickSort(vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::Sound& swapSound, bool isFinalCall = false);

#endif