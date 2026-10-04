#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& values, int target) {
    // The input must be sorted in ascending order.
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;

    while (left <= right) {
        const int middle = left + (right - left) / 2;

        if (values[middle] == target) {
            return middle;
        }
        if (values[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    int size;
    int target;
    std::cin >> size >> target;

    std::vector<int> values(size);
    for (int& value : values) {
        std::cin >> value;
    }

    std::cout << binarySearch(values, target) << '\n';
    return 0;
}
