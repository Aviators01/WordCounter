/*
Timothy Queva
CS2010 Lab4
October 5, 2020
*/

#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//Dictionary output
//Note: Since we are only interested in reading-not editing-this only has a copy of the vector.
int doutput(vector<string> word,vector<int> wtotals){
	//Heading prompts for user
	cout << string("/------------\\ \n")
	+ ("| Dictionary |\n")
	+ ("\\------------/ \n \n ")
	+ ("Word		Frequency\n")
	+ ("-------------------------") << endl;
	
	//Outputs word and their total
	for(int i=0;i<word.size();i++){
		cout << setw(15) << left << word[i] << "	" << setw(8) << right << wtotals[i] << endl;
	}
}

//Histogram output
//Note: Since we are only interested in reading-not editing-this only has a copy of the vector.
int houtput(vector<string> word,vector<int> wtotals){
	//Heading prompts for user
	cout << string("/------------\\ \n")
	+ ("| Histogram |\n")
	+ ("\\------------/ \n") << endl;
	
	//n^2 algorithm to output stars to represent word total
	for(int i=0;i<word.size();i++){
		cout << setw(15) << left << word[i] << "	      |";
		for(int star=0;star<wtotals[i];star++){
			cout << "*";
		}
		cout << endl;
	}
}


int main(){
	string w;
	char ch;
	int index=0;
	bool found=false;
	bool cbuilding=false;
	vector<int> wtotals;
	vector<string> word;
	
	
	cout << "Welcome to the word counter program" << endl;
	cout << "Please enter your words: " << endl;
	
	/*While loop executes until end of file (cin.good()) or input. Each loop cycle, a character is
	read and added to string w if it is in the English alphabet. Once a blank, digit, or punctuation
	character is read, character is not added to string w in that loop. Instead, string w is checked against
	string vector. If found, corresponding word total is incremented. If not found, string w's word is
	added to string vector and corresponding word total is set to 1. Then, string w is cleared and loop
	cycle begins again.
	*/
	while(cin.good()){
		//Characters input to word section
		ch=cin.get();
		ch=tolower(ch);
		if(isalpha(ch)){
			w.push_back(ch);
			cbuilding=true;		//this line enables else condition to executes once we finished building word
		}
		//else if code section executes once non-alphabet character is encountered
		else if(cbuilding){ 
			/*For loop checks string w against words in string vector. Increments corresponding word
			total and breaks loop if word is found.*/
			for(int i=0;i<word.size();i++){
				if(w == word[i]){
					wtotals[i]++;
					found=true;
					break;
				}
			}
			//if statement adds string w's word to string vector if word wasn't found in string vector.
			if(!found){
				word.push_back(w);
				wtotals.push_back(1);
			}
			
			//Resets everything for next loop cycle
			found = false;
			w.clear();
			cbuilding=false;	//This line resets bool variable and prevents an empty string from being added in the case of two spaces.
		}
	}
	
	//Calls functions to output results to user
	cout << "Results are as follows:" << endl;
	::doutput(word,wtotals);
	cout << "\n\n";
	::houtput(word,wtotals);
}