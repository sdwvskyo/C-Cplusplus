#include "time.h"
#include "stdlib.h"
int main(void)
{
	time_t t;
	struct tm *gmt, *area;
	tzset(); /*tzset()*/
	t = time(NULL);
	area = localtime(&t);
	printf("Local time is: %s", (char *)asctime(area));
	gmt = gmtime(&t);
	printf("GMT is: %s", (char *)asctime(gmt));
	return 0;
}
