#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sorting {
private:
    vector<int> numbers;

public:
    void readNumbers() {
        int n;
        cout << "Enter the number of elements : ";
        cin >> n;

        cout << "Enter " << n << " integers separated by spaces:";
        for (int i = 1; i <= n; ++i) {
            int num;
            cin >> num;
            numbers.push_back(num);
        }
    }

    void displayNumbers() {
        sort(numbers.begin(), numbers.end());
        cout << "The numbers you have entered are sorted in ascending order as:";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    sorting s1;
    s1.readNumbers();
    s1.displayNumbers();
    return 0;
}
