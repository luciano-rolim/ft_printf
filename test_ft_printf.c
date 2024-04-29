/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeneghe <lmeneghe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:29:09 by lmeneghe          #+#    #+#             */
/*   Updated: 2024/04/29 14:56:33 by lmeneghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(void) 
{
    int len_ft, len_orig;
    int all_tests_passed = 1;

    // Test printing a simple string
    printf("1 - Simple string test:\n");
    len_ft = ft_printf("Simple string: Hello, world!\n");
    len_orig = printf("Simple string: Hello, world!\n");
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch in simple string length\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // Test printing characters, including non-printable ones
    printf("2 - Characters test:\n");
    len_ft = ft_printf("Characters: %c %c %c", 'A', '\n', 0x7F);
    len_orig = printf("Characters: %c %c %c", 'A', '\n', 0x7F);
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch in characters length\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // Test printing NULL string
	char *ptr1 = NULL;

    printf("3 - Null string test:\n");
    len_ft = ft_printf("NULL string: %s\n", NULL);
    len_orig = printf("NULL string: %s\n", ptr1);
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing NULL string\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // Test printing empty string
    printf("4 - Empty string test:\n");
    len_ft = ft_printf("Empty string: '%s'\n", "");
    len_orig = printf("Empty string: '%s'\n", "");
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing empty string\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // Test integer overflow
    printf("5 - Int max and int min test:\n");
    len_ft = ft_printf("Int max: %d, Int min: %d\n", INT_MAX, INT_MIN);
    len_orig = printf("Int max: %d, Int min: %d\n", INT_MAX, INT_MIN);
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch in integer overflow\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // Test with mixed types
    printf("6 - Mixed types test:\n");
    len_ft = ft_printf("Mixed: %s %d %c\n", "Number", 42, 'X');
    len_orig = printf("Mixed: %s %d %c\n", "Number", 42, 'X');
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch in mixed types\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // Extreme case: large strings
    printf("7 - Large string test:\n");
    char large_string[21];
    memset(large_string, 'a', 20);
    large_string[20] = '\0';
    len_ft = ft_printf("%s\n", large_string);
    len_orig = printf("%s\n", large_string);
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch with large string\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // 8 - Special Characters and Escape Sequences Test
    printf("8 - Special characters and escape sequences test:\n");
    len_ft = ft_printf("Special chars: %c %s %c\n", '\x7E', "\x48\x65\x6C\x6C\x6F\x21", '\n'); // '~' and "Hello!" and newline
    len_orig = printf("Special chars: %c %s %c\n", '\x7E', "\x48\x65\x6C\x6C\x6F\x21", '\n');
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch in special characters and escape sequences\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // 9 - Hexadecimal and Octal Codes in Strings Test
    printf("9 - Hexadecimal and octal codes in strings test:\n");
    len_ft = ft_printf("Hex and octal: \\x41 \\101\n"); // 'A' in hex and octal
    len_orig = printf("Hex and octal: \\x41 \\101\n");
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing strings with hex and octal codes\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // 10 - Non-printable Characters Test
    printf("10 - Non-printable characters test:\n");
    len_ft = ft_printf("Non-printable: %c %c %c\n", '\x01', '\x02', '\x03'); // non-printable control characters
    len_orig = printf("Non-printable: %c %c %c\n", '\x01', '\x02', '\x03');
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing non-printable characters\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // 11 - Printing "literal" escape sequences
    printf("11 - Printing \"literal\" escape sequences:\n");
    len_ft = ft_printf("Escape sequences: \\n \\t \\r \\b\n"); // newline, tab, carriage return, backspace
    len_orig = printf("Escape sequences: \\n \\t \\r \\b\n");
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing \"literal\" escape sequences\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // 12 - null terminated string test
    printf("12 - Null terminated string test:\n");
    len_ft = ft_printf("String: %s\n", "f\0");
    len_orig = printf("String: %s\n", "f\0");
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing null terminated strings\n");
        all_tests_passed = 0;
    }
    printf("\n");

    // 13 - null terminated string test (2)
    printf("13 - Null terminated string test:\n");
    len_ft = ft_printf("String: %s\n", "f\0a");
    len_orig = printf("String: %s\n", "f\0a");
    if (len_ft != len_orig) 
	{
        printf("KO: Mismatch when printing null terminated strings (2)\n");
        all_tests_passed = 0;
    }
    printf("\n");

	// 14 - Test for simple unsigned integer printing
	printf("14 - Simple unsigned integer test:\n");
	len_ft = ft_printf("unsigned: %u\n", 567890);
	len_orig = printf("unsigned: %u\n", 567890);
	if (len_ft != len_orig) {
		printf("KO: Mismatch when printing unsigned integer\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 15 - Test for simple unsigned integer printing (2)
	printf("15 - Underflow unsigned integer test:\n");
	len_ft = ft_printf("underflow unsigned: %u\n", -10);
	len_orig = printf("underflow unsigned: %u\n", -10);
	if (len_ft != len_orig) {
		printf("KO: Mismatch when printing underflow unsigned integer\n");
		all_tests_passed = 0;
	}
	printf("\n");

	unsigned int test = 4294967295;

	// 16 - Test for mixed types including unsigned integer
	printf("16 - Mixed types with unsigned integer test:\n");
	len_ft = ft_printf("mixed: %u %d %s %c\n", test, INT_MIN, "hello", 'A');
	len_orig = printf("mixed: %u %d %s %c\n", test, INT_MIN, "hello", 'A');
	if (len_ft != len_orig) {
		printf("KO: Mismatch in mixed types including unsigned integer\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 17 - Test consecutive percent signs
	printf("17 - Consecutive percent signs test:\n");
	len_ft = ft_printf("percent: %%%%%%\n");
	len_orig = printf("percent: %%%%%%\n");
	if (len_ft != len_orig) {
		printf("KO: Mismatch when printing consecutive percent signs\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 18 - Test percent sign at the start and end of string
	printf("18 - Percent sign at the start and end of string test:\n");
	len_ft = ft_printf("%% starting and ending with percent %%\n");
	len_orig = printf("%% starting and ending with percent %%\n");
	if (len_ft != len_orig) {
		printf("KO: Mismatch with percent sign at start and end\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 19 - Test unsigned integer with large numbers and wrap around
	printf("19 - Unsigned integer wrap around test:\n");
	len_ft = ft_printf("wrap around: %u\n", 0 - 1);
	len_orig = printf("wrap around: %u\n", 0 - 1);
	if (len_ft != len_orig) {
		printf("KO: Mismatch in unsigned integer wrap around\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 20 - Test for empty string and boundary condition unsigned integers
	printf("20 - Empty string and boundary condition unsigned integers test:\n");
	len_ft = ft_printf("empty string and max uint: '%s' %u\n", "", test);
	len_orig = printf("empty string and max uint: '%s' %u\n", "", test);
	if (len_ft != len_orig) {
		printf("KO: Mismatch with empty string and maximum unsigned integer\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 21 - Edge case for percent alone at the end
	printf("21 - Edge case percent alone at the end test:\n");
	len_ft = ft_printf("trailing percent: %%");
	printf("\n");
	len_orig = printf("trailing percent: %%");
	printf("\n");
	if (len_ft != len_orig) {
		printf("KO: Mismatch when percent is alone at the end\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 22 - Testing hexadecimal lower-case and upper-case
	printf("22 - Testing hexadecimal lower and upper case:\n");
	len_ft = ft_printf("Hex lower: %x, Hex upper: %X\n", 0x1a2b3c4d, 0x1a2b3c4d);
	len_orig = printf("Hex lower: %x, Hex upper: %X\n", 0x1a2b3c4d, 0x1a2b3c4d);
	if (len_ft != len_orig) {
		printf("KO: Mismatch in hexadecimal lower and upper case output\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 23 - Test hexadecimal edge cases (zero and UINT_MAX)
	printf("23 - Hexadecimal edge cases:\n");
	len_ft = ft_printf("Hex zero: %x, Hex UINT_MAX: %X\n", 0, UINT_MAX);
	len_orig = printf("Hex zero: %x, Hex UINT_MAX: %X\n", 0, UINT_MAX);
	if (len_ft != len_orig) {
		printf("KO: Mismatch in hexadecimal edge cases\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 24 - Test printing pointers
	printf("24 - Printing pointers:\n");
	char *ptr3;
	len_ft = ft_printf("Pointer address: %p\n", ptr3);
	len_orig = printf("Pointer address: %p\n", ptr3);
	if (len_ft != len_orig) {
		printf("KO: Mismatch in printing pointer addresses\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 25 - Mixing types including pointer, hex and unsigned
	printf("25 - Mixing types with pointer, hex and unsigned:\n");
	len_ft = ft_printf("Mixed types: %p %x %u\n", ptr3, 0xdeadbeef, 3702);
	len_orig = printf("Mixed types: %p %x %u\n", ptr3, 0xdeadbeef, 3702);
	if (len_ft != len_orig) {
		printf("KO: Mismatch when mixing pointer, hexadecimal and unsigned integer\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 26 - Multiple consecutive %x and %X
	printf("26 - Multiple consecutive hex specifiers:\n");
	len_ft = ft_printf("Consecutive hex: %x%X%x%X\n", 0xabc, 0x123, 0x456, 0x789);
	len_orig = printf("Consecutive hex: %x%X%x%X\n", 0xabc, 0x123, 0x456, 0x789);
	if (len_ft != len_orig) {
		printf("KO: Mismatch in consecutive hexadecimal specifiers\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 27 - Format specifiers at the start and end
	printf("27 - Format specifiers at the start and end of strings:\n");
	len_ft = ft_printf("%x Beginning and end %X\n", 0xabc, 0xdef);
	len_orig = printf("%x Beginning and end %X\n", 0xabc, 0xdef);
	if (len_ft != len_orig) {
		printf("KO: Mismatch with format specifiers at the start and end\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 28 - Edge case with very small and very large hex values
	printf("28 - Edge case with very small and very large hex values:\n");
	len_ft = ft_printf("Small hex: %x, large hex: %X\n", 0x1, 0xFFFFFFFE);
	len_orig = printf("Small hex: %x, large hex: %X\n", 0x1, 0xFFFFFFFE);
	if (len_ft != len_orig) {
		printf("KO: Mismatch with very small and large hex values\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 29 - Test printing null pointer address
	printf("29 - Printing pointers:\n");
	char *ptr4 = NULL;
	len_ft = ft_printf("Pointer address: %p\n", ptr4);
	len_orig = printf("Pointer address: %p\n", ptr4);
	if (len_ft != len_orig) {
		printf("KO: Mismatch in printing null pointer address\n");
		all_tests_passed = 0;
	}
	printf("\n");

	// 30 - Empty string just to sure
	printf("30 - Printing empty string just to be sure:\n");
	len_ft = ft_printf("");
	len_orig = printf("");
	if (len_ft != len_orig) {
		printf("KO: Mismatch in printing empty string\n");
		all_tests_passed = 0;
	}
	printf("\n");

    // Final result
    if (all_tests_passed) 
        printf("----------------\n OK - All ft_printf tests passed\n");
	else
        printf("----------------\n KO - One or more tests with error\n");

}
