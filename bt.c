#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuan_hoa(char *s)
{
    int len = strlen(s);
    char result[81];
    int i = 0;
    int start = 1;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            if (i > 0 && result[i - 1] != ' ')
                result[i++] = ' ';
            start = 1;
        }
        else
        {
            if (start)
            {
                result[i++] = toupper(s[i]);
                start = 0;
            }
            else
            {
                result[i++] = tolower(s[i]);
            }
        }
    }

    if (i > 0 && result[i - 1] == ' ')
        i--;

    result[i] = '\0';
    strcpy(s, result);
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();

    while (t--)
    {
        char name[81];
        fgets(name, sizeof(name), stdin);

        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
            name[len - 1] = '\0';

        chuan_hoa(name);
        printf("%s\n", name);
    }
}
