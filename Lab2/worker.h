#ifndef WORKER_H
#define WORKER_H

#include <fstream>
#include <list>
#include <vector>
#include <regex>

#include "exceptions.h"



using namespace std;

class Worker {
private:
public:
	virtual void work(vector<string>& arr_of_string) = 0;
};

class Readfile : public Worker{
private:
	string file_name_for_work;
	ifstream file;
public:
	Readfile(string file_name);
	void work(vector<string>& arr_of_string) override;
};

class Writefile : public Worker {
private:
	string file_name_for_work;
public:
	Writefile(string file_name);
	void work(vector<string>& arr_of_string) override;
};

class Grep : public Worker {
private:
	string word_for_work;
public:
	Grep(string word);
	void work(vector<string>& arr_of_string) override;
};

class Sort : public Worker {
public:
	Sort() = default;
	void work(vector<string>& arr_of_string) override;
};

class Replace : public Worker {
	string word1_for_work;
	string word2_for_work;
public:
	Replace(string word1, string word2);
	void work(vector<string>& arr_of_string) override;
};

class Dump : public Worker {
private:
	string file_name_for_work;
public:
	Dump(string file_name);
	void work(vector<string>& arr_of_string) override;
};

#endif  // WORKER_H