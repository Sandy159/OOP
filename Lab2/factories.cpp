#include "factories.h"

Worker* ReadFactory::fabric_make_worker(list<string>& list_of_arguments) {
	if (list_of_arguments.size() != 1)
		throw(wrong_number_of_arguments());
	Readfile* read_file = new Readfile(list_of_arguments.front());
	return read_file;
}

Worker* WriteFactory::fabric_make_worker(list<string>& list_of_arguments) {
	if (list_of_arguments.size() != 1)
		throw(wrong_number_of_arguments());
	Writefile* write_file = new Writefile(list_of_arguments.front());
	return write_file;
}

Worker* GrepFactory::fabric_make_worker(list<string>& list_of_arguments) {
	if (list_of_arguments.size() != 1)
		throw(wrong_number_of_arguments());
	Grep* grep = new Grep(list_of_arguments.front());
	return grep;
}

Worker* SortFactory::fabric_make_worker(list<string>& list_of_arguments) {
	if (list_of_arguments.size() != 0)
		throw(wrong_number_of_arguments());
	Sort* sort = new Sort();
	return sort;
}

Worker* ReplaceFactory::fabric_make_worker(list<string>& list_of_arguments) {
	if (list_of_arguments.size() != 2)
		throw(wrong_number_of_arguments());
	string argument1 = list_of_arguments.front();
	list_of_arguments.pop_front();
	string argument2 = list_of_arguments.front();
	Replace* replace = new Replace(argument1, argument2);
	return replace;
}

Worker* DumpFactory::fabric_make_worker(list<string>& list_of_arguments) {
	if (list_of_arguments.size() != 1)
		throw(wrong_number_of_arguments());
	Dump* dump = new Dump(list_of_arguments.front());
	return dump;
}