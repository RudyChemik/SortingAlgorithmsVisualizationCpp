#include "SharedFunctions.h"
using namespace std;

void insertionSorts(std::vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound) {
    int size = arr.size();

    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];

            drawBars(window, arr, j + 1, false);
            sf::sleep(sf::milliseconds(100));
            swapSound.play();

            j--;
        }

        arr[j + 1] = key;

        drawBars(window, arr, i, false);
        sf::sleep(sf::milliseconds(100));
    }

    for (int i = 0; i < arr.size(); ++i) {
        drawBars(window, arr, i, true);
        sf::sleep(sf::milliseconds(10));
    }
}