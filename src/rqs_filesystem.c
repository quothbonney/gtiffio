#include "rqs.h"
#include "rqs_structures.h"
#include <tiffio.h>

#define RQS_DATA_DIR "./data/"
#define RQS_MAX_FILENAMES 500

#define TIFFTAG_GEOTIEPOINTS      33922  /* tiepoint */
#define TIFFTAG_MODELPIXELSCALE    33550  /* pixel scale */


#define STR_ENDS_WITH(S, E) (strcmp(S + strlen(S) - (sizeof(E)-1), E) == 0)

struct rqs_filename_info rqs_get_filenames()
{
	DIR* dir = opendir(RQS_DATA_DIR);
	if(!dir) {
		perror("Cannot open RQS data directory. Please execute from the project root openRQS/.");
		exit(1);
	}

	char* filenames[RQS_MAX_FILENAMES];
	size_t num_filenames = 0;
	// Iterate over the directory entries
	struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
		// Skip the "." and ".." entries
		if (entry->d_name[0] == '.' ||  !STR_ENDS_WITH(entry->d_name, "tif")) {
		  continue;
		}

		filenames[num_filenames] = malloc(strlen(entry->d_name) + 1);
		strcpy(filenames[num_filenames], entry->d_name);
		num_filenames++;

		if(num_filenames >= RQS_MAX_FILENAMES) {
			fprintf(stderr, "Maximum number of data files (500) exceeded... Ignoring after%s", entry->d_name);
			break;
		}
	}

	for (int i = 0; i < num_filenames; i++) {
		printf("%s\n", filenames[i]);
	}
	free(entry);

	struct rqs_filename_info result = {filenames, num_filenames};
	return result;
}

struct RQS_transformData* rqs_read_tags(struct rqs_filename_info file_data) {
	struct RQS_transformData file_transform[file_data.size];

	for(int elem = 0; elem < file_data.size; ++elem) {
		// Concatanate the data directory and file name to open TIFF file
		char fname[100] = RQS_DATA_DIR;
		strcat(fname, file_data.filenames[elem]);
		TIFF* tiff = TIFFOpen(fname, "r");	
		if(!tiff) {
			fprintf(stderr, "Cannot open TIFF file %s", fname);
			continue;
		}
		
		uint32_t width, height;
		double* resolution = 0;
		uint16 tmp;
		
	    char* modelType = NULL;
		double* tiepoints;
		double* tiematrix;

		TIFFGetField(tiff, TIFFTAG_GEOTRANSMATRIX, &tmp, &tiematrix);
		
		TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &width);
		TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &height);
		TIFFGetField(tiff, 33550, &tmp, &resolution);
		file_transform[elem].xsize = width;
		file_transform[elem].ysize = height;
		file_transform[elem].res = make_ll(resolution[0], resolution[1]);

			
		/*
		for(int i = 0; i < 6; ++i)
			printf("%f\n", tiematrix[i]);
		*/
	}
	return file_transform;
}
