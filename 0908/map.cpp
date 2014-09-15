/*************************************************************************
	> File Name: map.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  9/ 8 21:04:04 2014
 ************************************************************************/

#include<iostream>
using namespace std;

char mostFrequentCharacter(ifstream &in, int &numOccurrences)
{
	Map<int> charFrequencies;
	numOccurrences = 0;

	int nextChar;
	while ((nextChar = in.get()) != EOF) {
		string foundChar = "";
		foundChar += char(nextChar);

		int frequency = 1;
		if (charFrequencies.containsKey(foundChar))
			frequency = charFrequencies[foundChar] + 1;
		charFrequencies[foundChar] = frequency;
	}

	Mao<int>::Iterator it = charFrequencies.iterator;
	string maxCharacter = "";

	while (it.hasNext()) {
		string character = it.next();
		int frequency = charFrequencies[character];

		if (frequency > numOccurrences) {
			maxCharacter = character;
			numOccurrences = frequency;
		}
	}
	return maxCharacter[0];
}

struct pointT {
	int x;
	int y;
};

struct cityT {
	string name;
	pointT coordinates;
};

Vector<cityT> cities;
Map<string> nameMap;
for (int cityIndex = 0; cityIndex < cities.size(); cityIndex++) {
	cityT curCity = cities[cityIndex];
	string key = IntegerToString(cities[cityIndex].coordinates.x) + "-" +
				IntegerToString(cities[cityIndex].coordinates.y);
	nameMap.add(key, curCity);
}

