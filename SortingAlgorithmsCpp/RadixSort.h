#pragma once
#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;

void countingSort(vector<int>& arr, int exp, sf::RenderWindow& window, sf::Sound& swapSound);
int getMax(vector<int>& arr);
void radixSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound);

#endif