#include "workflow.h"

extern int count_read;
extern int count_write;

void Workflow::put_worker_to_map(int index, Worker* worker) {
	map_of_workers[index] = worker;
}

void Workflow::put_index_to_queue(int index) {
	order_of_operations.push(index);
}

bool Workflow::is_free_id(int index) const{
	return (!map_of_workers.count(index));
}

void Workflow::execute() {
	int index;
	int size = order_of_operations.size();
	vector<string> arr_of_string;
	while (size) {
		index = order_of_operations.front();
		order_of_operations.pop();
		if (count_read > 1 || count_write > 1) {
			throw(wrong_order_of_arguments());
		}
		map_of_workers[index]->work(arr_of_string);
		size--;
	}
}

void Workflow::free_workflow() {
	for (auto i : map_of_workers) {
		delete(i.second); //удаляем, т.к. память на куче выделили
	}
}