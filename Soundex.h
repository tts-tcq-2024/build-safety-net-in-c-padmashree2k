#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char soundexTable[128];

void initializeSoundexTable() {
    // Initialize the whole table to '0' by default
    memset(soundexTable, '0', sizeof(soundexTable));

    // Manually assign values for the relevant letters
    soundexTable['B'] = soundexTable['b'] = '1';
    soundexTable['F'] = soundexTable['f'] = '1';
    soundexTable['P'] = soundexTable['p'] = '1';
    soundexTable['V'] = soundexTable['v'] = '1';

    soundexTable['C'] = soundexTable['c'] = '2';
    soundexTable['G'] = soundexTable['g'] = '2';
    soundexTable['J'] = soundexTable['j'] = '2';
    soundexTable['K'] = soundexTable['k'] = '2';
    soundexTable['Q'] = soundexTable['q'] = '2';
    soundexTable['S'] = soundexTable['s'] = '2';
    soundexTable['X'] = soundexTable['x'] = '2';
    soundexTable['Z'] = soundexTable['z'] = '2';

    soundexTable['D'] = soundexTable['d'] = '3';
    soundexTable['T'] = soundexTable['t'] = '3';

    soundexTable['L'] = soundexTable['l'] = '4';

    soundexTable['M'] = soundexTable['m'] = '5';
    soundexTable['N'] = soundexTable['n'] = '5';

    soundexTable['R'] = soundexTable['r'] = '6';
}

void generateSoundex(const char *name, char *soundex) {
    // Initialize the table if not already initialized
    static int initialized = 0;
    if (!initialized) {
        initializeSoundexTable();
        initialized = 1;
    }

    soundex[0] = toupper(name[0]);  // Retain the first character as-is
    char lastCode = soundexTable[(int)name[0]];

    // Fixed path: a simple loop without conditions
    int sIndex = 1;
    for (int i = 1; i < 4; ++i) {
        char code = soundexTable[(int)name[i]];
        soundex[sIndex++] = (code != lastCode && code > '0') ? code : '0';
        lastCode = code;
    }

    soundex[4] = '\0';  // Null-terminate the result
}

#endif // SOUNDEX_H
