#include <fstream>
#include <iostream>
#include <string>

#include "Workflow.h"
#include "config_handler.h"

using namespace std;

int main() {
    Config_handler config_handler("file.txt");
    Workflow& workflow = config_handler.read_file();
    workflow.execute();
    workflow.free_workflow();
}