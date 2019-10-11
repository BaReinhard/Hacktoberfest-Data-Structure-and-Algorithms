#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<double> arr;
    arr.push_back(2.02);
    arr.push_back(1.02);
    arr.push_back(3.03);
    std::sort(arr.begin(), arr.end());

    for (auto x : arr) 
        std::cout << x << "\n";

    return 0;
}
