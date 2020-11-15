#include <iostream>
#include <random>
#include <functional>
#include <algorithm>
#include "validator.hpp"
#include "vecimpl.hpp"

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(1, 128);
auto gen = bind(dist, mt);
int arr[1000];

void randArray(int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = gen();
    }
}

bool task(int totalTasks, int taskNo, int arrSize) {
    int popCount = arrSize / 3;

    cout << "Task (" << taskNo << "/" << totalTasks << ") ... ";

    Clear();

    randArray(arrSize);
    for (int i = 0; i < arrSize; i++) {
        PushBack(arr[i]);
    }

    if (Size() != arrSize) {
        goto TASKFAILED;
    }

    for (int i = 0; i < arrSize; i++) {
        if (GetValue(i) != arr[i]) {
            goto TASKFAILED;
        }
    }

    for (int i = 0; i < popCount; i++) {
        PopBack();
    }

    arrSize -= popCount;

    if (Size() != arrSize) {
        goto TASKFAILED;
    }

    for (int i = 0; i < arrSize; i++) {
        if (GetValue(i) != arr[i]) {
            goto TASKFAILED;
        }
    }

    Sort();

    if (!is_sorted(Begin(), End())) {
        goto TASKFAILED;
    }

    cout << "Success!" << endl;
    return true;

TASKFAILED:
    cout << "Failed" << endl;
    return false;
}

void Validate() {

    int tasks = 4;

    // Task 1
    if (!task(tasks, 1, 64)) {
        goto FAILED;
    }

    // Task 2
    if (!task(tasks, 2, 128)) {
        goto FAILED;
    }

    // Task 3
    if (!task(tasks, 3, 256)) {
        goto FAILED;
    }

    // Task 4
    if (!task(tasks, 4, 512)) {
        goto FAILED;
    }

    cout << "All Tasks are successfully passed. Good job!" << endl;
    return;

FAILED:
    cout << "Try again!" << endl;
}
