#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <thread>


//algos
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "SharedFunctions.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "RadixSort.h"

using namespace std;


int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorts");

    vector<int> bars(windowWidth / barWidth);

    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

    sf::SoundBuffer swapBuffer = createSwapSound();
    sf::Sound swapSound;
    swapSound.setBuffer(swapBuffer);
    
    bubbleSorts(bars, window, swapSound);

    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

    selectionSort(bars, window, swapSound);

    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

    insertionSorts(bars, window, swapSound);

    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

   mergeSort(bars, window, swapSound);

    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

    quickSort(bars, 0, bars.size() - 1, window, swapSound, true);
    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

    heapSort(bars, window, swapSound);
    for (int& bar : bars) {
        bar = rand() % (windowHeight - 10) + 10;
    }

    radixSort(bars, window, swapSound);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}