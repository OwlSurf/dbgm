#include <gtest/gtest.h>
#include <iostream>

#include "dbgm.h"

TEST(DEBUG_PRINT, Print_HELLO)
{
#ifdef DEBUG
	testing::internal::CaptureStdout();
	std::cout << DEBUG_PRINT("HELLO!\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.data(), "HELLO!\r\n8");
#endif
}

TEST(ERROR_PRINT, Some_error_format_str)
{
    testing::internal::CaptureStdout();
	std::cout << ERROR_PRINT("%s\r\n","Some error happend!");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), RED_COLOR "Error: " COLOR_OFF "Some error happend!\r\n39");

}

TEST(ERROR_PRINT, Some_just_error_str)
{
    testing::internal::CaptureStdout();
	std::cout << ERROR_PRINT("Just error happend!\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;31mError: \x1B[0mJust error happend!\r\n39");

}

TEST(ERROR_PRINT, Some_format_param_error)
{
    testing::internal::CaptureStdout();
	std::cout << ERROR_PRINT("Error %d\r\n",12);
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;31mError: \x1B[0mError 12\r\n28");

}

TEST(LOG_PRINT, Some_log_format_str)
{
    testing::internal::CaptureStdout();
	std::cout << LOG_PRINT("%s\r\n","Some Log");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;34mLog: \x1B[0m\x1B[0;36mSome Log\r\n33" COLOR_OFF);
}

TEST(LOG_PRINT, Just_log_str)
{
    testing::internal::CaptureStdout();
	std::cout << LOG_PRINT("Just Log\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;34mLog: \x1B[0m\x1B[0;36mJust Log\r\n33" COLOR_OFF);
}

TEST(WARNING_PRINT, Some_warning_format_str)
{
    testing::internal::CaptureStdout();
	std::cout << WARNING_PRINT("%s\r\n","Some Warning");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;33mWarning:\x1B[0m\x1B[0;36mSome Warning\r\n40" COLOR_OFF);
}

TEST(WARNING_PRINT, Just_warning_str)
{
    testing::internal::CaptureStdout();
	std::cout << WARNING_PRINT("Just Warning\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "\x1B[0;33mWarning:\x1B[0m\x1B[0;36mJust Warning\r\n40" COLOR_OFF);
}

TEST(WARNING_PRINT, Warning_format_str_param)
{
    testing::internal::CaptureStdout();
	std::cout << WARNING_PRINT("Number %d\r\n", 45);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "\x1B[0;33mWarning:\x1B[0m\x1B[0;36mNumber 45\r\n37" COLOR_OFF);
}

TEST(PRINT_SHOW, show_all_outputs)
{
	ERROR_PRINT("%s\r\n","Some error happend!");
	ERROR_PRINT("Just error happend!\r\n");
	ERROR_PRINT("Error 12\r\n");
	ERROR_PRINT("%s: %d, %s: %f\r\n", "Level", 200, "value", 50.34);
	ERROR_PRINT("%d, %d, %f, %d\r\n", 10, 20, 45.56, 346);
	LOG_PRINT("%s\r\n","Some Log");
	LOG_PRINT("Just Log\r\n");
	LOG_PRINT("%s, %d, %s, %f\r\n", "Deep", 45, "value:", 45.56);
	WARNING_PRINT("%s\r\n","Some Warning");
	WARNING_PRINT("Just Warning\r\n");
	WARNING_PRINT("Number %d\r\n", 45);
	WARNING_PRINT("%s, %d, %s, %f\r\n", "Max", 45, "Min", 56.78);
}
