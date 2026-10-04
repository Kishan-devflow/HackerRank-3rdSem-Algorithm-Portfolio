#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int toyCount;
    long long budget;
    std::cin >> toyCount >> budget;

    std::vector<long long> prices(toyCount);
    for (long long& price : prices) {
        std::cin >> price;
    }

    // The cheapest-first greedy choice maximizes how many toys fit the budget.
    std::sort(prices.begin(), prices.end());

    int purchasedCount = 0;
    for (long long price : prices) {
        if (price > budget) {
            break;
        }
        budget -= price;
        ++purchasedCount;
    }

    std::cout << purchasedCount << '\n';
    return 0;
}
