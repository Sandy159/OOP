#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <regex>
#include <map>
#include <windows.h>

#pragma execution_character_set( "utf-8" )
using namespace std;

class Handler {
private:
	ifstream in;
	int count = 0;

	map <string, int> get_map() {
		map <string, int> words;
		string str;
		while (in.good()) { 
			getline(in, str, '\n');

			regex reg("[^A-Za-zАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя0-9]+"); 

			sregex_token_iterator word(str.begin(), str.end(), reg, -1);

			sregex_token_iterator end;

			while (word != end) {
				string test = *word;
				words[*word]++;
				word++;
				count++;
			}
		}
		return words;
	}

	vector <pair <int, string>> get_vector_statistic() {
		map <string, int> words = get_map();
		map <string, int> ::iterator iter1 = words.begin(), iter2 = words.end();
		vector <pair <int, string>> sorted_word;

		while (iter1 != iter2) {
			sorted_word.push_back(make_pair(iter1->second, iter1->first));
			iter1++;
		}
		return sorted_word;
	}

public:
	Handler(const char* file_name) {
		in.open(file_name);
		if (!in.good()) {
			cout << "No";
			exit(EXIT_FAILURE);
		}
	}

	vector <pair <int, string>> get_sorted_statistic() {
		vector <pair <int, string>> sorted_word = get_vector_statistic();

		sort(sorted_word.begin(), sorted_word.end(), greater<>()); 

		return sorted_word;
	}

	int getter() {
		return count;
	};
};

class print_words {
	ofstream out;
public:
	print_words(const char* file_name) {
		out.open(file_name);
	}

	void Printer(vector <pair <int, string>> statistic, int count) {
		vector <pair <int, string>> ::iterator iter3 = statistic.begin(), iter4 = statistic.end();
		while (iter3 != iter4) {
			out << iter3->second << "," << iter3->first << "," << (iter3->first / static_cast<double>(count)) * 100 << "%" << endl;
			iter3++;
		}
	}
};

int main() {
	//SetConsoleOutputCP(65001);
	Handler handler("input.txt");
	vector <pair <int, string>> sorted_word = handler.get_sorted_statistic();
	int counter = handler.getter();
	print_words printer("output.csv");
	printer.Printer(sorted_word, counter);
	return 0;
}