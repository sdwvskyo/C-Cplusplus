#include "my_file.h"

int main(int argc, char *argv[])
{
//  printFile(FILENAME_SRC);
//	copyFile(FILENAME_DST, FILENAME_SRC);

	file_handle(FILENAME_DST, FILENAME_SRC);
	countLine(FILENAME_DST);	

    return 0;
}
