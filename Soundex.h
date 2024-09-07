#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Precomputed Soundex table for all ASCII characters
const char soundexTable[128] = {
    ['A'] = '0', ['B'] = '1', ['C'] = '2', ['D'] = '3', ['E'] = '0',
    ['F'] = '1', ['G'] = '2', ['H'] = '0', ['I'] = '0', ['J'] = '2',
    ['K'] = '2', ['L'] = '4', ['M'] = '5', ['N'] = '5', ['O'] = '0',
    ['P'] = '1', ['Q'] = '2', ['R'] = '6', ['S'] = '2', ['T'] = '3',
    ['U'] = '0', ['V'] = '1', ['W'] = '0', ['X'] = '2', ['Y'] = '0',
    ['Z'] = '2', ['a'] = '0', ['b'] = '1', ['c'] = '2', ['d'] = '3',
    ['e'] = '0', ['f'] = '1', ['g'] = '2', ['h'] = '0', ['i'] = '0',
    ['j'] = '2', ['k'] = '2', ['l'] = '4', ['m'] = '5', ['n'] = '5',
    ['o'] = '0', ['p'] = '1', ['q'] = '2', ['r'] = '6', ['s'] = '2',
    ['t'] = '3', ['u'] = '0', ['v'] = '1', ['w'] = '0', ['x'] = '2',
    ['y'] = '0', ['z'] = '2'
};

void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);  // First character is retained as-is
    int sIndex = 1;
    char lastCode = soundexTable[(int)name[0]];  // Get Soundex code for the first character

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = soundexTable[(int)name[i]];  // Get the Soundex code from the table
        if (code != '0' && code != lastCode) {   // Add non-zero and non-duplicate code
            soundex[sIndex++] = code;
        }
        lastCode = code;
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';  // Pad with zeroes if necessary
    }

    soundex[4] = '\0';  // Null-terminate the result
}

#endif // SOUNDEX_H
