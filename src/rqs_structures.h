#include <stdint.h>

#ifndef RQS_STRUCTURES_H
#define RQS_STRUCTURES_H

struct RQS_llPoint{
	double lat;
	double lon;
};

struct RQS_nPoint{
	int x;
	int y;
	int r;
};

struct RQS_transformData{
	int index;
	const char* fname;
	struct RQS_llPoint origin;
	struct RQS_llPoint res;
	uint32_t xsize;
	uint32_t ysize;
	uint32_t** data;
};

struct RQS_llPoint make_ll(double lat, double lon); 

#endif
