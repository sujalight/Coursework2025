#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

void addPerson(vector<string>& names, map<string, int>& ageMap, const string& name, int age) {
    names.push_back(name);
    ageMap[name] = age;
}

void findPeopleAboveAge(const map<string, int>& ageMap, int ageThreshold) {
    cout << "\n---------------------------------------------------\n";
    cout << "People above " << ageThreshold << " years of age are listed below:\n";

    for (const auto& entry : ageMap) {
        if (entry.second > ageThreshold) {
            cout << entry.first << " (" << entry.second << " years)\n";
        }
    }
}

void displaySortedNames(vector<string>& names) {
    sort(names.begin(), names.end());
    cout << "\n---------------------------------------------------\n";
    cout << "Sorted names alphabetical wise:\n";
    for (const string& name : names) {
        cout << name << endl;
    }
}

int main() {
    vector<string> names;
    map<string, int> ageMap;

    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int age;

        cout << "Enter name: ";
        cin >> name;

        while (true) {
            try {
                cout << "Enter age: ";
                cin >> age;

                if (cin.fail()) {
                    throw invalid_argument("Error! Enter age");
                }
                break;
            } catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << e.what() << endl;
            }
        }
        addPerson(names, ageMap, name, age);
    }

    int ageThreshold;
    cout << "Enter the age you want to get the people above that age: ";
    cin >> ageThreshold;
    findPeopleAboveAge(ageMap, ageThreshold);

    displaySortedNames(names);

    cout << "\n---------------------------------------------------";
    cout << "End of the Program" << endl;

    return 0;
}
