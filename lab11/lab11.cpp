
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
	
    // Создаю счетчики
    int n = words.size();
    vector<int> importance(n, 0); 
    vector<bool> isRoot(n, false); 

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            // поиск корневый слов
            if (words[j].length() >= words[i].length()) {
                bool isPrefix = true;
                for (int k = 0; k < words[i].length(); k++) {
                    if (words[i][k] != words[j][k]) {
                        isPrefix = false;
                        break;
                    }
                }

                if (isPrefix) {
                    importance[i]++;
                    isRoot[i] = true;     
                }
            }
        }
    }
    // поиск длинного 
    string longslovo = "";
    int maxlen = 0;

    for (int i = 0; i < n; i++) {
        if (isRoot[i] && words[i].length() > maxlen) {
            maxlen = words[i].length();
            longslovo = words[i];
        }
    }
    // поиск важного 
    string mimport = "";
    int maximport = -1;

    for (int i = 0; i < n; i++) {
        if (importance[i] > maximport) {
            maximport = importance[i];
            mimport = words[i];
        }
    }

    // поиск всех слов для длинного корневого слова
    vector<string> slova;

    if (!longslovo.empty()) {
        for (int j = 0; j < n; j++) {
            if (words[j] != longslovo && words[j].find(longslovo) == 0) {
                slova.push_back(words[j]);
            }
        }
    }

    // Проверка есть ли корневые
    bool hRoots = false;
    for (int i = 0; i < n; i++) {
        if (isRoot[i]) {
            hRoots = true;
            break;
        }
    }

    // Тест в текстовый файл
    ofstream Etog("etog" + to_string(num)+".txt");
    if (!hRoots) {
        Etog << "NO";
    }
    else {
        // исходные слова
        for (int i = 0; i < n; i++) {
            Etog << words[i];
            if (i < n - 1) Etog << "   "; 
        }
        Etog << endl;

        
        Etog << "=============================" << endl;

       // слова для длинного слова 
        for (string s : slova) {
            Etog << s << " ";
        }
        Etog << endl;
        // важное слово
        Etog << mimport << " " << maximport;
    }

    Etog.close();
    




}

