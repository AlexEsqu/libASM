#include "inc/libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

// Color codes for output
#define BOLD "\033[1m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define GREY "\033[90m"
#define RESET "\033[0m"

void test_separator(const char *title) {
	printf("\n" BOLD "=== %s ===" RESET "\n\n", title);
}

void test_case(const char *description) {
	printf(BOLD "TEST: " RESET "%s\n", description);
}

void result_match(const char *label_custom, const char *label_orig) {
	printf(GREEN "✓ MATCH" RESET " - %s == %s \n", label_custom, label_orig);
}

void result_mismatch(const char *label_custom, const char *label_orig) {
	printf(RED "✗ MISMATCH" RESET " - %s != %s \n", label_custom, label_orig);
}

// ============================================================================
// STRLEN TESTS
// ============================================================================

void test_strlen(void) {
	test_separator("FT_STRLEN");

	// Test 1: Basic string
	test_case("Basic ASCII string");
	char *str1 = "hello";
	size_t len1_ft = ft_strlen(str1);
	size_t len1_c = ft_strlen_in_C(str1);
	size_t len1_libc = strlen(str1);
	printf("  ft_strlen in libASM (\"%s\") = %ld\n", str1, len1_ft);
	printf(GREY "  ft_strlen in libft  (\"%s\") = %ld\n" RESET, str1, len1_c);
	printf(GREY "     strlen in libc   (\"%s\") = %ld\n" RESET, str1, len1_libc);
	if (len1_ft == len1_c && len1_c == len1_libc) result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 2: Empty string
	test_case("Empty string");
	char *str2 = "";
	size_t len2_ft = ft_strlen(str2);
	size_t len2_c = ft_strlen_in_C(str2);
	size_t len2_libc = strlen(str2);
	printf("  ft_strlen in libASM (\"%s\") = %ld\n", str2, len2_ft);
	printf(GREY "  ft_strlen in libft  (\"%s\") = %ld\n" RESET, str2, len2_c);
	printf(GREY "     strlen in libc   (\"%s\") = %ld\n" RESET, str2, len2_libc);
	if (len2_ft == len2_c && len2_c == len2_libc) result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 3: String with special characters
	test_case("String with special characters");
	char *str3 = "hello\nworld\t!!";
	size_t len3_ft = ft_strlen(str3);
	size_t len3_c = ft_strlen_in_C(str3);
	size_t len3_libc = strlen(str3);
	printf("  ft_strlen in libASM (\"hello\\nworld\\t!!\") = %ld\n", len3_ft);
	printf(GREY "  ft_strlen in libft  (\"hello\\nworld\\t!!\") = %ld\n" RESET, len3_c);
	printf(GREY "     strlen in libc   (\"hello\\nworld\\t!!\") = %ld\n" RESET, len3_libc);
	if (len3_ft == len3_c && len3_c == len3_libc) result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 4: Long string
	test_case("Long string (100 characters)");
	char *str4 = "aaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	size_t len4_ft = ft_strlen(str4);
	size_t len4_c = ft_strlen_in_C(str4);
	size_t len4_libc = strlen(str4);
	printf("  ft_strlen in libASM (...) = %ld\n", len4_ft);
	printf(GREY "  ft_strlen in libft  (...) = %ld\n" RESET, len4_c);
	printf(GREY "     strlen in libc   (...) = %ld\n" RESET, len4_libc);
	if (len4_ft == len4_c && len4_c == len4_libc) result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 5: String with null bytes (only tests up to first null)
	test_case("Single character");
	char *str5 = "a\0a\0";
	size_t len5_ft = ft_strlen(str5);
	size_t len5_c = ft_strlen_in_C(str5);
	size_t len5_libc = strlen(str5);
	printf("  ft_strlen in libASM (\"%s\") = %ld\n", str5, len5_ft);
	printf(GREY "  ft_strlen in libft  (\"%s\") = %ld\n" RESET, str5, len5_c);
	printf(GREY "     strlen in libc   (\"%s\") = %ld\n" RESET, str5, len5_libc);
	if (len5_ft == len5_c && len5_c == len5_libc) result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");
}

