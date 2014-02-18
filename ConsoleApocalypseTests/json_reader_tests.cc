#include "gmock\gmock.h"
#include "gtest\gtest.h"
#include "json_reader.h"

namespace console_apoc {

	class JsonReaderTest : public ::testing::Test {
	protected:
		void SetUp() {
			json_reader_ = new JsonReader(test_json_file_);
		}

		JsonReader *json_reader_;
		const string test_json_file_ = ".\\test_json_groups.json";
	};
	
	TEST_F(JsonReaderTest, CapturesRootElement) {
		string error_msg = "JsonReader should capture the root element of the \
						   JSON document";
		ASSERT_TRUE(json_reader_->root() != NULL) << error_msg;
	}

	TEST_F(JsonReaderTest, LocatesElementByName) {
		string error_msg = "JsonReader should locate an element in the JSON by name";
		Json::Value group_element = json_reader_->find_element("group1");
		EXPECT_TRUE(group_element != NULL) << error_msg;

		group_element = json_reader_->find_element("name");
		EXPECT_TRUE(group_element != NULL) << error_msg;
	}
}