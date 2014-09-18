/*************************************************************************
	> File Name: set.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 一  9/ 8 22:31:52 2014
 ************************************************************************/

#include<iostream>
using namespace std;

int compareeEntry(entryT one, entryT two)
{
	if (one.lastName < two.lastName)
		return -1;
	else if (one.lastName > two.lastName)
		return 1;
	else if (one.firstName < two.firstName)
		return -1;
	else if (one.firstName > two.firstName)
		return 1;
	else 
		return 0;
}

set<entryT> addresses(compareeEntry);

int compareeStringCaseInsensitive(string one, string two)
{
	string lowerOne = convertToLowerCase(one);
	string lowerTwo = convertToLowerCase(two);
	if (lowerOne < lowerTwo)
		return -1;
	else if (lowerOne > lowerTwo)
		return 1;
	else 
		return 0;
}

set<string> caseInsensitiveSet(compareeStringCaseInsensitive);


/**************************************************************/

struct pairT {
	string first;
	string second;
};

int pairTCmpFn(pairT one, pairT two)
{
	if (one.first == two.first && one.second == two.second)
		return 0;
	else if (one.first < tow.first)
		return -1;
	else if (one.first == two.first && one.second < two.second)
		return -1;
	else 
		return 1;
}

Set<pairT> cartesianProduct(Set<string> & one, Set<string> & two)
{
	Set<pairT> result(pairTCmpFn);
	Set<string>::Iterator oneIt = one.iterator;
	while (oneIt.hasNext()) {
		string first = oneIt.next();
		Set<string>::Iterator towIt = two.iterator;
		while (twoIt.hasNext()) {
			string second = towIt.next();

			pairT pair;
			pair.first = first;
			pair.second = second;

			result.add(pair);
		}
	}	
	return result;
}

