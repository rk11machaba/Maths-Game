#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

class Player {
// data members
private:
	string name, phone;
	int age, score;
// function members
public:
	Player(); //default constructor
	void setPlayer(string, string, int, int); //setter

	//getters
	string getName() { return name; }
	string getPhone() { return phone; }
	int getAge() { return age; }
	int getScore() { return score; }
};

Player::Player() {
	name = "";
	phone = "";
	age = 1;
	score = 0;
}

void Player::setPlayer(string nm, string pn, int ag,int sc) {
	if (nm.size() > 0) {
		name = nm;
	}else {
		name = "PLAYER";
	}
	if (pn.size() == 10) {
		phone = pn;
	}
	else {
		phone = "1234567890";
	}
	if (ag > 10) {
		age = ag;
	}
	else {
		age = 10;
	}
	if (sc  >= 0) {
		score = sc;
	}
	else
	{
		score = 0;
	}
}

void PopulateRecord(Player Pr, string filename) {
	// code...
	ifstream inFile;
	inFile.open(filename);
	string line = "";
	string nm, pn;
	int ag, sc;
	int pos = 0;


	if (!inFile.good()) {
		cout << "Failed to open the file..." << endl;
	}
	else
	{
		do
		{
			getline(inFile, line);

			// getting name
			pos = line.find(",");
			nm = line.substr(0, pos);
			line = line.erase(0, pos + 1);

			// getting phone number
			pos = line.find(",");
			pn = line.substr(0, pos);
			line = line.erase(0, pos + 1);

			// getting age
			pos = line.find(",");
			ag = atoi(line.substr(0, pos).c_str());
			line = line.erase(0, pos + 1);

			// getting score
			sc = atoi(line.c_str());

			cout << nm << "\t" << pn << "\t" << ag << "\t" << sc << endl;

			Pr.setPlayer(nm, pn, ag, sc);
		} while (!inFile.eof());
	}

}


int main() {
	// declare variables
	Player Pr;
	string name, phone;
	int age;
	int menu;
	string filename = "record.txt";
	
	/*cout << "Hello World" << endl;
	PopulateRecord(Pr, filename);
	cout << "Hello World" << endl;*/

	cout << "***Maths Game***" << endl;
	cout << "Please enter your details." << endl;
	cout << "--------------------------" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Phone number: ";
	cin >> phone;
	cout << "Age: ";
	cin >> age;

	cout << "\n***\tMENU\t***" << endl;
	cout << "Play game (1: Yes/ 2: No): ";
	cin >> menu;

	if (menu == 1) {
		int score = 0;
		int answer, ans;
		int num1, num2, num3, num4;
		int add_ans, subtr_ans, by_ans, mod_ans;
		double div_ans;
		bool gameOver = false;

		srand(time(0));

		do {
			num1 = 1 + (rand() % 11);
			num2 = 1 + (rand() % 11);
			num3 = 5 + (rand() % 11);
			num4 = 1 + (rand() % 5);

			cout << num1 << " + " << num2 << ": ";
			cin >> add_ans;
			cout << num1 << " - " << num2 << ": ";
			cin >> subtr_ans;
			cout << num1 << " X " << num2 << ": ";
			cin >> by_ans;
			cout << num3 << " / " << num4 << ": ";
			cin >> div_ans;
			cout << num3 << " % " << num4 << ": ";
			cin >> mod_ans;
	
			if (add_ans == (num1 + num2)) 
				score = score + 1;
			else
				gameOver = true;
			
			if (subtr_ans == (num1 - num2))
				score = score + 1;
			else
				gameOver = true;
			
			if (by_ans == num1 * num2)
				score = score + 1;
			else
				gameOver = true;

			if (div_ans == (num3 / num4))
				score = score + 1;
			else
				gameOver = true;

			if (mod_ans == (num3 % num4))
				score = score + 1;
			else
				gameOver = true;
				
		} while (gameOver==false);
		cout << score << endl;

		// open the existing file
		ifstream inFile;
		inFile.open(filename);
		string line = "";
		string oldContent;

		getline(inFile, line);
		
		oldContent = line;

		// update the existing file
		ofstream outFile(filename);

		outFile << oldContent << endl;
		outFile << name << "," << phone << "," << age << "," << score << endl;

	}else
	if (menu == 2) {
		exit(1);
	}
	system("pause");
}