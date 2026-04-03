#include "cardiovascular-exercise.h"
#include <iostream>
using namespace std;

CardiovascularExercise::CardiovascularExercise() {
    this->heartRate = 0;
    this->setType("Cardiovascular");
}

void CardiovascularExercise::setHeartRate(int rate) { this->heartRate = rate; }
int  CardiovascularExercise::getHeartRate()         { return this->heartRate; }

void CardiovascularExercise::inputData() {
    int r;
    Exercise::inputData();
    cout << "Recommended heart rate (bpm): "; cin >> r; cin.ignore();
    this->setHeartRate(r);
}

void CardiovascularExercise::displayData() {
    cout << "--- Cardiovascular Exercise ---" << endl;
    Exercise::displayData();
    cout << "Heart rate: " << getHeartRate() << " bpm" << endl;
}
