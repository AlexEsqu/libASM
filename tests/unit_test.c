#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include "../inc/libft.h"

// ============================================================================
// FT_STRLEN TESTS
// ============================================================================


Test(ft_strlen, basic_ascii_string) {
	char *str = "hello";
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, 5, "ft_strlen should return 5 for 'hello'");
	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
}

Test(ft_strlen, empty_string) {
	char *str = "";
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, 0, "ft_strlen should return 0 for empty string");
	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
}

Test(ft_strlen, special_characters) {
	char *str = "hello\nworld\t!!";
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
}

Test(ft_strlen, long_string) {
	char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, 104, "ft_strlen should return 104 for 104 'a's");
	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
}

Test(ft_strlen, single_character) {
	char *str = "a\0a\0";
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, 1, "ft_strlen should stop at null terminator");
	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
}

Test(ft_strlen, with_null_in_middle) {
	char str[] = "hello\0world\0end";
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, 5, "ft_strlen should stop at first null terminator");
	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
}

Test(ft_strlen, large_string) {
	char *str = malloc(5000);
	memset(str, 'a', 4999);
	str[4999] = '\0';
	size_t len_ft = ft_strlen(str);
	size_t len_c = ft_strlen_in_C(str);
	size_t len_libc = strlen(str);

	cr_assert_eq(len_ft, 4999, "ft_strlen should handle large strings");
	cr_assert_eq(len_ft, len_c, "ft_strlen should match ft_strlen_in_C");
	cr_assert_eq(len_ft, len_libc, "ft_strlen should match libc strlen");
	free(str);
}

// ============================================================================
// FT_STRCMP TESTS
// ============================================================================

