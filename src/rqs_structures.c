#include "rqs_structures.h"

struct RQS_llPoint make_ll(double lat, double lon) {
	struct RQS_llPoint ll = {lat, lon};
	return ll;
}
