
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

    // Test for "Smith"
    generateSoundex("Smith", soundex);
    ASSERT_STREQ(soundex, "S5030");

    // Test for "Schmidt"
    generateSoundex("Schmidt", soundex);
    ASSERT_STREQ(soundex, "S205033");

    // Test for "Jack"
    generateSoundex("Jack", soundex);
    ASSERT_STREQ(soundex, "J0222");

    // Test for "Jax"
    generateSoundex("Jax", soundex);
    ASSERT_STREQ(soundex, "J020");

    // Test for "Robert"
    generateSoundex("Robert", soundex);
    ASSERT_STREQ(soundex, "R163");

    // Test for "Rubin"
    generateSoundex("Rubin", soundex);
    ASSERT_STREQ(soundex, "R150");
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
    ASSERT_STREQ(soundex, "T320");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
