#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    int a[3];
    std::string line;
    getline(cin, line);

    int len = line.size();
    int space1 = line.find(" ");
    string witch1 = line.substr(0, space1);
    line = line.substr(space1 + 1, len);
    len = line.size();
    int space2 = line.find(" ");
    string witch2 = line.substr(0,space2);
    string witch3 = line.substr(space2 + 1, len);
    a[0] = stoi(witch1);
    a[1] = stoi(witch2);
    a[2] = stoi(witch3);

    std::map<int, int> map;
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (int i = 0; i < 3; ++i) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
        int inside = map[a[i]];
        if (inside != 0)
            map[a[i]] = ++inside;
        else
            map[a[i]] = 1;
    }

    int diff[3] = {0, 0, 0};
    for (int i = 0; i < 3; ++i) {
        int j = i;
        j = (j + 1) > 2 ? 0 : j + 1;
        int diff1 = a[i] > a[j] ? a[i] - a[j] : a[j] - a[i];
        j = (j + 1) > 2 ? 0 : j + 1;
        int diff2 = a[i] > a[j] ? a[i] - a[j] : a[j] - a[i];
        int minimum = diff1;
        if (diff2 < diff1) {
            minimum = diff2;
        }
        diff[i] = minimum;
    }

    for (int i = 0; i < 3; ++i) {
        int first;
        int second;
        int mapSize = map.size();
        if (mapSize < 3) {
            first = diff[i];
            second = (map[a[i]] == 1 || map[a[i]] == 3) ? 0 : 3 - mapSize;
        } else {
            if (a[i] == min || a[i] == max) {
                first = diff[i];
                second = 1;
            } else {
                first = 0;
                second = 2;
            }
        }
        cout << first << " " << second << endl;
    }
    return 0;
}



