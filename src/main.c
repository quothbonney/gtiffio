#include "tiffio.h"
#include "rqs.h"

int main(int argc, char* argv[])
{
	struct rqs_filename_info file_d = rqs_get_filenames();
	rqs_read_tags(file_d);
	
	return 0;
}

