#include "cardiovascular-exercise.h"
#include "strength-exercise.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<Exercise*> catalog;

    CardiovascularExercise *c1 = new CardiovascularExercise();
    c1->setCode("C001");
    c1->setName("Treadmill run");
    c1->setIntensity("Intermediate");
    c1->setDurationMinutes(30);
    c1->setDescription("Running at moderate pace");
    c1->setHeartRate(140);
    catalog.push_back(c1);

    StrengthExercise *f1 = new StrengthExercise();
    f1->setCode("F001");
    f1->setName("Bench press");
    f1->setIntensity("Advanced");
    f1->setDurationMinutes(15);
    f1->setDescription("Lifting barbell lying on flat bench");
    f1->setWeight(60.0);
    catalog.push_back(f1);

    for (Exercise *e : catalog) {
        e->displayData();
        cout << endl;
    }

    for (Exercise *e : catalog) {
        delete e;
    }

    return 0;
}
