#ifndef CONFIG_HANDLER_H_
#define CONFIG_HANDLER_H_

#include <fstream>
#include <list>
#include <regex>
#include <string>

#include "Workflow.h"
#include "exceptions.h"
#include "factories.h"

using namespace std;



class Config_handler {
private:
    ifstream file_;

    void put_workers(Workflow* workflow);
    Worker* make_worker(list<string>& list_of_arguments);
    void put_order_operations(Workflow* workflow);

public:
    Config_handler(string file_name);
    Workflow& read_file();
};

#endif  // CONFIG_HANDLER_H_