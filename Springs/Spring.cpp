#include "functions.h"

Spring::Spring(float a, float kc, float d) : h1(nullptr), h2(nullptr) {

	anchorL = a;
	k = kc;
	damping = d;
}

Spring::Spring() : h1(nullptr), h2(nullptr) {
	anchorL = 0.0f;
	k = 0.0f;
	damping = 0.0f;
}