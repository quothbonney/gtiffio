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
	int xsize;
	int ysize;
};


