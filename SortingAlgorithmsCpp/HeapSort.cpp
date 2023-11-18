#include "SharedFunctions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i, sf::RenderWindow& window, sf::Sound& swapSound) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        drawBars(window, arr, i, false);
        swapSound.play();
        sf::sleep(sf::milliseconds(20));

        heapify(arr, n, largest, window, swapSound);
    }
}

void heapSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, window, swapSound);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        drawBars(window, arr, i, false);
        swapSound.play();
        sf::sleep(sf::milliseconds(20));

        heapify(arr, i, 0, window, swapSound);
    }

    for (int i = 0; i < arr.size(); ++i) {
        drawBars(window, arr, i, true);
        sf::sleep(sf::milliseconds(20));
    }
}
