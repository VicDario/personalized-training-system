#include "exercise.h"
#include <iostream>
using namespace std;

Exercise::Exercise() {
    this->code = "";
    this->name = "";
    this->type = "";
    this->intensity = "";
    this->durationMinutes = 0;
    this->description = "";
    this->weekUsed = 0;
}

Exercise::~Exercise() {
    cout << "[destroyed] " << name << endl;
}

// Setters
void Exercise::setCode(string code)             { this->code = code; }
void Exercise::setName(string name)             { this->name = name; }
void Exercise::setType(string type)             { this->type = type; }
void Exercise::setIntensity(string intensity)   { this->intensity = intensity; }
void Exercise::setDurationMinutes(int duration) { this->durationMinutes = duration; }
void Exercise::setDescription(string description) { this->description = description; }
void Exercise::setWeekUsed(int week)            { this->weekUsed = week; }

// Getters
string Exercise::getCode()           { return this->code; }
string Exercise::getName()           { return this->name; }
string Exercise::getType()           { return this->type; }
string Exercise::getIntensity()      { return this->intensity; }
int    Exercise::getDurationMinutes(){ return this->durationMinutes; }
string Exercise::getDescription()    { return this->description; }
int    Exercise::getWeekUsed()       { return this->weekUsed; }

void Exercise::inputData() {
    string temp;
    int num;

    cout << "Code: ";        getline(cin, temp); this->setCode(temp);
    cout << "Name: ";        getline(cin, temp); this->setName(temp);
    cout << "Type (Cardiovascular/Strength): "; getline(cin, temp); this->setType(temp);
    cout << "Intensity (Basic/Intermediate/Advanced/High Performance): ";
    getline(cin, temp); this->setIntensity(temp);
    cout << "Duration (min): "; cin >> num; cin.ignore();
    this->setDurationMinutes(num);
    cout << "Description: "; getline(cin, temp); this->setDescription(temp);
}

void Exercise::displayData() {
    cout << "Exercise info: " << endl;
    cout << "Code:        " << getCode() << endl;
    cout << "Name:        " << getName() << endl;
    cout << "Type:        " << getType() << endl;
    cout << "Intensity:   " << getIntensity() << endl;
    cout << "Duration:    " << getDurationMinutes() << " min" << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Week used:   " << getWeekUsed() << endl;
}
