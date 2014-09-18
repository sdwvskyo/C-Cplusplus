#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdlib.h>
#include <algorithm>
#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

using namespace std;

double getTime();
void loadNum(FILE *fp, vector<int> &vec);
bool binarySeek(const vector<int> &vec, int key);

int main(int argc, const char *argv[])
{
	double timeBegin = getTime();
	FILE *fp1 = fopen("largeW.txt", "r");
	FILE *fp2 = fopen("largeT.txt", "r");
	vector<int> largeW;
	vector<int>	largeT;
	loadNum(fp1, largeW);
	loadNum(fp2, largeT);
	sort(largeT.begin(), largeT.end());
	for (size_t i = 0; i < largeW.size(); ++i) {
		if(binarySeek(largeT, largeW[i]))
			cout << largeW[i] << endl;
	}
	fclose(fp1);
	fclose(fp2);
	double timeEnd = getTime();
	cout << timeEnd - timeBegin << endl;
	return 0;
}

bool binarySeek(const vector<int> &vec, int key)
{
	int start = 0;
	int end = vec.size() - 1;
	int mid;
	while (start <= end) {
		mid = (end + start) / 2;
		if (vec[mid] == key)
			return true;
		else if (key < vec[mid])
			end = mid - 1;
		else 
			start = mid + 1;
	}
	return false;
}

void loadNum(FILE *fp, vector<int> &vec)
{
	char buf[32];
	int n;
	while (memset(buf, 0, 32), fgets(buf, 32, fp)) {
		n = atoi(buf);
		vec.push_back(n);
	}
}

double getTime()
{
	timeval tm;
	memset(&tm, 0, sizeof tm);
	if(gettimeofday(&tm, NULL) == -1)
		ERR_EXIT("gettimeofday");
	double res = 0.0;
	res += tm.tv_sec;
	res += tm.tv_usec / (double)1000000;
	return res;
}
