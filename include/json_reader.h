#include <string>
#include <exception>
#include <windows.h>
#include <tchar.h>
#include <fstream>
#include "json\json.h"

using namespace std;

namespace console_apoc {

	class JsonReader {
	public:
		JsonReader(string file_path);
		virtual ~JsonReader();

		virtual Json::Value find_element(string element_name);

		Json::Value root() const;

	private:
		Json::Value root_;
		const char *null_label_ = "NULL";

		bool file_exists_(string* file_path);
		Json::Value find_element_(string element_name, 
									Json::Value root_element = NULL);
	};

}