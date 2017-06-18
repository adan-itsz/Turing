
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>



using namespace std;

class Tape{
private:
typedef std::map<int, char> Cinta;
Cinta cinta;
int cle = 1;
int limit = 1;
int limitL=0;
public:
Tape(){
	cinta[0] = ' ';
	cinta[1] = '@';
	
	}
void print() {
	map<int,char>::iterator it;
	for (it=cinta.begin(); it != cinta.end(); it++)
	{	
		if (cle == it->first) {
			cout << '.';
		}
		cout << cinta[it->first];
	}
	cout << endl;
}



bool leng(char c) {
	int caracter = c;
	if ((caracter >= 48 && caracter <= 57 )||( caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)) {
	
		return true;
	}
	return false;


}



void right(int n = 1) {
	if(cinta[cle]== '\0'){
		cinta[cle]=' ';
		cinta[cle+1];
		limit++;
		}
	cle += n;
	print();
	
}

void left(int n= 1) {
	if(cinta[cle]== '\0'){
		cinta[cle]=' ';
		cinta[cle-1];
		limitL--;
		}
	cle -= n;
	print();
}

void sigma(char s) {
	cinta[cle] = s;
	print();
}

void left_to(char s) {
	int j = cle;
	while (cinta[j] != s && j >= limitL) {
		left();
		j--;
	}
	cinta[j-1];
	
}

void right_to(char s) {
	int j = cle;
	while (cinta[j] != s && j<=limit) {
		right();
		j++;
	}
	cinta[j + 1];
	
	
}


void push(char val) {
	if (leng(val)) {
		right_to(' ');
		sigma(val);
		left_to('@');
		limit++;
	}
	else {
		
	}
}

void pop() {
	if(cinta.size()>2){
	right_to(' ');
	left();
	char val = cinta[cle];
	limit--;
	sigma(' ');
	left_to('@');
	left();
	sigma(val);
	right();
}
}

void finish() {
	int aux=limit;
	if(cinta.size()>2){
for(int i=1;i<aux;i++){
	pop();
	}
	left();
	sigma(' ');
	right_to('@');
	
}
}

void read() {
	char input = ' ';
	
	do {
	cin >> input;
	
		switch (input)
		{
		case 'I': {
			char value = ' ';
			cin >> value;
			print();
			push(value);
			
			break;
		}
		case 'O': {
			print();
			pop();
			
			break;
		}
		case 'X': {
			print();
			finish();
			break;
		}
		}
	} while (input != '#');
	
}

};

int main()
{
	Tape t;
	t.read();
	system("PAUSE");
	return 0;
}
