#include "json_reader.h"

namespace console_apoc {

	JsonReader::JsonReader(string file_path) {
		if (file_exists_(&file_path) == false) {
			string error_msg = "Failed to locate file: " + file_path + "\n"
								+ "please ensure you have the correct path and"+
								"file name";
			cout << error_msg;
			throw std::runtime_error(error_msg);
		}

		Json::Reader reader;
		std::ifstream ifs(file_path);
		string buffer( (std::istreambuf_iterator<char>(ifs) ),
						(std::istreambuf_iterator<char>()	)  );
		bool parse_result = reader.parse(buffer, root_);
		if (parse_result == false) {
			string error_msg = "Failed to parse JSON file : " + file_path + "\n"
								+ reader.getFormatedErrorMessages();
			cout << error_msg;
			throw std::runtime_error(error_msg);
		}
	}

	JsonReader::~JsonReader() {

	}

	Json::Value JsonReader::find_element(string element_name) {
		return find_element_(element_name);
	}

	Json::Value JsonReader::root() const {
		return root_;
	}

	bool JsonReader::file_exists_(string *file_path) {
		TCHAR *tchar_file_path = (TCHAR*)file_path->c_str();
		DWORD fileAttr = GetFileAttributes(tchar_file_path);

		if (fileAttr == 0xFFFFFFFF && GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			return false;
		}

		return true;
	}

	Json::Value JsonReader::find_element_(string element_name,
											Json::Value root_element) {
		if (root_element == NULL) 
		{
			root_element = root_;
		}
		Json::Value search_element = root_element[element_name];
		if (search_element == NULL) {
			if (root_element.size() > 0) {
				search_element = find_element_(element_name, root_element[1]);
			}
			else {
				search_element = NULL;
			}
		}
		return search_element;
	}

}