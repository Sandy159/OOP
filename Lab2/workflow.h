#ifndef WORKFLOW_H
#define WORKFLOW_H
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "worker.h"

using namespace std;

class Workflow {
private:
	map<int, Worker*> map_of_workers;
	queue<int> order_of_operations;
public:
	void put_worker_to_map(int index, Worker* worker);
	void put_index_to_queue(int index);
	bool is_free_id(int index) const;
	void execute();
	void free_workflow();
};

#endif  // WORKFLOW_H
