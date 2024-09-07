#include <gtest/gtest.h>
#include "Soundex.h"

class SoundexTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any necessary setup code here
    }

    void TearDown() override {
        // Any necessary cleanup code here
    }
};

TEST_F(SoundexTest, BasicTests) {
    char soundex[5];

    // Test for "Jack"
    generateSoundex("Jack", soundex);
    ASSERT_STREQ(soundex, "J200");

    // Test for "Schm"
    generateSoundex("Schm", soundex);
    ASSERT_STREQ(soundex, "S500");

    // Test for "John"
    generateSoundex("John", soundex);
    ASSERT_STREQ(soundex, "J500");

    // Test for "Jaxi"
    generateSoundex("Jaxi", soundex);
    ASSERT_STREQ(soundex, "J200");

    // Test for "Roby"
    generateSoundex("Roby", soundex);
    ASSERT_STREQ(soundex, "R100");

    // Test for "Rubi"
    generateSoundex("Rubi", soundex);
    ASSERT_STREQ(soundex, "R100");
}

TEST_F(SoundexTest, EdgeCases) {
    char soundex[5];

    // Test for empty string
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "0000");

    // Test for single character
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");

    generateSoundex("B", soundex);
    ASSERT_STREQ(soundex, "B000");

    // Test for a string with all characters resulting in the same code
    generateSoundex("AAAA", soundex);
    ASSERT_STREQ(soundex, "A000");

    // Test for string with non-alphabetic characters
    generateSoundex("1234", soundex);
    ASSERT_STREQ(soundex, "0000");

    // Test for string with special characters
    generateSoundex("!@#$", soundex);
    ASSERT_STREQ(soundex, "0000");
}

TEST_F(SoundexTest, InitializationCheck) {
    char soundex[5];
    
    // Force initialization of the table and check functionality
    generateSoundex("Test", soundex);
    ASSERT_STREQ(soundex, "T230");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
