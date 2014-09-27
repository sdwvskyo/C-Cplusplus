#ifndef BUFFER_H_
#define BUFFER_H_ 

#include <iostream>
#include <string>
#include <vector>

class Buffer{
	public:
		Buffer();
		~Buffer();
		
		void moveCursorForward();
		void moveCursorBackward();

		void moveCursorTostart();
		void moveCursorToEnd();

		void insertCharacter(char ch);
		void deleteCharacter();

		void display();
	private:
		vector<char> chars;
		int cursor;
		//Stack<char> before, after;
};

#endif  /*BUFFER_H_*/
