#include <iostream>

int main() {
    int candleCount;
    std::cin >> candleCount;

    int tallestHeight;
    std::cin >> tallestHeight;
    int tallestCount = 1;

    for (int i = 1; i < candleCount; ++i) {
        int height;
        std::cin >> height;

        // Reset the count for a new maximum; otherwise count another tallest candle.
        if (height > tallestHeight) {
            tallestHeight = height;
            tallestCount = 1;
        } else if (height == tallestHeight) {
            ++tallestCount;
        }
    }

    std::cout << tallestCount << '\n';
    return 0;
}
