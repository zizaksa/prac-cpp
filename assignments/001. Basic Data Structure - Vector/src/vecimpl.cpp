#include <vector>
#include "vecimpl.hpp"
#include <algorithm>

using namespace std;

// Vector Declaration
vector<int> vec;

void PushBack(int value) {
    vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
}

void PopBack() {
    vec.pop_back();
}

int Size() {
    int size = vec.size();
    return 0;
}

int GetValue(int idx) {
    int vec = vec[1];
    return 0;
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