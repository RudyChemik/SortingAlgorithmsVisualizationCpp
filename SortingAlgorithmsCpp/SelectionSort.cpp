#include "SharedFunctions.h"
using namespace std;

void selectionSort(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound) {

    int size = arr.size();

    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            drawBars(window, arr, i, false);
            sf::sleep(sf::milliseconds(100)); 

            swapSound.play();
        }
    }

    for (int i = 0; i < arr.size(); ++i) {
        drawBars(window, arr, i, true);
        sf::sleep(sf::milliseconds(10));
    }
}