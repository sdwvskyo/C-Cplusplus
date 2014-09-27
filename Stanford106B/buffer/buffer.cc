#include "buffer.h"

using namespace std;

Buffer::Buffer()
{
	cursor = 0;
}

Buffer::~Buffer()
{

}
		
void Buffer::moveCursorForward()
{
	if (cursor < chars.size())
		cursor++;
}

void Buffer::moveCursorBackward()
{
	if (cursor > 0)
		cursor--;
}

void Buffer::moveCursorTostart()
{
	cursor = 0;
}
void moveCursorToEnd()
{
	cursor = chars.size();
}

void Buffer::insertCharacter(char ch)
{
	chars.insert(cursor, ch);
	cursor++;
}
void deleteCharacter()
{
	chars.erase(cursor);
	cursor--;
}

void display()
{
	for (size_t i = 0; i < chars.size(); i++) {
		cout << chars[i] << endl;
	}
	for (size_t i = 0; i < cursor; i++) {
		cout << " ";
	}
	cout << "-";
}

