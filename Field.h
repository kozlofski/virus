#ifndef _Field_
#define _Field_

#include <iostream>
#include "stdlib.h"
#include "Animation.h"
#include <cmath>

#define HEALTHY 3
#define IMMUNE 5
#define ILL 0
#define DEAD 6

#define DEATH_RATE 0.3
#define INFECTION_PROBABILITY 0.3

class Field {
    public:
        int state;
				bool infected;
				int illness;
        Field();
				Field(int st);

        ~Field();

				void getInfected();
				void patientZeroGetIll();
				void getIll();
				void checkImmunity();
				void die();
				
        void draw();
				
};

#endif