#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const int count = 5;
    std::vector<long long> values(count);
    long long total = 0;

    for (long long& value : values) {
        std::cin >> value;
        total += value;
    }

    // Excluding the largest or smallest value gives the two four-item sums.
    const auto bounds = std::minmax_element(values.begin(), values.end());
    const long long minimumSum = total - *bounds.second;
    const long long maximumSum = total - *bounds.first;

    std::cout << minimumSum << ' ' << maximumSum << '\n';
    return 0;
}
