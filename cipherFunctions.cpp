#include <vector>
#include <string>
/**
 * This is an array of characters in an order that the cipher shifts through.
 */
static const int32_t ALPHABET_SIZE = 28;
static const char ALPHABET[ALPHABET_SIZE] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

/**
 * Takes a char and returns the index + 1 of the matching char in |ALPHABET|.
 * This function returns a 0 if the character is not in |ALPHABET|.
 */
int32_t indexChar(const char c) {
  for (int32_t i = 0; i < ALPHABET_SIZE; ++i) {
    if (c == ALPHABET[i]) {
      return i + 1;
    }
  }
  return 0;
}

/**
 * This function uses |indexChar| to tell if the char is on |ALPHABET|. It takes
 * a string and runs each char through |indexChar| if it gets a zero on any char
 * it returns false.
 */
bool isInAlphabetIndex(const std::string& str) {
  for (int i = 0; i < str.size(); ++i) {
    if (indexChar(str[i]) == 0) {
      return false;
    }
  }
  return true;
}

/**
 * Takes a char and moves it along the |ALPHABET| to the right.
 * The |key| dictates how much it moves the char's in |str|.
 */
char charShiftRight(const int32_t key, char charToShift) {
  char shiftedChar = indexChar(charToShift) + (key % ALPHABET_SIZE);
  if (shiftedChar >= ALPHABET_SIZE) {
    shiftedChar -= (ALPHABET_SIZE - 1);
  }
  return ALPHABET[shiftedChar - 1];
}

/**
 * Takes a char and moves it along the |ALPHABET| to the left.
 * The |key| dictates how much it moves the char's in |str|.
 */
char charShiftLeft(const int32_t key, char charToShift) {
  char shiftedChar = indexChar(charToShift) - (key % ALPHABET_SIZE);
  if (shiftedChar < 1) {
    shiftedChar += (ALPHABET_SIZE - 1);
  }
  return ALPHABET[shiftedChar - 1];
}

/**
 * Encrypts a string by moving each char to the right using |charShiftRight|.
 * The amount to shift is dictated by the |key|.
 */
std::string encrypt(const int32_t key, std::string& str) {
  for (int i = 0; i < str.size(); ++i) {
    str[i] = charShiftRight(key, str[i]);
  }
  return str;
}

/**
 * Decrypts a string by moving each char to the left using |charShiftLeft|.
 * The amount to shift is dictated by the |key|.
 */
std::string decrypt(const int32_t key, std::string& str) {
  for (int i = 0; i < str.size(); ++i) {
    str[i] = charShiftLeft(key, str[i]);
  }
  return str;
}