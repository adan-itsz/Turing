
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>



using namespace std;

class Maquina{
private:
typedef std::map<int, char> Cinta;
Cinta cinta;
int cle = 1;
int limite = 1;
public:
void print() {
	for (int i = 0; i < cinta.size(); i++)
	{
		
		if (cle == i) {
			cout << '.';
		}
		cout << cinta[i];
	}
	cout << endl;
}

void tape() {
	cinta[0] = ' ';
	cinta[1] = '@';
	
}

bool leng(char c) {
	int caracter = c;
	if ((caracter >= 48 && caracter <= 57 )||( caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)) {
	
		return true;
	}
	return false;


}



void right(int n = 1) {
	cle += n;
	print();
}

void left(int n= 1) {
	cle -= n;
	print();
}

void sigma(char s) {
	cinta[cle] = s;
	print();
}

void left_to(char s) {
	int j = cle;
	while (cinta[j] != s && j >= 0) {
		left();
		j--;
	}
}

void right_to(char s) {
	int j = cle;
	while (cinta[j] != s && j<=limite) {
		right();
		j++;
	}
	cinta[j + 1];
}


void push(char val) {
	if (leng(val)) {
		cinta[limite + 1];
		right_to(' ');
		sigma(val);
		left_to('@');
		limite++;
	}
	else {
		
	}
}

void pop() {
	right_to(' ');
	left();
	char val = cinta[cle];
	limite--;
	sigma(' ');
	left_to('@');
	left();
	sigma(val);
	sigma(' ');
	right();
}

void finish() {
	int aux=limite;
for(int i=1;i<aux;i++){
	pop();
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
	Maquina mt;
	mt.tape();
	mt.read();
	system("PAUSE");
	return 0;
}
