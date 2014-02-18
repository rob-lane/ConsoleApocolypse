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
		const string test_json_file_ = "test_groups.json";
	};


	TEST_F(JsonReaderTest, CreatesJsonReader) {
		string error_msg = "JsonReader should create a new Json::Reader";
		ASSERT_TRUE(json_reader_->reader() != NULL) << error_msg;
	}
	
	TEST_F(JsonReaderTest, CapturesRootElement) {
		string error_msg = "JsonReader should capture the root element of the \
						   JSON document";
		ASSERT_TRUE(json_reader_->root() != NULL) << error_msg;
	}
}