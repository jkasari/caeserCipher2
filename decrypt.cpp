#include <iostream>
#include <cmath>
#include <ctgmath>
#include <vector>
#include <string>
#include "cipherFunctions.cpp"
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Error: This program expects exactly two arguments" << endl << endl;
    cout << "  (The distance to shift)" << endl;
    cout << "  (The message to encrypt)" << endl;
    return 1;
  }
  string str = argv[2];
  if (!isInAlphabetIndex(str)) {
    cout << "The message can only use characters in |ALPHABET_INDEX|" <<endl;
    return 1;
  }
  int key = stol(argv[1]);
  decrypt(key, str);
  cout << str << endl;
}
