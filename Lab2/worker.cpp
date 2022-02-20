#include "worker.h"

int count_read = 0;
int count_write = 0;

using namespace std;

Readfile::Readfile(string file_name) {
	file_name_for_work = file_name;
}

void Readfile::work(vector<string>& arr_of_string) {
	int size = arr_of_string.size();
	if (size != 0) {
		throw(wrong_arguments());
	}
	file.open(file_name_for_work);
	if (file.fail() == true) {
		throw(bad_file());
	}
	count_read++;
	string str;
	while (!file.eof()) {
		getline(file, str, '\n');
		arr_of_string.push_back(str);
	}

}

Writefile::Writefile(string file_name) {
	file_name_for_work = file_name;
}

void Writefile::work(vector<string>& arr_of_string) {
	int size = arr_of_string.size();
	if (size == 0) {
		throw(wrong_arguments());
	}
	ofstream file;
	file.open(file_name_for_work);
	if (file.fail() == true) {
		throw(bad_file());
	}
	count_write++;
	for (int i = 0; i < size; i++) {
		file << arr_of_string[i] << '\n';
	}
	arr_of_string.clear();
	file.close();
}

Grep::Grep(string word) {
	word_for_work = word;
}

void Grep::work(vector<string>& arr_of_string) {
	int size = arr_of_string.size();
	vector<string> new_arr;
	if (size == 0) {
		throw(wrong_arguments());
	}
	regex reg(".*" + word_for_work + ".*");
	for (auto i = arr_of_string.begin(), j = arr_of_string.end(); i != j;) {
		if (regex_match(*i, reg)) {
			new_arr.push_back(*i);
		}
		i++;
	}
	arr_of_string = new_arr;
}

void Sort::work(vector<string>& arr_of_string) {
	sort(arr_of_string.begin(), arr_of_string.end());
}

Replace::Replace(string word1, string word2) {
	word1_for_work = word1;
	word2_for_work = word2;
}

void Replace::work(vector<string>& arr_of_string) {
	int size = arr_of_string.size();
	if (size == 0) {
		throw(wrong_arguments());
	}
	regex reg_replace(word1_for_work);
	for (auto i = arr_of_string.begin(), j = arr_of_string.end(); i != j;) {
		(*i) = regex_replace(*i, reg_replace, word2_for_work);
		i++;
	}
}

Dump::Dump(string file_name) {
	file_name_for_work = file_name;
}

void Dump::work(vector<string>& arr_of_string) {
	int size = arr_of_string.size();
	if (size == 0) {
		throw(wrong_arguments());
	}
	ofstream file;
	file.open(file_name_for_work);
	if (file.fail() == true) {
		throw(bad_file());
	}
	for (int i = 0; i < size; i++) {
		file << arr_of_string[i];
	}
	file.close();
}