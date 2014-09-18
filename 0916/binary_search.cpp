#include <iostream>
#include <string>
#include <vector>

bool binary_search(vector<int> &text, omt sought)
{
	auto beg = text.begin();
	auto end = text.end();
	while (mid != end) {
		auto mid = (beg + end) / 2;
		if (sought < *mid) {
			end = mid;
		} else if (sought > *mid){
			beg = mid + 1;
		} else {
			return true;
		}
	}
	return false;
}
