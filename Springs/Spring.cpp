#include "functions.h"

Spring::Spring(float a, float kc, float d, std::string t) : iH1(-1), iH2(-1){

	anchorL = a;
	k = kc;
	damping = d;

	test = t;
}

Spring::Spring() : iH1(-1), iH2(-1){
	anchorL = 0.0f;
	k = 0.0f;
	damping = 0.0f;
}