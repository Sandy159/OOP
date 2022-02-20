#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using namespace std;

class bad_file : public exception {
public:
	const char* what() const noexcept override;
};

class no_desc_csed : public exception {
public:
	const char* what() const noexcept override;
};

class error_str : public exception {
public:
	const char* what() const noexcept override;
};

class not_last_string : public exception {
public:
	const char* what() const noexcept override;
};

class false_index : public exception {
public:
	const char* what() const noexcept override;
};

class wrong_number_of_arguments : public exception {
public:
	const char* what() const noexcept override;
};

class wrong_arguments : public exception {
public:
	const char* what() const noexcept override;
};

class wrong_order_of_arguments : public exception {
public:
	const char* what() const noexcept override;
};

class no_argument : public exception {
public:
	const char* what() const noexcept override;
};
#endif  // EXCEPTIONS_H