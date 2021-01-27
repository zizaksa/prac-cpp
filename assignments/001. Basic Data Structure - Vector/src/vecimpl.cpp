#include <vector>
#include <algorithm>
#include "vecimpl.hpp"

using namespace std;

// Vector Declaration
vector<int> vec;

void PushBack(int value) {
    vec.push_back(value);
}

void PopBack() {
    vec.pop_back();
}

int Size() {
    return vec.size();
}

int GetValue(int idx) {
    return vec[idx];
}

void Clear() {
    vec.clear();
}

void Sort() {
    sort(vec.begin(),vec.end());
}

vector<int>::iterator Begin() {
    return vec.begin();
}

vector<int>::iterator End() {
    return vec.end();
}