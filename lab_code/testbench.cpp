//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include "apex_code.h"
#include <fstream>
#include <iostream>

using namespace std;

static int testNum = 0;
static int testsCorrect = 0;

static int funcTestNum = 0;
static int funcTestCorrect = 0;

#define TEST_FUNC_PTR void (*test_func)(stringstream &, stringstream &)
void test(TEST_FUNC_PTR, const string &input, const string &expected) {
  funcTestNum++;
  testNum++;

  stringstream in_stream(input);
  stringstream out_stream;
  test_func(in_stream, out_stream);

  cout << "Test " << testNum << ": ";

  if (expected == out_stream.str()) {
    cout << "PASS" << endl;
    testsCorrect++;
    funcTestCorrect++;
  } else {
    cout << "With input \"" << input << "\" expected output \"" << expected
         << "\", received \"" << out_stream.str() << "\"" << endl;
  }
}

void start_tests(string startFuncName) {
  cout << "----- Start of testing " << startFuncName << " -----" << endl;

  funcTestNum = 0;
  funcTestCorrect = 0;
}

void end_tests(string endFuncName) {
  if (funcTestNum == funcTestCorrect) {
    cout << "----- All tests passed for " << endFuncName << "! -----" << endl;
  } else {
    cout << "----- Some tests failed for " << endFuncName << " :( -----"
         << endl;
  }
  cout << endl;
}

void end_all_tests() {
  if (testsCorrect == testNum) {
    cout << "All tests passed! Let's goooo 🥳"  << endl;
  } else {
    cout << "Some tests failed. Keep trying!" << endl;
  }
}

int main() {
  // To add a test case, duplicate one of the test lines below
  // modify input with the first string, and the expected output
  // in the second string.

  start_tests("middle_word_check");
  test(middle_word_check, "apple", "apple comes before middle");
  test(middle_word_check, "Middle", "Middle comes before middle");
  test(middle_word_check, "tree", "tree comes after middle");
  test(middle_word_check, "1tree", "1tree comes before middle");
  test(middle_word_check, "middly", "middly comes after middle");
  end_tests("middle_word_check");

  start_tests("animal_abcs");
  test(animal_abcs, "a", "anteater");
  test(animal_abcs, "B", "bat");
  test(animal_abcs, "C", "caterpillar");
  test(animal_abcs, "d", "dolphin");
  test(animal_abcs, "e", "emu");
  test(animal_abcs, "F", "frog");
  test(animal_abcs, "G", "G is not supported");
  test(animal_abcs, "z", "z is not supported");
  test(animal_abcs, "1", "1 is not supported");
  end_tests("animal_abcs");

  start_tests("delivery_range_check");
  test(delivery_range_check, "gas 100 30 30 30 30", "Not going to happen.");
  test(delivery_range_check, "gas 10 5 5 5 5", "Not going to happen.");
  test(delivery_range_check, "electric 85 3.4 10 5 5",
       "You can make it in your electric car!");
  test(delivery_range_check, "gas 85 3 3 3 3",
       "You can make it on an electric scooter!");
  test(delivery_range_check, "gas 85 3 4 3 5",
       "You can make it in your gas car!");
  test(delivery_range_check, "gas 200 2.57 6.7 40 3",
       "You can make it in your gas car!");
  end_tests("delivery_range_check");

  end_all_tests();

  return 0;
}
