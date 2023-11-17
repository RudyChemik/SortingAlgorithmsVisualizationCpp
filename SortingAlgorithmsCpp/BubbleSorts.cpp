#include "SharedFunctions.h"
using namespace std;

void bubbleSorts(vector<int>& arr, sf::RenderWindow& window, sf::Sound& swapSound) {

    int size = arr.size();
    bool swapped;
    bool sorted = false;

    do {
        swapped = false;
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
                drawBars(window, arr, i, false);
                sf::sleep(sf::milliseconds(10));

                swapSound.play();
            }
        }
        if (!swapped) {
            sorted = true;
        }
    } while (swapped);

    for (int i = 0; i < arr.size(); ++i) {
        drawBars(window, arr, i, sorted);
        sf::sleep(sf::milliseconds(10));
    }
}