Test(ft_strcmp, identical_strings) {
	char *s1 = "hello", *s2 = "hello";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_c = ft_strcmp_in_C(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_eq(cmp_ft, 0, "ft_strcmp should return 0 for identical strings");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_c > 0) - (cmp_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp sign");
}

Test(ft_strcmp, first_string_greater) {
	char *s1 = "hello", *s2 = "apple";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_c = ft_strcmp_in_C(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_gt(cmp_ft, 0, "ft_strcmp should return positive for 'hello' > 'apple'");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_c > 0) - (cmp_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp sign");
}

Test(ft_strcmp, second_string_greater) {
	char *s1 = "apple", *s2 = "hello";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_c = ft_strcmp_in_C(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_lt(cmp_ft, 0, "ft_strcmp should return negative for 'apple' < 'hello'");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_c > 0) - (cmp_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp sign");
}

Test(ft_strcmp, both_empty_strings) {
	char *s1 = "", *s2 = "";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_c = ft_strcmp_in_C(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_eq(cmp_ft, 0, "ft_strcmp should return 0 for two empty strings");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_c > 0) - (cmp_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp sign");
}

Test(ft_strcmp, first_empty_second_not) {
	char *s1 = "", *s2 = "hello";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_c = ft_strcmp_in_C(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_lt(cmp_ft, 0, "ft_strcmp should return negative for empty < non-empty");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_c > 0) - (cmp_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp sign");
}

Test(ft_strcmp, prefix_comparison) {
	char *s1 = "hello", *s2 = "helloworld";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_c = ft_strcmp_in_C(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_lt(cmp_ft, 0, "ft_strcmp should return negative for prefix");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_c > 0) - (cmp_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp sign");
}

Test(ft_strcmp, case_sensitive) {
	int result_ABC = ft_strcmp("ABC", "abc");
	int result_c_ABC = ft_strcmp_in_C("ABC", "abc");

	cr_assert_neq(result_ABC, 0, "ft_strcmp should be case sensitive");
	cr_assert_eq((result_ABC > 0) - (result_ABC < 0), (result_c_ABC > 0) - (result_c_ABC < 0),
		"ft_strcmp case sensitivity should match ft_strcmp_in_C");
}

Test(ft_strcmp, single_char_difference) {
	int cmp_a_b = ft_strcmp("a", "b");
	int cmp_a_b_c = ft_strcmp_in_C("a", "b");

	cr_assert_lt(cmp_a_b, 0, "ft_strcmp should return negative for 'a' < 'b'");
	cr_assert_eq((cmp_a_b > 0) - (cmp_a_b < 0), (cmp_a_b_c > 0) - (cmp_a_b_c < 0),
		"ft_strcmp should match ft_strcmp_in_C sign");
}

Test(ft_strcmp, different_lengths) {
	char *s1 = "test";
	char *s2 = "testing";
	int cmp_ft = ft_strcmp(s1, s2);
	int cmp_libc = strcmp(s1, s2);

	cr_assert_lt(cmp_ft, 0, "Shorter prefix should be less");
	cr_assert_eq((cmp_ft > 0) - (cmp_ft < 0), (cmp_libc > 0) - (cmp_libc < 0),
		"ft_strcmp should match libc strcmp");
}

// ============================================================================
// FT_STRCPY TESTS
// ============================================================================

Test(ft_strcpy, basic_string_copy) {
	char buf_ft[50], buf_c[50], buf_libc[50];
	char *src = "hello";

	ft_strcpy(buf_ft, src);
	ft_strcpy_in_C(buf_c, src);
	strcpy(buf_libc, src);

	cr_assert_str_eq(buf_ft, "hello", "ft_strcpy should copy 'hello'");
	cr_assert_str_eq(buf_ft, buf_c, "ft_strcpy should match ft_strcpy_in_C");
	cr_assert_str_eq(buf_ft, buf_libc, "ft_strcpy should match libc strcpy");
}

Test(ft_strcpy, empty_string_copy) {
	char buf_ft[50], buf_c[50], buf_libc[50];
	char *src = "";

	ft_strcpy(buf_ft, src);
	ft_strcpy_in_C(buf_c, src);
	strcpy(buf_libc, src);

	cr_assert_str_eq(buf_ft, "", "ft_strcpy should copy empty string");
	cr_assert_str_eq(buf_ft, buf_c, "ft_strcpy should match ft_strcpy_in_C");
	cr_assert_str_eq(buf_ft, buf_libc, "ft_strcpy should match libc strcpy");
}

Test(ft_strcpy, special_characters) {
	char buf_ft[50], buf_c[50], buf_libc[50];
	char *src = "hello\nworld\t!!";

	ft_strcpy(buf_ft, src);
	ft_strcpy_in_C(buf_c, src);
	strcpy(buf_libc, src);

	cr_assert_str_eq(buf_ft, buf_c, "ft_strcpy should match ft_strcpy_in_C");
	cr_assert_str_eq(buf_ft, buf_libc, "ft_strcpy should match libc strcpy");
}

Test(ft_strcpy, single_character) {
	char buf_ft[50], buf_c[50], buf_libc[50];
	char *src = "a";

	ft_strcpy(buf_ft, src);
	ft_strcpy_in_C(buf_c, src);
	strcpy(buf_libc, src);

	cr_assert_str_eq(buf_ft, "a", "ft_strcpy should copy single character");
	cr_assert_str_eq(buf_ft, buf_c, "ft_strcpy should match ft_strcpy_in_C");
	cr_assert_str_eq(buf_ft, buf_libc, "ft_strcpy should match libc strcpy");
}

Test(ft_strcpy, long_string) {
	char buf_ft[100], buf_c[100], buf_libc[100];
	char *src = "The quick brown fox jumps over the lazy dog";

	ft_strcpy(buf_ft, src);
	ft_strcpy_in_C(buf_c, src);
	strcpy(buf_libc, src);

	cr_assert_str_eq(buf_ft, buf_c, "ft_strcpy should match ft_strcpy_in_C");
	cr_assert_str_eq(buf_ft, buf_libc, "ft_strcpy should match libc strcpy");
}

Test(ft_strcpy, return_value) {
	char buf_ft[50], buf_c[50], buf_libc[50];
	char *ret_ft = ft_strcpy(buf_ft, "test");
	char *ret_c = ft_strcpy_in_C(buf_c, "test");
	char *ret_libc = strcpy(buf_libc, "test");

	cr_assert_eq(ret_ft, buf_ft, "ft_strcpy should return pointer to destination");
	cr_assert_eq(ret_c, buf_c, "ft_strcpy_in_C should return pointer to destination");
	cr_assert_eq(ret_libc, buf_libc, "libc strcpy should return pointer to destination");
}

Test(ft_strcpy, buffer_ends_correctly) {
	char buf_ft[10], buf_c[10], buf_libc[10];
	char *src = "12345";

	ft_strcpy(buf_ft, src);
	ft_strcpy_in_C(buf_c, src);
	strcpy(buf_libc, src);

	cr_assert_eq(buf_ft[5], '\0', "ft_strcpy should null-terminate");
	cr_assert_eq(buf_c[5], '\0', "ft_strcpy_in_C should null-terminate");
	cr_assert_eq(buf_libc[5], '\0', "libc strcpy should null-terminate");
}

// ============================================================================
// FT_STRDUP TESTS
// ============================================================================

Test(ft_strdup, basic_duplication) {
	char *src = "hello";
	char *dup_ft = ft_strdup(src);
	char *dup_c = ft_strdup_in_C(src);
	char *dup_libc = strdup(src);

	cr_assert_not_null(dup_ft, "ft_strdup should allocate memory");
	cr_assert_not_null(dup_c, "ft_strdup_in_C should allocate memory");
	cr_assert_not_null(dup_libc, "libc strdup should allocate memory");

	cr_assert_str_eq(dup_ft, "hello", "ft_strdup should duplicate 'hello'");
	cr_assert_str_eq(dup_ft, dup_c, "ft_strdup should match ft_strdup_in_C");
	cr_assert_str_eq(dup_ft, dup_libc, "ft_strdup should match libc strdup");

	cr_assert_neq(dup_ft, dup_c, "Duplications should have different addresses");
	cr_assert_neq(dup_c, dup_libc, "Duplications should have different addresses");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);
}

Test(ft_strdup, empty_string) {
	char *src = "";
	char *dup_ft = ft_strdup(src);
	char *dup_c = ft_strdup_in_C(src);
	char *dup_libc = strdup(src);

	cr_assert_not_null(dup_ft, "ft_strdup should allocate memory for empty string");
	cr_assert_not_null(dup_c, "ft_strdup_in_C should allocate memory for empty string");
	cr_assert_not_null(dup_libc, "libc strdup should allocate memory for empty string");

	cr_assert_str_eq(dup_ft, "", "ft_strdup should duplicate empty string");
	cr_assert_str_eq(dup_ft, dup_c, "ft_strdup should match ft_strdup_in_C");
	cr_assert_str_eq(dup_ft, dup_libc, "ft_strdup should match libc strdup");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);
}

Test(ft_strdup, long_string) {
	char *src = "The quick brown fox jumps over the lazy dog. "
	            "This is a longer string to test memory allocation.";
	char *dup_ft = ft_strdup(src);
	char *dup_c = ft_strdup_in_C(src);
	char *dup_libc = strdup(src);

	cr_assert_not_null(dup_ft, "ft_strdup should allocate memory for long string");
	cr_assert_not_null(dup_c, "ft_strdup_in_C should allocate memory for long string");
	cr_assert_not_null(dup_libc, "libc strdup should allocate memory for long string");

	cr_assert_str_eq(dup_ft, dup_c, "ft_strdup should match ft_strdup_in_C");
	cr_assert_str_eq(dup_ft, dup_libc, "ft_strdup should match libc strdup");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);
}

Test(ft_strdup, special_characters) {
	char *src = "hello\nworld\t!!";
	char *dup_ft = ft_strdup(src);
	char *dup_c = ft_strdup_in_C(src);
	char *dup_libc = strdup(src);

	cr_assert_not_null(dup_ft, "ft_strdup should allocate memory");
	cr_assert_not_null(dup_c, "ft_strdup_in_C should allocate memory");
	cr_assert_not_null(dup_libc, "libc strdup should allocate memory");

	cr_assert_str_eq(dup_ft, dup_c, "ft_strdup should match ft_strdup_in_C");
	cr_assert_str_eq(dup_ft, dup_libc, "ft_strdup should match libc strdup");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);
}

Test(ft_strdup, single_character) {
	char *src = "X";
	char *dup_ft = ft_strdup(src);
	char *dup_c = ft_strdup_in_C(src);
	char *dup_libc = strdup(src);

	cr_assert_not_null(dup_ft, "ft_strdup should allocate memory");
	cr_assert_not_null(dup_c, "ft_strdup_in_C should allocate memory");
	cr_assert_not_null(dup_libc, "libc strdup should allocate memory");

	cr_assert_str_eq(dup_ft, "X", "ft_strdup should duplicate 'X'");
	cr_assert_str_eq(dup_ft, dup_c, "ft_strdup should match ft_strdup_in_C");
	cr_assert_str_eq(dup_ft, dup_libc, "ft_strdup should match libc strdup");

	free(dup_ft);
	free(dup_c);
	free(dup_libc);
}

Test(ft_strdup, different_addresses) {
	char *src = "testing";
	char *dup1 = ft_strdup(src);
	char *dup2 = ft_strdup(src);

	cr_assert_neq(dup1, dup2, "Multiple strdups should allocate different addresses");
	cr_assert_str_eq(dup1, dup2, "But contents should be equal");

	free(dup1);
	free(dup2);
}

// ============================================================================
// FT_WRITE TESTS
// ============================================================================

Test(ft_write, write_to_stdout) {
	char *msg = "Test ft_write to stdout";
	ssize_t ret_ft = ft_write(1, msg, strlen(msg));
	ssize_t ret_libc = write(1, msg, strlen(msg));

	cr_assert_eq(ret_ft, strlen(msg), "ft_write should write all bytes");
	cr_assert_eq(ret_ft, ret_libc, "ft_write should match libc write");
}

Test(ft_write, write_partial_data) {
	int fd = open("/tmp/test_write_ft.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cr_assert_neq(fd, -1, "Should open test file");

	char *msg = "hello world";
	ssize_t ret_ft = ft_write(fd, msg, 5);
	close(fd);

	fd = open("/tmp/test_write_ft.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ssize_t ret_libc = write(fd, msg, 5);
	close(fd);

	cr_assert_eq(ret_ft, 5, "ft_write should write 5 bytes");
	cr_assert_eq(ret_ft, ret_libc, "ft_write should match libc write");
}

Test(ft_write, write_zero_bytes) {
	ssize_t ret_ft = ft_write(1, "data", 0);
	ssize_t ret_libc = write(1, "data", 0);

	cr_assert_eq(ret_ft, 0, "ft_write should return 0 for 0 bytes");
	cr_assert_eq(ret_ft, ret_libc, "ft_write should match libc write");
}

Test(ft_write, write_to_file) {
	int fd = open("/tmp/test_write_ft.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cr_assert_neq(fd, -1, "Should open test file");

	char *msg = "Test write to file";
	ssize_t ret_ft = ft_write(fd, msg, strlen(msg));
	close(fd);

	fd = open("/tmp/test_write_ft.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ssize_t ret_libc = write(fd, msg, strlen(msg));
	close(fd);

	cr_assert_eq(ret_ft, (ssize_t)strlen(msg), "ft_write should write all bytes");
	cr_assert_eq(ret_ft, ret_libc, "ft_write should match libc write");
}

Test(ft_write, invalid_fd) {
	errno = 0;
	ssize_t ret_ft = ft_write(-1, "test", 4);
	int asm_errno = errno;

	errno = 0;
	ssize_t ret_libc = write(-1, "test", 4);
	int libc_errno = errno;

	cr_assert_eq(ret_ft, ret_libc, "ft_write should return same value as libc");
	cr_assert_eq(asm_errno, libc_errno, "ft_write should set same errno as libc");
}

Test(ft_write, closed_fd) {
	int fd = open("/tmp/test_write_ft.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int closed_fd = fd;
	close(fd);

	errno = 0;
	ssize_t ret_ft = ft_write(closed_fd, "test", 4);
	int asm_errno = errno;

	errno = 0;
	ssize_t ret_libc = write(closed_fd, "test", 4);
	int libc_errno = errno;

	cr_assert_eq(ret_ft, ret_libc, "ft_write should return same value as libc");
	cr_assert_eq(asm_errno, libc_errno, "ft_write should set same errno as libc");
}

Test(ft_write, multiple_writes) {
	int fd = open("/tmp/multi_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ssize_t ret1 = ft_write(fd, "a", 1);
	ssize_t ret2 = ft_write(fd, "b", 1);
	ssize_t ret3 = ft_write(fd, "c", 1);
	close(fd);

	cr_assert_eq(ret1, 1, "First write should return 1");
	cr_assert_eq(ret2, 1, "Second write should return 1");
	cr_assert_eq(ret3, 1, "Third write should return 1");

	unlink("/tmp/multi_write.txt");
}

Test(ft_write, stderr_write) {
	ssize_t ret_ft = ft_write(2, "error", 5);
	ssize_t ret_libc = write(2, "error", 5);

	cr_assert_eq(ret_ft, 5, "ft_write to stderr should write all bytes");
	cr_assert_eq(ret_ft, ret_libc, "ft_write to stderr should match libc");
}

// ============================================================================
// FT_READ TESTS
// ============================================================================

Test(ft_read, read_from_file) {
	// Setup test file
	int fd = open("/tmp/test_read_input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "Hello from file!\n", 17);
	write(fd, "Second line\n", 12);
	close(fd);

	char buf_ft[100], buf_libc[100];
	memset(buf_ft, 0, 100);
	memset(buf_libc, 0, 100);

	fd = open("/tmp/test_read_input.txt", O_RDONLY);
	ssize_t ret_ft = ft_read(fd, buf_ft, 50);
	close(fd);

	fd = open("/tmp/test_read_input.txt", O_RDONLY);
	ssize_t ret_libc = read(fd, buf_libc, 50);
	close(fd);

	cr_assert_eq(ret_ft, ret_libc, "ft_read should return same bytes as libc");
	cr_assert_arr_eq(buf_ft, buf_libc, 50, "ft_read buffer should match libc");

	unlink("/tmp/test_read_input.txt");
}

Test(ft_read, read_zero_bytes) {
	int fd = open("/tmp/test_read_input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "test", 4);
	close(fd);

	char buf_ft[100], buf_libc[100];
	memset(buf_ft, 0, 100);
	memset(buf_libc, 0, 100);

	fd = open("/tmp/test_read_input.txt", O_RDONLY);
	ssize_t ret_ft = ft_read(fd, buf_ft, 0);
	close(fd);

	fd = open("/tmp/test_read_input.txt", O_RDONLY);
	ssize_t ret_libc = read(fd, buf_libc, 0);
	close(fd);

	cr_assert_eq(ret_ft, ret_libc, "ft_read(0) should return same as libc");

	unlink("/tmp/test_read_input.txt");
}

Test(ft_read, invalid_fd) {
	char buf[100];
	errno = 0;
	ssize_t ret_ft = ft_read(-1, buf, 50);
	int asm_errno = errno;

	errno = 0;
	ssize_t ret_libc = read(-1, buf, 50);
	int libc_errno = errno;

	cr_assert_eq(ret_ft, ret_libc, "ft_read should return same value as libc");
	cr_assert_eq(asm_errno, libc_errno, "ft_read should set same errno as libc");
}

Test(ft_read, closed_fd) {
	int fd = open("/tmp/test_read_input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "test", 4);
	int closed_fd = fd;
	close(fd);

	char buf[100];
	errno = 0;
	ssize_t ret_ft = ft_read(closed_fd, buf, 50);
	int asm_errno = errno;

	errno = 0;
	ssize_t ret_libc = read(closed_fd, buf, 50);
	int libc_errno = errno;

	cr_assert_eq(ret_ft, ret_libc, "ft_read should return same value as libc");
	cr_assert_eq(asm_errno, libc_errno, "ft_read should set same errno as libc");

	unlink("/tmp/test_read_input.txt");
}

Test(ft_read, read_multiple_chunks) {
	int fd = open("/tmp/test_large.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	for (int i = 0; i < 100; i++)
		write(fd, "test", 4);
	close(fd);

	char buf1[50], buf2[50];
	memset(buf1, 0, 50);
	memset(buf2, 0, 50);

	fd = open("/tmp/test_large.txt", O_RDONLY);
	ssize_t ret1 = ft_read(fd, buf1, 50);
	ssize_t ret2 = ft_read(fd, buf2, 50);
	close(fd);

	cr_assert_eq(ret1, 50, "First read should return 50");
	cr_assert_eq(ret2, 50, "Second read should return 50");
	cr_assert_neq(buf1[0], buf2[0], "Sequential reads should get different data");

	unlink("/tmp/test_large.txt");
}

Test(ft_read, read_entire_file) {
	int fd = open("/tmp/test_read_all.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char *test_data = "Test file content";
	write(fd, test_data, strlen(test_data));
	close(fd);

	char buf_ft[100], buf_libc[100];
	memset(buf_ft, 0, 100);
	memset(buf_libc, 0, 100);

	fd = open("/tmp/test_read_all.txt", O_RDONLY);
	ssize_t ret_ft = ft_read(fd, buf_ft, sizeof(buf_ft));
	close(fd);

	fd = open("/tmp/test_read_all.txt", O_RDONLY);
	ssize_t ret_libc = read(fd, buf_libc, sizeof(buf_libc));
	close(fd);

	cr_assert_eq(ret_ft, ret_libc, "ft_read should return same bytes as libc");
	cr_assert_arr_eq(buf_ft, buf_libc, ret_ft, "ft_read buffer should match libc");

	unlink("/tmp/test_read_all.txt");
}

// ============================================================================
// FT_ATOI_BASE TESTS
// ============================================================================

Test(ft_atoi_base, binary_conversion) {
	int result_ft = ft_atoi_base("1010", "01");
	int result_c = ft_atoi_base_in_C("1010", "01");

	cr_assert_eq(result_ft, 10, "ft_atoi_base should convert '1010' binary to 10");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, decimal_conversion) {
	int result_ft = ft_atoi_base("123", "0123456789");
	int result_c = ft_atoi_base_in_C("123", "0123456789");

	cr_assert_eq(result_ft, 123, "ft_atoi_base should convert '123' decimal to 123");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, hexadecimal_conversion) {
	int result_ft = ft_atoi_base("FF", "0123456789ABCDEF");
	int result_c = ft_atoi_base_in_C("FF", "0123456789ABCDEF");

	cr_assert_eq(result_ft, 255, "ft_atoi_base should convert 'FF' hex to 255");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, hex_lowercase) {
	int result_ft = ft_atoi_base("ab12", "0123456789abcdef");
	int result_c = ft_atoi_base_in_C("ab12", "0123456789abcdef");

	cr_assert_eq(result_ft, result_c, "ft_atoi_base should handle lowercase hex");
}

Test(ft_atoi_base, octal_conversion) {
	int result_ft = ft_atoi_base("755", "01234567");
	int result_c = ft_atoi_base_in_C("755", "01234567");

	cr_assert_eq(result_ft, result_c, "ft_atoi_base should convert octal correctly");
	cr_assert_eq(result_ft, 493, "ft_atoi_base should convert '755' octal to 493");
}

Test(ft_atoi_base, custom_base_characters) {
	int result_ft = ft_atoi_base("BBA", "ABCDEFGHIJ");
	int result_c = ft_atoi_base_in_C("BBA", "ABCDEFGHIJ");

	cr_assert_eq(result_ft, result_c, "ft_atoi_base should work with custom character bases");
}

Test(ft_atoi_base, empty_string) {
	int result_ft = ft_atoi_base("", "0123456789");
	int result_c = ft_atoi_base_in_C("", "0123456789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for empty string");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, single_digit) {
	int result_ft = ft_atoi_base("5", "0123456789");
	int result_c = ft_atoi_base_in_C("5", "0123456789");

	cr_assert_eq(result_ft, 5, "ft_atoi_base should convert single digit '5'");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, leading_zeros) {
	int result_ft = ft_atoi_base("00123", "0123456789");
	int result_c = ft_atoi_base_in_C("00123", "0123456789");

	cr_assert_eq(result_ft, 123, "ft_atoi_base should handle leading zeros");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, large_number) {
	int result_ft = ft_atoi_base("999", "0123456789");
	int result_c = ft_atoi_base_in_C("999", "0123456789");

	cr_assert_eq(result_ft, 999, "ft_atoi_base should convert large number '999'");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_less_than_two) {
	int result_ft = ft_atoi_base("5", "0");
	int result_c = ft_atoi_base_in_C("5", "0");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for base < 2");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_with_whitespace) {
	int result_ft = ft_atoi_base("123", "0 23456789");
	int result_c = ft_atoi_base_in_C("123", "0 23456789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for base with whitespace");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_with_plus_sign) {
	int result_ft = ft_atoi_base("123", "+0123456789");
	int result_c = ft_atoi_base_in_C("123", "+0123456789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for base with '+'");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_with_minus_sign) {
	int result_ft = ft_atoi_base("123", "01234-56789");
	int result_c = ft_atoi_base_in_C("123", "01234-56789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for base with '-'");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_with_duplicate_characters) {
	int result_ft = ft_atoi_base("123", "01234567899");
	int result_c = ft_atoi_base_in_C("123", "01234567899");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for base with duplicates");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_of_two) {
	int result_ft = ft_atoi_base("11111111", "01");
	int result_c = ft_atoi_base_in_C("11111111", "01");

	cr_assert_eq(result_ft, 255, "ft_atoi_base should convert '11111111' binary to 255");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, special_characters_base) {
	int result_ft = ft_atoi_base("@#$", "@#$%&");
	int result_c = ft_atoi_base_in_C("@#$", "@#$%&");

	cr_assert_eq(result_ft, result_c, "ft_atoi_base should work with special character bases");
}

Test(ft_atoi_base, zero_result) {
	int result_ft = ft_atoi_base("0", "0123456789");
	int result_c = ft_atoi_base_in_C("0", "0123456789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for '0'");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, multiple_zeros) {
	int result_ft = ft_atoi_base("000", "0123456789");
	int result_c = ft_atoi_base_in_C("000", "0123456789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for '000'");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, base_16_mixed_case) {
	int result_ft = ft_atoi_base("aA2f", "0123456789abcdefABCDEF");
	int result_c = ft_atoi_base_in_C("aA2f", "0123456789abcdefABCDEF");

	cr_assert_eq(result_ft, result_c, "ft_atoi_base should handle mixed case in base");
}

Test(ft_atoi_base, invalid_characters) {
	int result_ft = ft_atoi_base("XYZ", "0123456789");
	int result_c = ft_atoi_base_in_C("XYZ", "0123456789");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should return 0 for invalid chars");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}

Test(ft_atoi_base, very_large_base) {
	int result_ft = ft_atoi_base("test", "abcdefghijklmnopqrstuvwxyz");
	int result_c = ft_atoi_base_in_C("test", "abcdefghijklmnopqrstuvwxyz");

	cr_assert_eq(result_ft, result_c, "ft_atoi_base should handle base 26");
}

Test(ft_atoi_base, single_char_in_string) {
	int result_ft = ft_atoi_base("A", "ABCDEFGHIJ");
	int result_c = ft_atoi_base_in_C("A", "ABCDEFGHIJ");

	cr_assert_eq(result_ft, 0, "ft_atoi_base should convert 'A' in custom base");
	cr_assert_eq(result_ft, result_c, "ft_atoi_base should match ft_atoi_base_in_C");
}
