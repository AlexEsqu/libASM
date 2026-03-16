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
	size_t len1_orig = strlen(str1);  // original
	printf("  ft_strlen(\"%s\") = %ld\n", str1, len1_ft);
	printf(GREY "     strlen(\"%s\") = %ld \n" RESET, str1, len1_orig);
	if (len1_ft == len1_orig) result_match("ft_strlen", "strlen");
	else result_mismatch("ft_strlen", "strlen");
	printf("\n");

	// Test 2: Empty string
	test_case("Empty string");
	char *str2 = "";
	size_t len2_ft = ft_strlen(str2);
	size_t len2_orig = strlen(str2);  // original
	printf("  ft_strlen(\"%s\") = %ld\n", str2, len2_ft);
	printf(GREY "     strlen(\"%s\") = %ld \n" RESET, str2, len2_orig);
	if (len2_ft == len2_orig) result_match("ft_strlen", "strlen");
	else result_mismatch("ft_strlen", "strlen");
	printf("\n");

	// Test 3: String with special characters
	test_case("String with special characters");
	char *str3 = "hello\nworld\t!!";
	size_t len3_ft = ft_strlen(str3);
	size_t len3_orig = strlen(str3);  // original
	printf("  ft_strlen(\"%s\") = %ld\n", str3, len3_ft);
	printf(GREY "     strlen(\"%s\") = %ld \n" RESET, str3, len3_orig);
	if (len3_ft == len3_orig) result_match("ft_strlen", "strlen");
	else result_mismatch("ft_strlen", "strlen");
	printf("\n");

	// Test 4: Long string
	test_case("Long string (100 characters)");
	char *str4 = "aaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	size_t len4_ft = ft_strlen(str4);
	size_t len4_orig = strlen(str4);  // original
	printf("  ft_strlen(\"%s\") = %ld\n", str4, len4_ft);
	printf(GREY "     strlen(\"%s\") = %ld \n" RESET, str4, len4_orig);
	if (len4_ft == len4_orig) result_match("ft_strlen", "strlen");
	else result_mismatch("ft_strlen", "strlen");
	printf("\n");

	// Test 5: String with null bytes (only tests up to first null)
	test_case("Single character");
	char *str5 = "a\0a\0";
	size_t len5_ft = ft_strlen(str5);
	size_t len5_orig = strlen(str5);  // original
	printf("  ft_strlen(\"%s\") = %ld\n", str5, len5_ft);
	printf(GREY "     strlen(\"%s\") = %ld \n" RESET, str5, len5_orig);
	if (len5_ft == len5_orig) result_match("ft_strlen", "strlen");
	else result_mismatch("ft_strlen", "strlen");
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
	int cmp1_orig = strcmp(s1, s2);  // original
	printf("  ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s2, cmp1_ft);
	printf(GREY "     strcmp(\"%s\", \"%s\") = %d \n" RESET, s1, s2, cmp1_orig);
	if ((cmp1_ft == 0 && cmp1_orig == 0) || (cmp1_ft < 0 && cmp1_orig < 0) || (cmp1_ft > 0 && cmp1_orig > 0))
		result_match("ft_strcmp", "strcmp");
	else result_mismatch("ft_strcmp", "strcmp");
	printf("\n");

	// Test 2: First string greater
	test_case("First string greater (lexicographical order)");
	s1 = "hello"; s2 = "apple";
	int cmp2_ft = ft_strcmp(s1, s2);
	int cmp2_orig = strcmp(s1, s2);  // original
	printf("  ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s2, cmp2_ft);
	printf(GREY "     strcmp(\"%s\", \"%s\") = %d \n" RESET, s1, s2, cmp2_orig);
	if ((cmp2_ft > 0 && cmp2_orig > 0) || (cmp2_ft < 0 && cmp2_orig < 0) || (cmp2_ft == 0 && cmp2_orig == 0))
		result_match("ft_strcmp", "strcmp");
	else result_mismatch("ft_strcmp", "strcmp");
	printf("\n");

	// Test 3: Second string greater
	test_case("Second string greater (lexicographical order)");
	s1 = "apple"; s2 = "hello";
	int cmp3_ft = ft_strcmp(s1, s2);
	int cmp3_orig = strcmp(s1, s2);  // original
	printf("  ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s2, cmp3_ft);
	printf(GREY "     strcmp(\"%s\", \"%s\") = %d \n" RESET, s1, s2, cmp3_orig);
	if ((cmp3_ft < 0 && cmp3_orig < 0) || (cmp3_ft > 0 && cmp3_orig > 0) || (cmp3_ft == 0 && cmp3_orig == 0))
		result_match("ft_strcmp", "strcmp");
	else result_mismatch("ft_strcmp", "strcmp");
	printf("\n");

	// Test 4: Empty strings
	test_case("Both empty strings");
	s1 = ""; s2 = "";
	int cmp4_ft = ft_strcmp(s1, s2);
	int cmp4_orig = strcmp(s1, s2);  // original
	printf("  ft_strcmp(\"\", \"\") = %d\n", cmp4_ft);
	printf(GREY "     strcmp(\"\", \"\") = %d \n" RESET, cmp4_orig);
	if (cmp4_ft == 0 && cmp4_orig == 0) result_match("ft_strcmp", "strcmp");
	else result_mismatch("ft_strcmp", "strcmp");
	printf("\n");

	// Test 5: One empty string
	test_case("First string empty, second non-empty");
	s1 = ""; s2 = "hello";
	int cmp5_ft = ft_strcmp(s1, s2);
	int cmp5_orig = strcmp(s1, s2);  // original
	printf("  ft_strcmp(\"\", \"%s\") = %d\n", s2, cmp5_ft);
	printf(GREY "     strcmp(\"\", \"%s\") = %d \n" RESET, s2, cmp5_orig);
	if ((cmp5_ft < 0 && cmp5_orig < 0) || (cmp5_ft > 0 && cmp5_orig > 0) || (cmp5_ft == 0 && cmp5_orig == 0))
		result_match("ft_strcmp", "strcmp");
	else result_mismatch("ft_strcmp", "strcmp");
	printf("\n");

	// Test 6: Prefix comparison
	test_case("Prefix comparison");
	s1 = "hello"; s2 = "helloworld";
	int cmp6_ft = ft_strcmp(s1, s2);
	int cmp6_orig = strcmp(s1, s2);  // original
	printf("  ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s2, cmp6_ft);
	printf(GREY "     strcmp(\"%s\", \"%s\") = %d \n" RESET, s1, s2, cmp6_orig);
	if ((cmp6_ft < 0 && cmp6_orig < 0) || (cmp6_ft > 0 && cmp6_orig > 0) || (cmp6_ft == 0 && cmp6_orig == 0))
		result_match("ft_strcmp", "strcmp");
	else result_mismatch("ft_strcmp", "strcmp");
	printf("\n");
}

// ============================================================================
// STRCPY TESTS
// ============================================================================

void test_strcpy(void) {
	test_separator("FT_STRCPY");

	// Test 1: Basic string copy
	test_case("Basic string copy");
	char buf_ft[50], buf_orig[50];
	char *src1 = "hello";
	char *ret_ft = ft_strcpy(buf_ft, src1);
	char *ret_orig = strcpy(buf_orig, src1);  // original
	printf("  ft_strcpy(buf, \"%s\")\n", src1);
	printf("    buffer: \"%s\", returns: \"%s\"\n", buf_ft, ret_ft);
	printf(GREY "  strcpy(buf, \"%s\") \n" RESET, src1);
	printf(GREY "    buffer: \"%s\", returns: \"%s\"\n" RESET, buf_orig, ret_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "original");
	else result_mismatch("copy result", "original");
	printf("\n");

	// Test 2: Empty string
	test_case("Empty string copy");
	char *src2 = "";
	ret_ft = ft_strcpy(buf_ft, src2);
	ret_orig = strcpy(buf_orig, src2);  // original
	printf("  ft_strcpy(buf, \"\")\n");
	printf("    buffer: \"%s\", returns: \"%s\"\n", buf_ft, ret_ft);
	printf(GREY "  strcpy(buf, \"\") \n" RESET);
	printf(GREY "    buffer: \"%s\", returns: \"%s\"\n" RESET, buf_orig, ret_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "original");
	else result_mismatch("copy result", "original");
	printf("\n");

	// Test 3: String with special characters
	test_case("String with special characters");
	char *src3 = "hello\nworld\t!!";
	ret_ft = ft_strcpy(buf_ft, src3);
	ret_orig = strcpy(buf_orig, src3);  // original
	printf("  ft_strcpy(buf, \"hello\\nworld\\t!!\")\n");
	printf("    buffer: \"%s\", returns: \"%s\"\n", buf_ft, ret_ft);
	printf(GREY "  strcpy(buf, \"hello\\nworld\\t!!\") \n" RESET);
	printf(GREY "    buffer: \"%s\", returns: \"%s\"\n" RESET, buf_orig, ret_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "original");
	else result_mismatch("copy result", "original");
	printf("\n");

	// Test 4: Single character
	test_case("Single character copy");
	char *src4 = "a";
	ret_ft = ft_strcpy(buf_ft, src4);
	ret_orig = strcpy(buf_orig, src4);  // original
	printf("  ft_strcpy(buf, \"%s\")\n", src4);
	printf("    buffer: \"%s\", returns: \"%s\"\n", buf_ft, ret_ft);
	printf(GREY "  strcpy(buf, \"%s\") \n" RESET, src4);
	printf(GREY "    buffer: \"%s\", returns: \"%s\"\n" RESET, buf_orig, ret_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "original");
	else result_mismatch("copy result", "original");
	printf("\n");

	// Test 5: Long string
	test_case("Long string copy");
	char *src5 = "The quick brown fox jumps over the lazy dog";
	ret_ft = ft_strcpy(buf_ft, src5);
	ret_orig = strcpy(buf_orig, src5);  // original
	printf("  ft_strcpy(buf, \"The quick brown fox jumps over the lazy dog\")\n");
	printf("    buffer: \"%s\"\n", buf_ft);
	printf(GREY "  strcpy(buf, \"The quick brown fox jumps over the lazy dog\") \n" RESET);
	printf(GREY "    buffer: \"%s\"\n" RESET, buf_orig);
	if (strcmp(buf_ft, buf_orig) == 0) result_match("copy result", "original");
	else result_mismatch("copy result", "original");
	printf("\n");

	// Test 6: Verify return value points to destination
	test_case("Return value points to destination buffer");
	ret_ft = ft_strcpy(buf_ft, "test");
	ret_orig = strcpy(buf_orig, "test");  // original
	printf("  ft_strcpy returns pointer to buf: %s\n", (ret_ft == buf_ft) ? "YES" : "NO");
	printf(GREY "  strcpy returns pointer to buf: %s \n" RESET, (ret_orig == buf_orig) ? "YES" : "NO");
	if ((ret_ft == buf_ft) && (ret_orig == buf_orig)) result_match("return pointer", "original");
	else result_mismatch("return pointer", "original");
	printf("\n");
}

// // ============================================================================
// // STRDUP TESTS
// // ============================================================================

// void test_strdup(void) {
// 	test_separator("FT_STRDUP");

// 	// Test 1: Basic string duplication
// 	test_case("Basic string duplication");
// 	char *src1 = "hello";
// 	char *dup_ft = ft_strdup(src1);
// 	char *dup_orig = strdup(src1);  // original
// 	printf("  ft_strdup(\"%s\") = \"%s\"\n", src1, dup_ft ? dup_ft : "NULL");
// 	printf(GREY "  strdup(\"%s\") = \"%s\" \n" RESET, src1, dup_orig ? dup_orig : "NULL");
// 	if (dup_ft && dup_orig && strcmp(dup_ft, dup_orig) == 0) result_match("duplicated string", "original");
// 	else if (!dup_ft && !dup_orig) result_match("both NULL", "original");
// 	else result_mismatch("duplicated string", "original");
// 	if (dup_ft && dup_orig) printf("  Independent allocations: %s\n", (dup_ft != dup_orig) ? "YES" : "NO");
// 	printf("\n");

// 	free(dup_ft);
// 	free(dup_orig);

// 	// Test 2: Empty string
// 	test_case("Empty string duplication");
// 	char *src2 = "";
// 	dup_ft = ft_strdup(src2);
// 	dup_orig = strdup(src2);  // original
// 	printf("  ft_strdup(\"\") = \"%s\"\n", dup_ft ? dup_ft : "NULL");
// 	printf(GREY "  strdup(\"\") = \"%s\" \n" RESET, dup_orig ? dup_orig : "NULL");
// 	if (dup_ft && dup_orig && strcmp(dup_ft, dup_orig) == 0) result_match("duplicated string", "original");
// 	else result_mismatch("duplicated string", "original");
// 	printf("\n");

// 	free(dup_ft);
// 	free(dup_orig);

// 	// Test 3: Long string
// 	test_case("Long string duplication");
// 	char *src3 = "The quick brown fox jumps over the lazy dog. "
// 	             "This is a longer string to test memory allocation.";
// 	dup_ft = ft_strdup(src3);
// 	dup_orig = strdup(src3);  // original
// 	printf("  ft_strdup(long_string) = \"%s\"\n", dup_ft ? dup_ft : "NULL");
// 	printf(GREY "  strdup(long_string) = \"%s\" \n" RESET, dup_orig ? dup_orig : "NULL");
// 	if (dup_ft && dup_orig && strcmp(dup_ft, dup_orig) == 0) result_match("duplicated string", "original");
// 	else result_mismatch("duplicated string", "original");
// 	printf("\n");

// 	free(dup_ft);
// 	free(dup_orig);

// 	// Test 4: String with special characters
// 	test_case("String with special characters");
// 	char *src4 = "hello\nworld\t!!";
// 	dup_ft = ft_strdup(src4);
// 	dup_orig = strdup(src4);  // original
// 	printf("  ft_strdup(\"hello\\nworld\\t!!\") = \"%s\"\n", dup_ft ? dup_ft : "NULL");
// 	printf(GREY "  strdup(\"hello\\nworld\\t!!\") = \"%s\" \n" RESET, dup_orig ? dup_orig : "NULL");
// 	if (dup_ft && dup_orig && strcmp(dup_ft, dup_orig) == 0) result_match("duplicated string", "original");
// 	else result_mismatch("duplicated string", "original");
// 	printf("\n");

// 	free(dup_ft);
// 	free(dup_orig);

// 	// Test 5: Single character
// 	test_case("Single character duplication");
// 	char *src5 = "X";
// 	dup_ft = ft_strdup(src5);
// 	dup_orig = strdup(src5);  // original
// 	printf("  ft_strdup(\"%s\") = \"%s\"\n", src5, dup_ft ? dup_ft : "NULL");
// 	printf(GREY "  strdup(\"%s\") = \"%s\" \n" RESET, src5, dup_orig ? dup_orig : "NULL");
// 	if (dup_ft && dup_orig && strcmp(dup_ft, dup_orig) == 0) result_match("duplicated string", "original");
// 	else result_mismatch("duplicated string", "original");
// 	printf("\n");

// 	free(dup_ft);
// 	free(dup_orig);
// }

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
	// test_strdup();
	// test_write();
	// test_read();

	printf("\n" BOLD "═══════════════════════════════════════════════════════════════════\n");
	printf("Tests completed!" RESET "\n\n");

	return (0);
}
