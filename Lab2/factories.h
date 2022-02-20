#ifndef FACTORIES_H
#define FACTORIES_H

#include <string>

#include "worker.h"
#include "exceptions.h"

class Factory {
public:
	virtual Worker* fabric_make_worker(list<string> &list_of_arguments) = 0;
};

class ReadFactory : public Factory { public:
	Worker* fabric_make_worker(list<string>& list_of_arguments) override;
};

class WriteFactory : public Factory { public:
	Worker* fabric_make_worker(list<string>& list_of_arguments) override;
};

class GrepFactory : public Factory { public:
	Worker* fabric_make_worker(list<string>& list_of_arguments) override;
};

class SortFactory : public Factory { public:
	Worker* fabric_make_worker(list<string>& list_of_arguments) override;
};

class ReplaceFactory : public Factory { public:
	Worker* fabric_make_worker(list<string>& list_of_arguments) override;
};

class DumpFactory : public Factory { public:
	Worker* fabric_make_worker(list<string>& list_of_arguments) override;
};

#endif //FACTORIES_H