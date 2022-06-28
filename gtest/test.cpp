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
	ASSERT_STREQ(output.c_str(), "\033[0;31mError: Some error happend!\033[0m\r\n39");

	ERROR_PRINT("%s\r\n","Some error happend!");
}

TEST(ERROR_PRINT, Some_just_error_str)
{
    testing::internal::CaptureStdout();
	std::cout << ERROR_PRINT("Just error happend!\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;31mError: Just error happend!\r\n\x1B[0m39");

	ERROR_PRINT("Just error happend!\r\n");
}

TEST(LOG_PRINT, Some_log_format_str)
{
    testing::internal::CaptureStdout();
	std::cout << LOG_PRINT("%s\r\n","Some Log");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;34mLog: \x1B[0m\x1B[0;36mSome Log\x1B[0m\r\n37");
	LOG_PRINT("%s\r\n","Some Log");
}

TEST(LOG_PRINT, Just_log_str)
{
    testing::internal::CaptureStdout();
	std::cout << LOG_PRINT("Just Log\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;34mLog: \x1B[0m\x1B[0;36mJust Log\r\n\x1B[0m37");
	LOG_PRINT("Just Log\r\n");
}

TEST(WARNING_PRINT, Some_warning_format_str)
{
    testing::internal::CaptureStdout();
	std::cout << WARNING_PRINT("%s\r\n","Some Warning");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(output.c_str(), "\x1B[0;33mWarning:\x1B[0m\x1B[0;36mSome Warning\x1B[0m\r\n44");
	WARNING_PRINT("%s\r\n","Some Warning");
}

TEST(WARNING_PRINT, Just_warning_str)
{
    testing::internal::CaptureStdout();
	std::cout << WARNING_PRINT("Just Warning\r\n");
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "\x1B[0;33mWarning:\x1B[0m\x1B[0;36mJust Warning\r\n\x1B[0m44");
	WARNING_PRINT("Just Warning\r\n");
}