// ============================================================================
// STRCMP TESTS
// ============================================================================

void test_strcmp(void) {
	test_separator("FT_STRCMP");

	// Test 1: Identical strings
	test_case("Identical strings");
	char *s1 = "hello", *s2 = "hello";
	int cmp1_ft = ft_strcmp(s1, s2);
	int cmp1_c = ft_strcmp_in_C(s1, s2);
	int cmp1_libc = strcmp(s1, s2);
	printf("  ft_strcmp in libASM (\"%s\", \"%s\") = %d\n", s1, s2, cmp1_ft);
	printf(GREY "  ft_strcmp in libft  (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp1_c);
	printf(GREY "     strcmp in libc   (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp1_libc);
	if ((cmp1_ft == 0 && cmp1_c == 0 && cmp1_libc == 0) ||
	    (cmp1_ft < 0 && cmp1_c < 0 && cmp1_libc < 0) ||
	    (cmp1_ft > 0 && cmp1_c > 0 && cmp1_libc > 0))
		result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 2: First string greater
	test_case("First string greater (lexicographical order)");
	s1 = "hello"; s2 = "apple";
	int cmp2_ft = ft_strcmp(s1, s2);
	int cmp2_c = ft_strcmp_in_C(s1, s2);
	int cmp2_libc = strcmp(s1, s2);
	printf("  ft_strcmp in libASM (\"%s\", \"%s\") = %d\n", s1, s2, cmp2_ft);
	printf(GREY "  ft_strcmp in libft  (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp2_c);
	printf(GREY "     strcmp in libc   (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp2_libc);
	if ((cmp2_ft > 0 && cmp2_c > 0 && cmp2_libc > 0) || (cmp2_ft < 0 && cmp2_c < 0 && cmp2_libc < 0) || (cmp2_ft == 0 && cmp2_c == 0 && cmp2_libc == 0))
		result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 3: Second string greater
	test_case("Second string greater (lexicographical order)");
	s1 = "apple"; s2 = "hello";
	int cmp3_ft = ft_strcmp(s1, s2);
	int cmp3_c = ft_strcmp_in_C(s1, s2);
	int cmp3_libc = strcmp(s1, s2);
	printf("  ft_strcmp in libASM (\"%s\", \"%s\") = %d\n", s1, s2, cmp3_ft);
	printf(GREY "  ft_strcmp in libft  (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp3_c);
	printf(GREY "     strcmp in libc   (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp3_libc);
	if ((cmp3_ft < 0 && cmp3_c < 0 && cmp3_libc < 0) || (cmp3_ft > 0 && cmp3_c > 0 && cmp3_libc > 0) || (cmp3_ft == 0 && cmp3_c == 0 && cmp3_libc == 0))
		result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 4: Empty strings
	test_case("Both empty strings");
	s1 = ""; s2 = "";
	int cmp4_ft = ft_strcmp(s1, s2);
	int cmp4_c = ft_strcmp_in_C(s1, s2);
	int cmp4_libc = strcmp(s1, s2);
	printf("  ft_strcmp in libASM (\"\", \"\") = %d\n", cmp4_ft);
	printf(GREY "  ft_strcmp in libft  (\"\", \"\") = %d\n" RESET, cmp4_c);
	printf(GREY "     strcmp in libc   (\"\", \"\") = %d\n" RESET, cmp4_libc);
	if (cmp4_ft == 0 && cmp4_c == 0 && cmp4_libc == 0) result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 5: One empty string
	test_case("First string empty, second non-empty");
	s1 = ""; s2 = "hello";
	int cmp5_ft = ft_strcmp(s1, s2);
	int cmp5_c = ft_strcmp_in_C(s1, s2);
	int cmp5_libc = strcmp(s1, s2);
	printf("  ft_strcmp in libASM (\"\", \"%s\") = %d\n", s2, cmp5_ft);
	printf(GREY "  ft_strcmp in libft  (\"\", \"%s\") = %d\n" RESET, s2, cmp5_c);
	printf(GREY "     strcmp in libc   (\"\", \"%s\") = %d\n" RESET, s2, cmp5_libc);
	if ((cmp5_ft < 0 && cmp5_c < 0 && cmp5_libc < 0) || (cmp5_ft > 0 && cmp5_c > 0 && cmp5_libc > 0) || (cmp5_ft == 0 && cmp5_c == 0 && cmp5_libc == 0))
		result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");

	// Test 6: Prefix comparison
	test_case("Prefix comparison");
	s1 = "hello"; s2 = "helloworld";
	int cmp6_ft = ft_strcmp(s1, s2);
	int cmp6_c = ft_strcmp_in_C(s1, s2);
	int cmp6_libc = strcmp(s1, s2);
	printf("  ft_strcmp in libASM (\"%s\", \"%s\") = %d\n", s1, s2, cmp6_ft);
	printf(GREY "  ft_strcmp in libft  (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp6_c);
	printf(GREY "     strcmp in libc   (\"%s\", \"%s\") = %d\n" RESET, s1, s2, cmp6_libc);
	if ((cmp6_ft < 0 && cmp6_c < 0 && cmp6_libc < 0) || (cmp6_ft > 0 && cmp6_c > 0 && cmp6_libc > 0) || (cmp6_ft == 0 && cmp6_c == 0 && cmp6_libc == 0))
		result_match("all three", "match");
	else result_mismatch("assembly/C/libc", "match");
	printf("\n");
}

// ============================================================================
// STRCPY TESTS
// ============================================================================

void test_strcpy(void) {
	test_separator("FT_STRCPY");

	// Test 1: Basic string copy
	test_case("Basic string copy");
	char buf_ft[50], buf_c[50], buf_libc[50];
	char *src1 = "hello";
	char *ret_ft = ft_strcpy(buf_ft, src1);
	char *ret_c = ft_strcpy_in_C(buf_c, src1);
	char *ret_libc = strcpy(buf_libc, src1);
	printf("  ft_strcpy in libASM (buf, \"%s\") = \"%s\"\n", src1, buf_ft);
	printf(GREY "  ft_strcpy in libft  (buf, \"%s\") = \"%s\"\n" RESET, src1, buf_c);
	printf(GREY "     strcpy in libc   (buf, \"%s\") = \"%s\"\n" RESET, src1, buf_libc);
	if (strcmp(buf_ft, buf_c) == 0) result_match("copy result", "match");
	else result_mismatch("copy result", "match");
	printf("\n");

	// Test 2: Empty string
	test_case("Empty string copy");
	char buf_orig[50];
	char *src2 = "";
	ret_ft = ft_strcpy(buf_ft, src2);
	ret_c = ft_strcpy_in_C(buf_c, src2);
	char *ret_orig = strcpy(buf_orig, src2);
	printf("  ft_strcpy in libASM (buf, \"\") = \"%s\"\n", buf_ft);
	printf(GREY "  ft_strcpy in libft  (buf, \"\") = \"%s\"\n" RESET, buf_c);
	printf(GREY "     strcpy in libc   (buf, \"\") = \"%s\"\n" RESET, buf_orig);
	if (strcmp(buf_ft, buf_c) == 0 && strcmp(buf_c, buf_orig) == 0) result_match("all three", "match");
	else result_mismatch("copy result", "match");
	printf("\n");

	// Test 3: String with special characters
	test_case("String with special characters");
	char *src3 = "hello\nworld\t!!";
	ret_ft = ft_strcpy(buf_ft, src3);
	ret_c = ft_strcpy_in_C(buf_c, src3);
	ret_orig = strcpy(buf_orig, src3);
	printf("  ft_strcpy in libASM (buf, \"hello\\nworld\\t!!\") = \"%s\"\n", buf_ft);
	printf(GREY "  ft_strcpy in libft  (buf, \"hello\\nworld\\t!!\") = \"%s\"\n" RESET, buf_c);
	printf(GREY "     strcpy in libc   (buf, \"hello\\nworld\\t!!\") = \"%s\"\n" RESET, buf_orig);
	if (strcmp(buf_ft, buf_c) == 0 && strcmp(buf_c, buf_orig) == 0) result_match("all three", "match");
	else result_mismatch("copy result", "match");
	printf("\n");

	// Test 4: Single character
	test_case("Single character copy");
	char *src4 = "a";
	ret_ft = ft_strcpy(buf_ft, src4);
	ret_c = ft_strcpy_in_C(buf_c, src4);
	ret_orig = strcpy(buf_orig, src4);
	printf("  ft_strcpy in libASM (buf, \"%s\") = \"%s\"\n", src4, buf_ft);
	printf(GREY "  ft_strcpy in libft  (buf, \"%s\") = \"%s\"\n" RESET, src4, buf_c);
	printf(GREY "     strcpy in libc   (buf, \"%s\") = \"%s\"\n" RESET, src4, buf_orig);
	printf("  ft_strcpy_in_C(buf, \"%s\") = \"%s\"\n", src4, buf_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "match");
	else result_mismatch("copy result", "match");
	printf("\n");

	// Test 5: Long string
	test_case("Long string copy");
	char *src5 = "The quick brown fox jumps over the lazy dog";
	ret_ft = ft_strcpy(buf_ft, src5);
	ret_c = ft_strcpy_in_C(buf_c, src5);
	ret_orig = strcpy(buf_orig, src5);
	printf("  ft_strcpy in libASM (buf, \"...\") = \"%s\"\n", buf_ft);
	printf(GREY "  ft_strcpy in libft  (buf, \"...\") = \"%s\"\n" RESET, buf_c);
	printf(GREY "     strcpy in libc   (buf, \"...\") = \"%s\"\n" RESET, buf_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "original");
	else result_mismatch("copy result", "original");
	printf("\n");

	// Test 6: Verify return value points to destination
	test_case("Return value points to destination buffer");
	ret_ft = ft_strcpy(buf_ft, "test");
	ret_c = ft_strcpy_in_C(buf_c, "test");
	ret_orig = strcpy(buf_orig, "test");
	printf("  ft_strcpy in libASM returns pointer to buf: %s\n", (ret_ft == buf_ft) ? "YES" : "NO");
	printf(GREY "  ft_strcpy in libft  returns pointer to buf: %s\n" RESET, (ret_c == buf_c) ? "YES" : "NO");
	printf(GREY "     strcpy in libc   returns pointer to buf: %s\n" RESET, (ret_orig == buf_orig) ? "YES" : "NO");
	if ((ret_ft == buf_ft) && (ret_orig == buf_orig) && (ret_libc == buf_libc)) result_match("return pointer", "original");
	else result_mismatch("return pointer", "original");
	printf("\n");
}

// ============================================================================
// STRDUP TESTS
// ============================================================================
// NOTE: ft_strdup not yet implemented in assembly, so this test is disabled
/*
void test_strdup(void) {
	test_separator("FT_STRDUP");

	// Test 1: Basic string duplication
	test_case("Basic string duplication");
	char *src1 = "hello";
	char *dup_ft = ft_strdup(src1);
	char *dup_c = ft_strdup_in_C(src1);
	char *dup_libc = strdup(src1);
	printf("  ft_strdup(\"%s\") = \"%s\"\n", src1, dup_ft ? dup_ft : "NULL");
	printf("  ft_strdup_in_C(\"%s\") = \"%s\"\n", src1, dup_c ? dup_c : "NULL");
	printf(GREY "  strdup(\"%s\") = \"%s\"\n" RESET, src1, dup_libc ? dup_libc : "NULL");
	if (dup_ft && dup_c && dup_libc && strcmp(dup_ft, dup_c) == 0 && strcmp(dup_c, dup_libc) == 0) result_match("duplicated string", "match");
	else if (!dup_ft && !dup_c && !dup_libc) result_match("all NULL", "match");
	else result_mismatch("duplicated string", "match");
	if (dup_ft && dup_c && dup_libc) printf("  Independent allocations: %s\n", (dup_ft != dup_c && dup_c != dup_libc) ? "YES" : "NO");
	printf("\n");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);

	// Test 2: Empty string
	test_case("Empty string duplication");
	char *src2 = "";
	dup_ft = ft_strdup(src2);
	dup_c = ft_strdup_in_C(src2);
	dup_libc = strdup(src2);
	printf("  ft_strdup(\"\") = \"%s\"\n", dup_ft ? dup_ft : "NULL");
	printf("  ft_strdup_in_C(\"\") = \"%s\"\n", dup_c ? dup_c : "NULL");
	printf(GREY "  strdup(\"\") = \"%s\"\n" RESET, dup_libc ? dup_libc : "NULL");
	if (dup_ft && dup_c && dup_libc && strcmp(dup_ft, dup_c) == 0 && strcmp(dup_c, dup_libc) == 0) result_match("empty string", "match");
	else if (!dup_ft && !dup_c && !dup_libc) result_match("all NULL", "match");
	else result_mismatch("empty string", "match");
	printf("\n");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);

	// Test 3: Long string
	test_case("Long string duplication");
	char *src3 = "The quick brown fox jumps over the lazy dog. "
	             "This is a longer string to test memory allocation.";
	dup_ft = ft_strdup(src3);
	dup_c = ft_strdup_in_C(src3);
	dup_libc = strdup(src3);
	printf("  ft_strdup(long_string) = \"%s\"\n", dup_ft ? dup_ft : "NULL");
	printf("  ft_strdup_in_C(long_string) = \"%s\"\n", dup_c ? dup_c : "NULL");
	printf(GREY "  strdup(long_string) = \"%s\"\n" RESET, dup_libc ? dup_libc : "NULL");
	if (dup_ft && dup_c && dup_libc && strcmp(dup_ft, dup_c) == 0 && strcmp(dup_c, dup_libc) == 0) result_match("long string", "match");
	else if (!dup_ft && !dup_c && !dup_libc) result_match("all NULL", "match");
	else result_mismatch("long string", "match");
	printf("\n");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);

	// Test 4: String with special characters
	test_case("String with special characters");
	char *src4 = "hello\nworld\t!!";
	dup_ft = ft_strdup(src4);
	dup_c = ft_strdup_in_C(src4);
	dup_libc = strdup(src4);
	printf("  ft_strdup(\"hello\\nworld\\t!!\") = \"%s\"\n", dup_ft ? dup_ft : "NULL");
	printf("  ft_strdup_in_C(\"hello\\nworld\\t!!\") = \"%s\"\n", dup_c ? dup_c : "NULL");
	printf(GREY "  strdup(\"hello\\nworld\\t!!\") = \"%s\"\n" RESET, dup_libc ? dup_libc : "NULL");
	if (dup_ft && dup_c && dup_libc && strcmp(dup_ft, dup_c) == 0 && strcmp(dup_c, dup_libc) == 0) result_match("special chars", "match");
	else if (!dup_ft && !dup_c && !dup_libc) result_match("all NULL", "match");
	else result_mismatch("special chars", "match");
	printf("\n");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);

	// Test 5: Single character
	test_case("Single character duplication");
	char *src5 = "X";
	dup_ft = ft_strdup(src5);
	dup_c = ft_strdup_in_C(src5);
	dup_libc = strdup(src5);
	printf("  ft_strdup(\"%s\") = \"%s\"\n", src5, dup_ft ? dup_ft : "NULL");
	printf("  ft_strdup_in_C(\"%s\") = \"%s\"\n", src5, dup_c ? dup_c : "NULL");
	printf(GREY "  strdup(\"%s\") = \"%s\"\n" RESET, src5, dup_libc ? dup_libc : "NULL");
	if (dup_ft && dup_c && dup_libc && strcmp(dup_ft, dup_c) == 0 && strcmp(dup_c, dup_libc) == 0) result_match("single char", "match");
	else if (!dup_ft && !dup_c && !dup_libc) result_match("all NULL", "match");
	else result_mismatch("single char", "match");
	printf("\n");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);
}
*/

// // ============================================================================
// // WRITE TESTS
// // ============================================================================

// void test_write(void) {
// 	test_separator("FT_WRITE");

// 	// Test 1: Write to stdout
// 	test_case("Write string to stdout (fd=1)");
// 	char *msg1 = "Hello from ft_write!\n";
// 	printf("  ft_write(1, \"%s\", %lu) returns: ", msg1, strlen(msg1));
// 	ssize_t ret_ft = ft_write(1, msg1, strlen(msg1));
// 	printf("%ld\n", ret_ft);
// 	printf(GREY "  write(1, \"%s\", %lu) returns: ", msg1, strlen(msg1));
// 	ssize_t ret_orig = write(1, msg1, strlen(msg1));
// 	printf("%ld \n" RESET, ret_orig);
// 	if (ret_ft == ret_orig) result_match("bytes written", "original");
// 	else result_mismatch("bytes written", "original");
// 	printf("\n");

// 	// Test 2: Write partial data
// 	test_case("Write partial data (5 bytes from 'hello world')");
// 	char *msg2 = "hello world";
// 	printf("  ft_write(1, \"%s\", 5) returns: ", msg2);
// 	ret_ft = ft_write(1, msg2, 5);
// 	printf("%ld\n", ret_ft);
// 	printf("\n");
// 	printf(GREY "  write(1, \"%s\", 5) returns: ", msg2);
// 	ret_orig = write(1, msg2, 5);
// 	printf("%ld \n" RESET, ret_orig);
// 	printf("\n");
// 	if (ret_ft == ret_orig) result_match("bytes written", "original");
// 	else result_mismatch("bytes written", "original");
// 	printf("\n");

// 	// Test 3: Write zero bytes
// 	test_case("Write zero bytes");
// 	printf("  ft_write(1, \"data\", 0) returns: ");
// 	ret_ft = ft_write(1, "data", 0);
// 	printf("%ld\n", ret_ft);
// 	printf(GREY "  write(1, \"data\", 0) returns: ");
// 	ret_orig = write(1, "data", 0);
// 	printf("%ld \n" RESET, ret_orig);
// 	if (ret_ft == ret_orig) result_match("bytes written", "original");
// 	else result_mismatch("bytes written", "original");
// 	printf("\n");

// 	// Test 4: Write to file
// 	test_case("Write to file (test_output.txt)");
// 	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1) {
// 		char *msg4 = "Test write to file\n";
// 		printf("  ft_write(fd, \"%s\", %lu) returns: ", msg4, strlen(msg4));
// 		ret_ft = ft_write(fd, msg4, strlen(msg4));
// 		printf("%ld\n", ret_ft);
// 		close(fd);

// 		fd = open("test_output.txt", O_WRONLY | O_APPEND);
// 		printf(GREY "  write(fd, \"%s\", %lu) returns: ", msg4, strlen(msg4));
// 		ret_orig = strlen(msg4);
// 		printf("%ld (original would also write)\n" RESET, ret_orig);
// 		close(fd);
// 		printf("  File created successfully\n");
// 	} else {
// 		printf("  Error opening file\n");
// 	}
// 	printf("\n");

// 	// Test 5: Write to stderr
// 	test_case("Write to stderr (fd=2)");
// 	char *msg5 = "Error message via ft_write!\n";
// 	printf("  ft_write(2, error_msg, %lu) returns: ", strlen(msg5));
// 	ret_ft = ft_write(2, msg5, strlen(msg5));
// 	printf("%ld\n", ret_ft);
// 	printf(GREY "  write(2, error_msg, %lu) returns: ", strlen(msg5));
// 	ret_orig = write(2, msg5, strlen(msg5));
// 	printf("%ld \n" RESET, ret_orig);
// 	if (ret_ft == ret_orig) result_match("bytes written", "original");
// 	else result_mismatch("bytes written", "original");
// 	printf("\n");
// }

// // ============================================================================
// // READ TESTS
// // ============================================================================

// void test_read(void) {
// 	test_separator("FT_READ");

// 	// Test 1: Create test file
// 	int fd = open("test_input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1) {
// 		write(fd, "Hello from file!\n", 17);
// 		write(fd, "Second line\n", 12);
// 		close(fd);
// 	}

// 	// Test 2: Read from file
// 	test_case("Read from file (test_input.txt)");
// 	char buf_ft[100] = {0}, buf_orig[100] = {0};
// 	fd = open("test_input.txt", O_RDONLY);
// 	if (fd != -1) {
// 		ssize_t ret_ft = ft_read(fd, buf_ft, 50);
// 		printf("  ft_read(fd, buf, 50) returns: %ld\n", ret_ft);
// 		printf("    buffer content: \"%s\"\n", buf_ft);
// 		close(fd);

// 		fd = open("test_input.txt", O_RDONLY);
// 		ssize_t ret_orig = read(fd, buf_orig, 50);
// 		printf(GREY "  read(fd, buf, 50) returns: %ld\n", ret_orig);
// 		printf("    buffer content: \"%s\" \n" RESET, buf_orig);
// 		close(fd);

// 		if (ret_ft == ret_orig && strcmp(buf_ft, buf_orig) == 0)
// 			result_match("bytes read and content", "original");
// 		else result_mismatch("bytes read or content", "original");
// 	}
// 	printf("\n");

// 	// Test 3: Read zero bytes
// 	test_case("Read zero bytes");
// 	fd = open("test_input.txt", O_RDONLY);
// 	if (fd != -1) {
// 		printf("  ft_read(fd, buf, 0) returns: ");
// 		ssize_t ret_ft = ft_read(fd, buf_ft, 0);
// 		printf("%ld\n", ret_ft);
// 		close(fd);

// 		fd = open("test_input.txt", O_RDONLY);
// 		printf(GREY "  read(fd, buf, 0) returns: ");
// 		ssize_t ret_orig = read(fd, buf_orig, 0);
// 		printf("%ld \n" RESET, ret_orig);
// 		close(fd);

// 		if (ret_ft == ret_orig) result_match("bytes read", "original");
// 		else result_mismatch("bytes read", "original");
// 	}
// 	printf("\n");

// 	// Test 4: Read exact file size
// 	test_case("Read exact file size");
// 	fd = open("test_input.txt", O_RDONLY);
// 	if (fd != -1) {
// 		memset(buf_ft, 0, 100);
// 		memset(buf_orig, 0, 100);
// 		ssize_t ret_ft = ft_read(fd, buf_ft, 100);
// 		printf("  ft_read(fd, buf, 100) returns: %ld\n", ret_ft);
// 		printf("    buffer: \"%s\"\n", buf_ft);
// 		close(fd);

// 		fd = open("test_input.txt", O_RDONLY);
// 		ssize_t ret_orig = read(fd, buf_orig, 100);
// 		printf(GREY "  read(fd, buf, 100) returns: %ld\n", ret_orig);
// 		printf("    buffer: \"%s\" \n" RESET, buf_orig);
// 		close(fd);

// 		if (ret_ft == ret_orig) result_match("bytes read", "original");
// 		else result_mismatch("bytes read", "original");
// 	}
// 	printf("\n");

// 	// Test 5: Read from stdin (non-interactive warning)
// 	test_case("Read capability from stdin (skipped - non-interactive)");
// 	printf("  (This test requires interactive input and is skipped)\n");
// 	printf("\n");
// }

// ============================================================================
// MAIN
// ============================================================================

int main(void) {
	printf("\n" BOLD BOLD "╔════════════════════════════════════════════════════════════════╗\n");
	printf("║         LIBRARY FUNCTION TESTS (libASM vs Standard C)          ║\n");
	printf("╚════════════════════════════════════════════════════════════════╝" RESET "\n");

	printf(GREY "Gray text indicates original standard library function results\n" RESET);
	printf(GREEN "Green checkmarks show matching behavior\n" RESET);
	printf(RED "Red X marks show mismatched behavior\n" RESET);

	test_strlen();
	test_strcmp();
	test_strcpy();
	// test_strdup();  // ft_strdup not yet implemented in assembly
	// test_write();
	// test_read();

	printf("\n" BOLD "═══════════════════════════════════════════════════════════════════\n");
	printf("Tests completed!" RESET "\n\n");

	return (0);
}
