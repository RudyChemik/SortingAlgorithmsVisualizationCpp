#pragma once
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;

void heapify(vector<int>& arr, int n, int i, sf::RenderWindow& window, sf::Sound& swapSound);
void heapSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound);

#endif