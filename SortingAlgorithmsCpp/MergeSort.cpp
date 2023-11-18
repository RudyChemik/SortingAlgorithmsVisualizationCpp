#include "SharedFunctions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>


using namespace std;

void merge(vector<int>& arr, int left, int middle, int right, sf::RenderWindow& window, sf::Sound& swapSound) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        drawBars(window, arr, k, false);      
        sf::sleep(sf::milliseconds(50));
        k++;
    }
    swapSound.play();

    while (i < n1) {
        arr[k] = L[i];
        drawBars(window, arr, k, false);
        swapSound.play();
        sf::sleep(sf::milliseconds(10));
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        drawBars(window, arr, k, false);
        swapSound.play();
        sf::sleep(sf::milliseconds(10));
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int>& arr, int left, int right, sf::RenderWindow& window, sf::Sound& swapSound) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSortHelper(arr, left, middle, window, swapSound);
        mergeSortHelper(arr, middle + 1, right, window, swapSound);

        merge(arr, left, middle, right, window, swapSound);
    }
}

void mergeSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound) {
    int n = arr.size();

    mergeSortHelper(arr, 0, n - 1, window, swapSound);

    for (int i = 0; i < arr.size(); ++i) {
        drawBars(window, arr, i, true);
        sf::sleep(sf::milliseconds(10));
    }
}
