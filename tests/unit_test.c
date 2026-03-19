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

Test(ft_strlen, benchmark) {
	char *str = "The quick brown fox jumps over the lazy dog";
	for (int i = 0; i < 10000; i++) {
		ft_strlen(str);
	}
	cr_assert(1, "Benchmark completed");
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

Test(ft_strcmp, benchmark) {
	char *s1 = "The quick brown fox";
	char *s2 = "The quick brown fox";
	for (int i = 0; i < 10000; i++) {
		ft_strcmp(s1, s2);
	}
	cr_assert(1, "Benchmark completed");
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

Test(ft_strcpy, benchmark) {
	char buf[100];
	char *src = "The quick brown fox jumps over the lazy dog";
	for (int i = 0; i < 5000; i++) {
		ft_strcpy(buf, src);
	}
	cr_assert(1, "Benchmark completed");
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

Test(ft_strdup, benchmark) {
	char *src = "The quick brown fox jumps over the lazy dog";
	for (int i = 0; i < 1000; i++) {
		char *dup = ft_strdup(src);
		free(dup);
	}
	cr_assert(1, "Benchmark completed");
}

// ============================================================================
// FT_WRITE TESTS
// ============================================================================

Test(ft_write, write_to_stdout, .disabled = 1) {
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

Test(ft_write, benchmark) {
	int fd = open("/tmp/test_write_ft.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char *msg = "The quick brown fox";
	for (int i = 0; i < 1000; i++) {
		ft_write(fd, msg, strlen(msg));
	}
	close(fd);
	cr_assert(1, "Benchmark completed");
	unlink("/tmp/test_write_ft.txt");
}

// ============================================================================
// FT_READ TESTS
// ============================================================================

Test(ft_read, read_from_file_setup) {
	int fd = open("/tmp/test_read_input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cr_assert_neq(fd, -1, "Should create test file");
	write(fd, "Hello from file!\n", 17);
	write(fd, "Second line\n", 12);
	close(fd);
}

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

Test(ft_read, benchmark) {
	int fd = open("/tmp/test_read_input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char *content = "The quick brown fox jumps over the lazy dog";
	for (int i = 0; i < 100; i++) {
		write(fd, content, strlen(content));
	}
	close(fd);

	char buf[4096];
	for (int i = 0; i < 1000; i++) {
		fd = open("/tmp/test_read_input.txt", O_RDONLY);
		ft_read(fd, buf, sizeof(buf));
		close(fd);
	}

	unlink("/tmp/test_read_input.txt");
	cr_assert(1, "Benchmark completed");
}
