#ifndef STEP_DEFINED
#define STEP_DEFINED
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "JimmyCommon.h"

#define HALF_WIDTH 0.08
#define HALF_LENGTH 0.13

class Step {
public:
	double x, y, yaw;
	double td, lo;
	int side;

	Step(double X, double Y, double YAW, double TD, int SIDE) {
		x = X;
		y = Y;
		yaw = YAW;
		td = TD;
		lo = std::numeric_limits<double>::infinity();
		side = SIDE;
	}

	bool adjustClearOf(Step *other) {
		if(side-other->side == 0) {
			printf("Adjusting two of the same feet\n");
			exit(-1);
		}

		double os = sin(other->yaw);
		double oc = cos(other->yaw);
		double ts = sin(yaw);
		double tc = cos(yaw);

		//corners of the other foot relative to that foot
		double corners[4][2];
		corners[0][X] = oc*HALF_LENGTH-os*HALF_WIDTH;
		corners[0][Y] = os*HALF_LENGTH+oc*HALF_WIDTH;
		corners[1][X] = -oc*HALF_LENGTH-os*HALF_WIDTH;
		corners[1][Y] = -os*HALF_LENGTH+oc*HALF_WIDTH;
		corners[2][X] = -oc*HALF_LENGTH+os*HALF_WIDTH;
		corners[2][Y] = -os*HALF_LENGTH-oc*HALF_WIDTH;
		corners[3][X] = oc*HALF_LENGTH+os*HALF_WIDTH;
		corners[3][Y] = os*HALF_LENGTH-oc*HALF_WIDTH;

		//corners of the other foot relative to this foot
		double dPos[2] = {other->x-x, other->y-y};
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 2; j++)	corners[i][j] += dPos[j];
		}

		//direction the foot may slide to get clearance
		double slideAxis[2];
		if(side == LEFT) {
			slideAxis[X] = -ts;
			slideAxis[Y] =  tc;
		}
		else {
			slideAxis[X] =  ts;
			slideAxis[Y] = -tc;
		}

		//find the closest of the four corners
		double closest = -1;
		for(int i = 0; i < 4; i++) {
			double dist = corners[i][X]*slideAxis[X] + corners[i][Y]*slideAxis[Y];
			if(dist > closest)	closest = dist;
		}
		if(closest > -0.13) {
			double dist = 0.13+closest;
			printf("Dist = %g;  Sliding from {%g %g} by %g",closest, x, y, dist);
			x += slideAxis[X]*dist;
			y += slideAxis[Y]*dist;
			printf(" to {%g %g}\n",x,y);
		}

	}
};

#endif
