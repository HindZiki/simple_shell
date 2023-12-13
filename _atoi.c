#include "shell.h"

/**
 * Code by – Susan Gicheru , Hind Ziki.
 * interactive - return true if shell is interactives mode.
 * @info: struct addresse.
 *
 * Return: 1 if interactives mode, zero otherwise.
 */
int interactive(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if characters is a delimeters.
 * @c: the char to checks.
 * @delim: the delimeter strings.
 * Return: 1 if true, zero if false.
 */
int is_delim(char c, char *delim)
{
        while (*delim)
                if (*delim++ == c)
                        return (1);
        return (0);
}

/**
 * Code by – Susan Gicheru , Hind Ziki.
 * _isalpha - check for alphabetic characters.
 * @c: The characters to inputs.
 * Return: 1 if c is alphabetic, zero otherwise
 */

int _isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 * Code by – Susan Gicheru , Hind Ziki.
 * _atoi - convert a string to an integers.
 * @s: the strings to be converted.
 * Return: 0 if no number in strings, converted numbers otherwise.
 */

int _atoi(char *s)
{
        int i, sign = 1, flag = 0, output;
        unsigned int result = 0;

        for (i = 0; s[i] != '\0' && flag != 2; i++)
        {
                if (s[i] == '-')
                        sign *= -1;

                if (s[i] >= '0' && s[i] <= '9')
                {
                        flag = 1;
                        result *= 10;
                        result += (s[i] - '0');
                }
                else if (flag == 1)
                        flag = 2;
        }

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}

