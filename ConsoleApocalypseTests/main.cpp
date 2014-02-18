#include <iostream>
#include <string>
#include "gmock\gmock.h"
#include "gtest\gtest.h"

#include "player.h"

using namespace std;

int main(int argc, char** argv) {
	::testing::GTEST_FLAG(throw_on_failure) = true;
	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	//Pause exiting
	std::getchar();
}