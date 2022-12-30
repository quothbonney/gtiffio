#include "tiffio.h"
#include "rqs.h"

int main(int argc, char* argv[])
{
	rqs_listDataDir();
	/*
	TIFF* tif = TIFFOpen(argv[1], "r");
	if (tif) {
	uint32 w, h;
	size_t npixels;
	uint32* raster;
	double* f = 0;
	uint16 dat;

	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &w);
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &h);

	TIFFGetField(tif, 33550, &dat, &f);
	TIFFGetField(tif, 33550, &dat, &f);
	
	npixels = w * h;
	printf("Width \t%i\n", w);
	printf("Height\t%i\n", h);
	printf("Res\t%f %f\n", f[0], f[1]);
	raster = (uint32*) _TIFFmalloc(npixels * sizeof (uint32));
	if (raster != NULL) {
		if (TIFFReadRGBAImage(tif, w, h, raster, 0)) {
		}
		_TIFFfree(raster);
	}
	printf("%i", 0xa481);
	TIFFClose(tif);
	}
	*/
	return 0;
}

