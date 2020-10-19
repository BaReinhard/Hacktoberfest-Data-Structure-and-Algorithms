/*
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value 
in the knapsack.
*/

#include <bits/stdc++.h>

using namespace std;

class Item {
   public:
    int val;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.val / a.weight;
    double r2 = (double)b.val / b.weight;
    return r1 > r2;
}

int main() {
    int n, w;
    cin >> n >> w;
    Item arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].val;
        cin >> arr[i].weight;
    }

    sort(arr, arr + n, compare);

    int current_weight = 0;
    double final_value = 0;

    for (int i = 0; i < n; i++) {
        if (current_weight + arr[i].weight <= w) {
            current_weight += arr[i].weight;
            final_value += arr[i].val;
        } else {
            int weight_remain = w - current_weight;
            final_value += arr[i].val * ((double)weight_remain / arr[i].weight);
            break;
        }
    }

    cout << final_value << endl;

    return 0;
}