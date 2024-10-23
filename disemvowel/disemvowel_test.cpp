#include <gtest/gtest.h>
#include "disemvowel.h"

void check_vowel_removal(const char* input, const char* expected) {
  char* result = disemvowel((char*)input);
  ASSERT_STREQ(expected, result);
  free(result);
}

TEST(Disemvowel, HandlesEmptyString) {
  check_vowel_removal("", "");
}

TEST(Disemvowel, HandlesNoVowels) {
  check_vowel_removal("pqrst", "pqrst");
}

TEST(Disemvowel, HandlesOnlyVowels) {
  check_vowel_removal("aeiouAEIOUOIEAuoiea", "");
}

TEST(Disemvowel, HandlesMorrisMinnesota) {
  check_vowel_removal("Morris, Minnesota", "Mrrs, Mnnst");
}

TEST(Disemvowel, HandlesPunctuation) {
  check_vowel_removal("An (Unexplained) Elephant!", "n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandlesLongString) {
  char *str;
  int size = 50000;

  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  
  for (int i = 3; i < size - 1; ++i) {
    str[i] = 'a';
  }
  
  str[size - 1] = '\0';
  
  check_vowel_removal(str, "xyz");

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
