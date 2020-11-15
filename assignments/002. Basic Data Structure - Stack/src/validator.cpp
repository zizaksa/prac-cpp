#include "validator.hpp"

#include <iostream>
#include <string>
#include "browser.hpp"

using namespace std;

#define NUMPAGES 10

string pages[NUMPAGES] = {
    "Cras rutrum, ante et egestas volutpat, dui ex.",
    "Nulla sit amet aliquam est. Nullam eu lacus.",
    "Cras hendrerit tempor sagittis. Integer ac purus id.",
    "Proin pulvinar odio vitae felis pretium condimentum. Vivamus",
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
    "Vivamus sit amet massa lobortis neque aliquet egestas.",
    "Integer arcu odio, interdum quis dapibus vel, lacinia.",
    "Integer malesuada, ex nec pharetra sodales, nisl ante.",
    "Cras laoreet finibus nibh a consectetur. Ut gravida.",
    "In eget ipsum at turpis placerat mollis eget."
};

bool task(int totalTasks, int taskNo) {
    cout << "Task (" << taskNo << "/" << totalTasks << ") ... ";

    GoPage(pages[4]);
    GoPage(pages[9]);
    GoPage(pages[2]);

    if (GetCurrentPage() != pages[2]) {
        goto TASKFAILED;
    }

    GoBack();

    if (GetNumPages() != 2) {
        goto TASKFAILED;
    }

    try {
        GoBack();
        GoBack();
        GoBack();
        GoBack();
    } catch (exception &e) {
        goto TASKFAILED;
    }

    if (GetCurrentPage() != "Main Page") {
        goto TASKFAILED;
    }

    GoPage(pages[0]);
    GoPage(pages[1]);
    GoPage(pages[2]);
    GoPage(pages[3]);

    Clear();

    GoPage(pages[4]);
    GoPage(pages[5]);
    GoPage(pages[6]);
    GoPage(pages[7]);
    GoPage(pages[8]);
    GoPage(pages[9]);

    GoBack();
    GoBack();

    if (GetCurrentPage() != pages[7]) {
        goto TASKFAILED;
    }

    cout << "Success!" << endl;
    return true;

TASKFAILED:
    cout << "Failed" << endl;
    return false;
}

void Validate() {
    int tasks = 1;

    // Task 1
    if (!task(tasks, 1)) {
        goto FAILED;
    }

    cout << "All Tasks are successfully passed. Good job!" << endl;
    return;

FAILED:
    cout << "Try again!" << endl;
}
