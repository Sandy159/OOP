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
	vector <pair <int, string>> vector_with_sorted_statistic;

	map <string, int> get_map() {
		map <string, int> words;
		string str;
		while (in.good()) {
			getline(in, str, '\n');

			regex reg("[^A-Za-z0-9]+");

			sregex_token_iterator word(str.begin(), str.end(), reg, -1);

			sregex_token_iterator end;

			while (word != end && *word != "") {
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

	void sort_statistic() {
		vector_with_sorted_statistic = get_vector_statistic();
		sort(vector_with_sorted_statistic.begin(), vector_with_sorted_statistic.end(), greater<>());
	}

public:
	Handler(const char* file_name) {
		in.open(file_name);
		if (!in.good()) {
			cout << "No";
			exit(EXIT_FAILURE);
		}
		sort_statistic();
	}

	const vector <pair <int, string>>& get_sorted_statistic() const {
		return vector_with_sorted_statistic;
	}

	const int& get_count() const {
		return count;
	};
};

class Printer {
private:
	ofstream out;

public:
	Printer(const char* file_name) {
		out.open(file_name);
	}

	void print_words(const Handler& handler) {
		vector <pair <int, string>> ::const_iterator iter3 = handler.get_sorted_statistic().begin(), iter4 = handler.get_sorted_statistic().end();
		while (iter3 != iter4) {
			out << iter3->second << "," << iter3->first << "," << (iter3->first / static_cast<double>(handler.get_count())) * 100 << "%" << endl;
			iter3++;
		}
	}
};

int main() {
	Handler handler("input.txt");
	Printer printer("output.csv");
	printer.print_words(handler);
	return 0;
}