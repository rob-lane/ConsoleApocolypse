#include <string>
#include "json\json.h"

using namespace std;

namespace console_apoc {

	class JsonReader {
	public:
		JsonReader(string file_path);
		virtual ~JsonReader();

		virtual Json::Value* find_element(string element_name);

		Json::Reader* reader() const;
		Json::Value* root() const;

	private:
		Json::Reader *reader_;
		Json::Value *root_;
	};

}