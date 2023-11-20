#include "Field.h"

Field::Field() : state(HEALTHY), infected(false), illness(0) {}
Field::~Field() {}

void Field::getInfected() {
	if ((rand() % 1000 / 1000.0 < INFECTION_PROBABILITY) && state == HEALTHY) {
		infected = true;		
	}
}

void Field::patientZeroGetIll() {
	state = ILL;
	illness = 1.0 / sqrt(DEATH_RATE);
}

void Field::getIll() {
	state = ILL;	
	infected = false;
	illness = 1.0 / sqrt(DEATH_RATE);
}

void Field::checkImmunity() {
	if (illness == 0) {
		state = IMMUNE;
	}
}

void Field::die() {
	if ((rand() % 1000) / 1000.0 < DEATH_RATE) {
		state = DEAD;
	}
}
