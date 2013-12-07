// Copyright 2013 Pavel Korotaev

#include <gtest/gtest.h>

#include <string>

#include "library/weightconvertor_application.h"

using ::testing::internal::RE;

TEST(AppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    WeightConvertorApplication app;
    int argc = 1;
    const char* argv[] = {"appname"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("This is a weight convertor application")));
}

TEST(AppTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    WeightConvertorApplication app;
    int argc = 3;
    const char* argv[] = {"appname", "3", "Ton"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("ERROR: Should be 3 arguments\\..*")));
}

TEST(AppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    WeightConvertorApplication app;
    int argc = 4;
    const char* argv[] = {"appname", "x", "Ounce", "Stone"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong number format!")));
}

TEST(AppTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    WeightConvertorApplication app;
    int argc = 4;
    const char* argv[] = {"appname", "1", "1", "abc"};

    // Act
    std::string output = app(argc, argv);

    // Assert
    EXPECT_TRUE(RE::PartialMatch(
                    output,
                    RE("Wrong number format!")));
}