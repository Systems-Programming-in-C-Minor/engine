#include <gtest/gtest.h>

#include "debug.hpp"
#include "string"


TEST(DebugTest, TestLogging)
{
    testing::internal::CaptureStdout();
    Debug::log("test log");
    std::string log = testing::internal::GetCapturedStdout();
    ASSERT_EQ(log, "INFO - test log");
}

TEST(DebugTest, TestWarningLogging)
{
    testing::internal::CaptureStderr();
    Debug::log_warning("test warning log");
    std::string log = testing::internal::GetCapturedStderr();
    ASSERT_EQ(log, "WARNING - test warning log");
}

TEST(DebugTest, TestErrorLogging)
{
    testing::internal::CaptureStderr();
    Debug::log_error("test error log");
    std::string log = testing::internal::GetCapturedStderr();
    ASSERT_EQ(log, "ERROR - test error log");
}
