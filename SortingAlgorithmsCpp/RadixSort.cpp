#include "SharedFunctions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp, sf::RenderWindow& window, sf::Sound& swapSound) {

    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int currentNumber = arr[i];
        int digit = (currentNumber / exp) % 10;
        int positionInOutput = count[digit] - 1;

        output[positionInOutput] = currentNumber;
        count[digit]--;
    }


    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        drawBars(window, arr, i, false);
        swapSound.play();
        sf::sleep(sf::milliseconds(20));
    }
}

void radixSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound) {

    int maxNum = getMax(arr);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp, window, swapSound);
    }

    for (int i = 0; i < arr.size(); ++i) {
        drawBars(window, arr, i, true);
        sf::sleep(sf::milliseconds(20));
    }
}
