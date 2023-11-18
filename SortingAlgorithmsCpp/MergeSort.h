#pragma once
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;
void mergeSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound);
void mergeSortHelper(vector<int>& arr, int left, int right, sf::RenderWindow& window, sf::Sound& swapSound);
void merge(vector<int>& arr, int left, int middle, int right, sf::RenderWindow& window, sf::Sound& swapSound);
#endif