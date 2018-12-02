#include<iostream>
#include<algorithm>
#include <vector>
#include <ctime>
using namespace std;
int main(){
	int numLength;
	cout << "Enter number of digits in code (3, 4, or 5): ";
	cin >> numLength;
	cout << endl;
	if (numLength == 0) {
		int code;
		cout << "Enter code: ";
		cin >> code;
		cout << endl;
		vector<int> codeVec;
		while (code > 0) {
			codeVec.push_back(code % 10);
			code = code / 10;
		}
		std::reverse(codeVec.begin(), codeVec.end());
		int numDigits;
		cout << "Enter number of digits in code: ";
		cin >> numDigits;
		cout << endl;
		if (numDigits > codeVec.size()) {
			while (codeVec.size() < numDigits) {
				codeVec.insert(codeVec.begin(), 0);
			}
		}
		cout << "Number to guess: ";
		for (int i = 0; i < codeVec.size(); i++) {
			cout << codeVec.at(i);
		}
		cout << endl;
		int  bulls=0;
		int cows;

		while (bulls != codeVec.size()) {
			int bulls = 0;
			int cows = 0;

			int guess;
			cout << "Enter guess: ";
			cin >> guess;
			cout << endl;
			
			vector<int> guessVec;
			while (guess > 0) {
				guessVec.push_back(guess % 10);
				guess = guess / 10;
			}
			std::reverse(guessVec.begin(), guessVec.end());
			if (guessVec.size()> codeVec.size()) {
				cout << "You can only enter " << codeVec.size() << " digits." << endl;
			}
			if (guessVec.size() == codeVec.size()-1) {
				guessVec.insert(guessVec.begin(), 0);
			}
			if (codeVec.size()-1 > guessVec.size())
				cout << "Each number must be different."<<endl;
			if (guessVec.size() == codeVec.size()) {
				int numRepeats = 0;
				for (int i = 0; i < guessVec.size(); i++) {
					
					for (int j = 0; j < guessVec.size(); j++) {
						if (guessVec.at(j) == guessVec.at(i))
							numRepeats++;
					}
					
					

				}
				if (numRepeats > guessVec.size()) {
					cout << "Each number must be different. " << endl;
					
				}
				else {


					for (int i = 0; i < guessVec.size(); i++) {
						if (guessVec.at(i) == codeVec.at(i))
							bulls++;
						else {
							for (int j = 0; j < guessVec.size(); j++) {
								if (guessVec.at(i) == codeVec.at(j))
									cows++;

							}
						}
					}
					if (bulls != guessVec.size()) {


						cout << bulls << " bulls" << endl;
						cout << cows << " cows" << endl;
					}
					else {
						cout << bulls<<" bulls- ";
						for (int i = 0; i < guessVec.size(); i++) {
							cout << guessVec.at(i);
						}
						cout << " is correct!" << endl;
						break;

					}
				}
			}
		}

			
	
		

	}
	else if ((numLength == 3) || (numLength == 4) || (numLength == 5)) {
		vector<int> codeVec;
		vector<int> bag = { 0,1,2,3,4,5,6,7,8,9 };
		srand(time(NULL));
		while (codeVec.size() < numLength) {
			int i = rand() % bag.size();
			int num = bag.at(i);
			codeVec.push_back(bag.at(i));
			bag.erase(find(bag.begin(), bag.end(), num));
		}
		cout << "Number to guess: ";
		for (int i = 0; i < codeVec.size(); i++) {
			cout << codeVec.at(i);
		}
		cout << endl;
		
		int  bulls = 0;
		int cows = 0;

		while (bulls != codeVec.size()) {


			int guess;
			cout << "Enter guess: ";
			cin >> guess;
			vector<int> guessVec;
			while (guess > 0) {
				guessVec.push_back(guess % 10);
				guess = guess / 10;
			}
			std::reverse(guessVec.begin(), guessVec.end());
			if (guessVec.size() - 1 > codeVec.size()) {
				cout << "You can only enter " << codeVec.size() << " digits." << endl;
			}
			if (guessVec.size() - 1 == codeVec.size()) {
				guessVec.insert(guessVec.begin(), 0);
			}
			if (codeVec.size() - 1 > guessVec.size())
				cout << "Each number must be different." << endl;
			if (guessVec.size() == codeVec.size()) {
				int numRepeats = 0;
				for (int i = 0; i < guessVec.size(); i++) {

					for (int j = 0; j < guessVec.size(); j++) {
						if (guessVec.at(j) == guessVec.at(i))
							numRepeats++;
					}



				}
				if (numRepeats > guessVec.size()) {
					cout << "Each number must be different. " << endl;

				}
				else {


					for (int i = 0; i < guessVec.size(); i++) {
						if (guessVec.at(i) == codeVec.at(i))
							bulls++;
						else {
							for (int j = 0; j < guessVec.size(); j++) {
								if (guessVec.at(i) == codeVec.at(j))
									cows++;

							}
						}
					}
					if (bulls != guessVec.size()) {


						cout << bulls << " bulls" << endl;
						cout << cows << " cows" << endl;
					}
					else {
						cout << bulls<<" bulls- ";
						for (int i = 0; i < guessVec.size(); i++) {
							cout << guessVec.at(i);
						}
						cout << " is correct!" << endl;
						break;

					}
				}
			}
		}



	}
	else
		cout << "Not a valid number";
	system("pause");
}

	