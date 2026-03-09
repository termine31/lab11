
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int main()
{
	cout << "Введите номер теста: \n"; 
	int num;
	cin >> num;
	string test = "test" + to_string(num) + ".txt";

	ifstream filename(test);


    vector<string> words;
    string word;

    while (filename >> word) {
        words.push_back(word);
    }

    filename.close();

 
    cout << "Слова:" << endl;
    for (int i = 0; i < words.size(); i++) {
        cout << i + 1 << ". " << words[i] << endl;
    }
	



}

