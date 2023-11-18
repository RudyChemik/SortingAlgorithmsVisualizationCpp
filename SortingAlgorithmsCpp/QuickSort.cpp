#include "SharedFunctions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::Sound& swapSound) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            drawBars(window, arr, j, false);
            swapSound.play();
            sf::sleep(sf::milliseconds(10));
        }
    }

    swap(arr[i + 1], arr[high]);
    drawBars(window, arr, high, false);
    swapSound.play();
    sf::sleep(sf::milliseconds(10));

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::Sound& swapSound, bool final = false) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, window, swapSound);

        quickSort(arr, low, pivotIndex - 1, window, swapSound);
        quickSort(arr, pivotIndex + 1, high, window, swapSound);
    }

    if (final) {
        for (int i = 0; i < arr.size(); ++i) {
            drawBars(window, arr, i, true);
            sf::sleep(sf::milliseconds(10));
        }
    }
}




