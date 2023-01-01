//
// Created by quothbonney on 12/28/22.
//

#ifndef RQS_H
#define RQS_H
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "tiffio.h"
#include "rqs_structures.h"

struct rqs_filename_info {
	char** filenames;
	size_t size;
};

struct rqs_filename_info rqs_get_filenames();

struct RQS_transformData* rqs_read_tags(struct rqs_filename_info file_data);

#endif //OPENRQS_RQS_H
