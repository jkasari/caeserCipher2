#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "cypherFunctions.cpp"

using namespace std;
using namespace nuttiest;

int main() {
  section("indexChar") {
    unit_test("\'A\' returns (1)") {
      assert_eq(1, indexChar('A'));
    }
    unit_test("\'Z\' returns (26)") {
      assert_eq(26, indexChar('Z'));
    }
  }
  section("isInAlphabetIndex") {
    unit_test("\"AAA\" is all caps") {
      string str {"AAA"};
      assert_eq(true, isInAlphabetIndex(str));
    }
    unit_test("\"AAa\" is not all caps") {
      string str {"AAa"};
      assert_eq(false, isInAlphabetIndex(str));
    }
  }
  section("charShiftRight") {
    unit_test("(2) and \'A\' returns \'C\'") {
      assert_eq('C', charShiftRight(2, 'A'));
    }
    unit_test("(25) and \'E\' returns \'B\'") {
      assert_eq('B', charShiftRight(25, 'E'));
    }
  }
  section("charShiftLeft") {
    unit_test("(2) and \'C\' returns \'A\'") {
      assert_eq('A', charShiftLeft(2, 'C'));
    }
    unit_test("(25) and \'B\' returns \'E\'") {
      assert_eq('E', charShiftLeft(25, 'B'));
    }
  }
   section("encrypt") {
    unit_test("(4) \"ABC\" returns \"EFG\"") {
      string str {"ABC"};
      encrypt(4, str);
      assert_eq("EFG", str);
    }
    unit_test("(25) and \"BLACK MAGIC\"  returns \" IZ.HXJZDF.\"") {
      string str {"BLACK MAGIC"};
      encrypt(25, str);
      assert_eq(" IZ.HXJZDF.", str);
    }
  }
   section("decrypt") {
    unit_test("(4) \"EFG\" returns \"ABC\"") {
      string str {"EFG"};
      decrypt(4, str);
      assert_eq("ABC", str);
    }
    unit_test("(25) and \" IZ.HXJZDF.\" returns \"BLACK MAGIC\"") {
      string str {" IZ.HXJZDF."};
      decrypt(25, str);
      assert_eq("BLACK MAGIC", str);
    }
  }
  summary();
}

