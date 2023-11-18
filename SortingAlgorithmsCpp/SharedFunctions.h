#pragma once
#ifndef SHARED_FUNCTIONS_H
#define SHARED_FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using std::vector;

const int windowWidth = 1200;
const int windowHeight = 800;
const int barWidth = 40;

sf::SoundBuffer createSwapSound();
void drawBars(sf::RenderWindow& window, vector<int>& bars, int sortingColumn, bool sorted);

#endif
