#include <iostream>
#include <vector>

void printArray(const std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
}

int main() {
    int size;
    std::cin >> size;

    std::vector<int> values(size);
    for (int& value : values) {
        std::cin >> value;
    }

    const int valueToInsert = values[size - 1];
    int index = size - 2;

    // Shift larger sorted-prefix values right, showing every intermediate state.
    while (index >= 0 && values[index] > valueToInsert) {
        values[index + 1] = values[index];
        printArray(values);
        --index;
    }

    values[index + 1] = valueToInsert;
    printArray(values);
    return 0;
}
