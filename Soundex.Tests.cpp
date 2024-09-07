#include <gtest/gtest.h>
#include <cstring>
#include "Soundex.h"

// Helper function to generate Soundex and compare with the expected result
void testSoundex(const char* name, const char* expectedSoundex) {
    char soundexResult[5];  // Soundex result has to be 4 chars + null terminator
    generateSoundex(name, soundexResult);
    ASSERT_STREQ(soundexResult, expectedSoundex);
}

// Test case 1: Standard case with mixed characters
TEST(SoundexTest, StandardSoundexTest) {
    testSoundex("Robert", "R163");
    testSoundex("Rupert", "R163");
    testSoundex("Rubin",  "R150");
}

// Test case 2: Names starting with different characters
TEST(SoundexTest, DifferentStartingLetters) {
    testSoundex("Ashcraft", "A261");
    testSoundex("Tymczak", "T522");
    testSoundex("Pfister", "P236");
}

// Test case 3: Name with all vowels (should result in first letter followed by 000)
TEST(SoundexTest, AllVowels) {
    testSoundex("Aeio", "A000");
    testSoundex("Ouaie", "O000");
}

// Test case 4: Name with repeating consonants (should eliminate duplicates)
TEST(SoundexTest, RepeatingConsonants) {
    testSoundex("Ttttt", "T000");
    testSoundex("Ssssss", "S000");
    testSoundex("Bbbbbbb", "B100");
}

// Test case 5: Empty name input
TEST(SoundexTest, EmptyName) {
    char soundexResult[5] = {};
    generateSoundex("", soundexResult);
    ASSERT_STREQ(soundexResult, "0");
}

// Test case 6: Name with special characters (ignored or handled as non-alphabetical)
TEST(SoundexTest, SpecialCharacters) {
    testSoundex("R@bert!", "R163");  // Should treat non-letters as ignored
    testSoundex("A#shcra*ft", "A261");
    testSoundex("!Pfister", "P236");
}

// Test case 7: Name with mixed cases (uppercase and lowercase)
TEST(SoundexTest, MixedCaseName) {
    testSoundex("robert", "R163");  // Lowercase input should be treated as uppercase
    testSoundex("RuBeRt", "R163");
}

// Test case 8: Name shorter than 4 characters
TEST(SoundexTest, ShortNames) {
    testSoundex("Al", "A400");
    testSoundex("Jo", "J000");
}

// Test case 9: Name exactly 4 characters long
TEST(SoundexTest, FourCharacterName) {
    testSoundex("John", "J500");
    testSoundex("Liam", "L500");
}

