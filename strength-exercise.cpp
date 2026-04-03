#include "strength-exercise.h"
#include <iostream>
using namespace std;

StrengthExercise::StrengthExercise() {
    this->weightKg = 0.0;
    this->setType("Strength");
}

void   StrengthExercise::setWeight(double weight) { this->weightKg = weight; }
double StrengthExercise::getWeight()              { return this->weightKg; }

void StrengthExercise::inputData() {
    double w;
    Exercise::inputData();
    cout << "Suggested weight (kg): "; cin >> w; cin.ignore();
    this->setWeight(w);
}

void StrengthExercise::displayData() {
    cout << "--- Strength Exercise ---" << endl;
    Exercise::displayData();
    cout << "Suggested weight: " << getWeight() << " kg" << endl;
}
