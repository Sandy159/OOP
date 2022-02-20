#include "exceptions.h"

const char* bad_file::what() const noexcept {
	return "file hasn`t opened or file has bad state";
}

const char* no_desc_csed::what() const noexcept { return "no desc or csed"; }

const char* error_str::what() const noexcept { return "error_string"; }

const char* not_last_string::what() const noexcept { return "not_last_string"; }

const char* false_index::what() const noexcept { return "false index in order"; }

const char* wrong_number_of_arguments::what() const noexcept { return "wrong number of arguments"; }

const char* wrong_arguments::what() const noexcept { return "wrong arguments"; }

const char* wrong_order_of_arguments::what() const noexcept { return "wrong order of arguments"; }

const char* no_argument::what() const noexcept { return "no argument"; }