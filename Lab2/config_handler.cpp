#include "config_handler.h"

extern int count_read;
extern int count_write;

void Config_handler::put_workers(Workflow* workflow) {
    string str;
    list<string> list_of_arguments;
    int index;
    regex reg("\\d+ = \\S+(\\s\\S+)*");
    regex re("\\s+");

    getline(file_, str, '\n');
    if (str.compare("desc")) {
        throw(no_desc_csed());
    }

    getline(file_, str, '\n');
    while (str.compare("csed") != 0 && !file_.eof()) {
        if (!regex_match(str, reg)) {
            throw(error_str());
        }
        sregex_token_iterator iter(str.begin(), str.end(), re, -1);
        sregex_token_iterator end;
        index = stoi(*iter);
        iter++; //пропустили индекс
        iter++; //пропустили =
        while (iter != end) {
            list_of_arguments.push_back(*iter);
            iter++;
        }
        if (workflow->is_free_id(index) == false) {
            workflow->free_workflow();
            throw(false_index());
        };

        workflow->put_worker_to_map(index, make_worker(list_of_arguments));
        getline(file_, str, '\n');
        list_of_arguments.clear();
    }

    if (file_.eof()) {
        throw(no_desc_csed());
    }
}

Worker* Config_handler::make_worker(list<string>& list_of_arguments) {
    string worker_name = list_of_arguments.front();
    list_of_arguments.pop_front();

    if (worker_name.compare("readfile") == 0) {
        ReadFactory read_factory;
        return read_factory.fabric_make_worker(list_of_arguments);
    }
    if (worker_name.compare("writefile") == 0) {
        WriteFactory write_factory;
        return write_factory.fabric_make_worker(list_of_arguments);
    }
    if (worker_name.compare("grep") == 0) {
        GrepFactory grep_factory;
        return grep_factory.fabric_make_worker(list_of_arguments);
    }
    if (worker_name.compare("sort") == 0) {
        SortFactory sort_factory;
        return sort_factory.fabric_make_worker(list_of_arguments);
    }
    if (worker_name.compare("replace") == 0) {
        ReplaceFactory replace_factory;
        return replace_factory.fabric_make_worker(list_of_arguments);
    }
    if (worker_name.compare("dump") == 0) {
        DumpFactory dump_factory;
        return dump_factory.fabric_make_worker(list_of_arguments);
    }
    throw (no_argument());
}

void Config_handler::put_order_operations(Workflow* workflow) {
    string str;
    regex reg("\\d+( -> \\d+)*");
    regex re("\\s+");
    getline(file_, str, '\n');
    if (!regex_match(str, reg)) {
        throw(error_str());
    }
    if (!file_.eof()) {
        throw(not_last_string());
    }
    sregex_token_iterator iter(str.begin(), str.end(), re, -1);
    sregex_token_iterator end;
    while (iter != end) {
        workflow->put_index_to_queue(stoi(*iter));
        if (workflow->is_free_id(stoi(*iter))) {
            throw(false_index());
        }
        iter++;
        if (iter != end)
            iter++;
    }
}

Config_handler::Config_handler(string file_name) {
    file_.open(file_name);
    if (file_.fail() == true) {
        throw(bad_file());
    }
}

Workflow& Config_handler::read_file() {
    Workflow* workflow = new Workflow{}; //иначе создастся на стеке, а так к нему будет доступ
    put_workers(workflow);
    put_order_operations(workflow);
    return *workflow;
}