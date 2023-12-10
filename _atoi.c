/**
 * _atoi - convert a string to an integer.
 * @s: pointer to string to be converted.
 *
 * Return: converted integer value
 */
int _atoi(char *s)
{
    unsigned int num;
    int i, sign;

    sign = 1;
    num = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '-')
        {
            sign = sign * -1;
        }
        if (s[i] > '9' || s[i] < '0')
        {
            continue;
        }
        else
        {
            num = (num * 10) + (s[i] - '0');
            if (s[i + 1] == ' ')
            {
                break;
            }
        }
    }
    return (num * sign);
}