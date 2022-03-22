#include <iostream>
#include <sstream>
#include "acutest.hpp"
#include "Dataframe.hpp"

void test_file_that_does_not_exist(void) {
    std::string expected = "";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("file_does_not_exist.csv", "2018-12-09");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected, "the function fails to return if the file doesn't exist.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_date_does_not_exist(void) {
    std::string expected = "";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("cookie_log.csv", "2018-12-10");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected, "the function fails to return if the date doesn't exist.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_file_is_empty(void) {
    std::string expected = "";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("empty.csv", "2018-12-09");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected, "if the function fails to return when the file is empty.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_one_entry(void) {
    std::string expected = "AtY0laUfhglK3lC7\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("one_entry.csv", "2018-12-09");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected, "if the function fails to return when the file is empty.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_cookie_log_date07(void) {
    std::string expected = "4sMM2LxV07bPJzwf\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("cookie_log.csv", "2018-12-07");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails the provided cookie_log.csv with -d 2018-12-07.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_cookie_log_date08(void) {
    std::string expected = "SAZuXPGUrfbcn5UA\n4sMM2LxV07bPJzwf\nfbcn5UAVanZf6UtG\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("cookie_log.csv", "2018-12-08");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails the provided cookie_log.csv with -d 2018-12-07.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_cookie_log_date09(void) {
    std::string expected = "AtY0laUfhglK3lC7\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("cookie_log.csv", "2018-12-09");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails the provided cookie_log.csv with -d 2018-12-09.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_win_at_two(void) {
    std::string expected = "a\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("ties.csv", "2018-12-10");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when a cookie wins with a score of w.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}
void test_large_tie_at_one(void) {
    std::string expected = "a\nb\nc\nd\ne\nf\ng\nh\ni\nj\nk\nl\nm\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("ties.csv", "2018-12-09");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when lots of cookies tie with a score of 1.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_large_tie_at_three(void) {
    std::string expected = "a\nb\nc\nd\ne\nf\ng\nh\ni\nj\nk\nl\nm\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("ties.csv", "2018-12-11");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when lots of cookies tie with a score of 3.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_1(void) {
    std::string expected = "a\nb\nc\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "1");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_2(void) {
    std::string expected = "a\nc\nb\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "2");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_3(void) {
    std::string expected = "b\na\nc\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "3");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_4(void) {
    std::string expected = "b\nc\na\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "4");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_5(void) {
    std::string expected = "c\na\nb\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "5");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_6(void) {
    std::string expected = "c\nb\na\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "6");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_large_1(void) {
    std::string expected = "b\nc\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "7");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering when tie values are large.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

void test_reorder_large_2(void) {
    std::string expected = "c\nb\n";

    std::stringstream buffer;
    // Redirect std::cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // BEGIN: Code being tested
    Dataframe df = Dataframe("reorder.csv", "8");
    df.printMostActiveCookie();
    // END:   Code being tested

    // Use the string value of buffer to compare against expected output
    std::string text = buffer.str();
    TEST_CHECK_(text == expected,
                "if the function fails when reordering when tie values are large.");

    // Restore original buffer before exiting
    std::cout.rdbuf(prevcoutbuf);
}

TEST_LIST = {
    {"test_file_that_does_not_exist", test_file_that_does_not_exist},
    {"test_date_does_not_exist", test_date_does_not_exist},
    {"test_file_is_empty", test_file_is_empty},
    {"test_one_entry", test_one_entry},
    {"test_cookie_log_date07", test_cookie_log_date07},
    {"test_cookie_log_date08", test_cookie_log_date08},
    {"test_cookie_log_date09", test_cookie_log_date09},
    {"test_win_at_two", test_win_at_two},
    {"test_large_tie_at_one", test_large_tie_at_one},
    {"test_large_tie_at_three", test_large_tie_at_three},
    {"test_reorder_1", test_reorder_1},
    {"test_reorder_2", test_reorder_2},
    {"test_reorder_3", test_reorder_3},
    {"test_reorder_4", test_reorder_4},
    {"test_reorder_5", test_reorder_5},
    {"test_reorder_6", test_reorder_6},
    {"test_reorder_large_1", test_reorder_large_1},
    {"test_reorder_large_2", test_reorder_large_2},
    {0} /*Terminate with {0}*/
};