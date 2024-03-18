#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    tasks();
    return 0;
}

int tasks(void)
{
    int num;
    printf("\nnum: ");
    if (scanf("%d", &num) != NULL)

        switch (num)
        {
        case 0:
            exit(0);
        case 1:
            t1(); tasks();
        case 2:
            t2(); tasks();
        case 3:
            t3(); tasks();
        case 4:
            t4(); tasks();
        case 5:
            t5(); tasks();
        case 6:
            t6(); tasks();
        case 7:
            t7(); tasks();
        case 8:
            t8(); tasks();
        case 9:
            t9(); tasks();
        case 10:
            t10(); tasks();
        case 11:
            t11(); tasks();
        case 12:
            t12(); tasks();
        case 13:
            t13(); tasks();
        default:
            break;
        }
}

void swap(void* a, void* b, size_t size);

int t1(void) //�������� �������� �� ������� �� ������� � ����� ������� ������� ����� 
{
    int a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    unsigned index;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }

    printf("Enter index [0 .. 9]\n");
    scanf("%ud", &index);

    if (index < SIZE)
    {
        index = index;
    }
    else
    {
        index = SIZE - 1;
    }

    memcpy(&a[index], &a[index + 1], sizeof(int) * (SIZE - index - 1));

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

int t2(void) //������� ������ ������� ��� ����������
{
    float a = 300.456;
    float b = 0.645;

    printf("a = %.3f\nb = %.3f\n", a, b);

    swap(&a, &b, sizeof(float));

    printf("\n");
    printf("a = %.3f\nb = %.3f\n\n", a, b);
}

void swap(void* a, void* b, size_t size)
{
    void* tmp = malloc(size);

    memcpy(tmp, a, size); //����������� �� � � tmp � ������� �������� ������
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}


int t3(void) //�������� ������� ������ � ��������� ���
{
    char str[] = "memmove can be very useful......";
    puts(str);
    memmove(str + 20, str + 15, 11); // ����, ������ � �������
    puts(str);
}


int t4(void) //�������� ���� ������ � ������, ������ � ������� ��������
{
    char buffer[128];
    char* word = NULL;

    scanf("%127s", buffer);

    word = (char*)malloc(strlen(buffer) + 1); //+1 ��� ���� �������

    strcpy(word, buffer); //����, ������

    printf("%s\n", word);

    free(word);
}


int t5(void)//��� ����������� �� ������ � ��� �� ������ ����� �� ������ ������������ 
{
    char word[] = "Aloha, Hawaii";
    char aloha[20];
    char hawaii[20];

    printf("%s", word);

    strncpy(aloha, word, 5); //���������� ������ 5 ������ ����
    aloha[5] = 0; //����� ������

    strncpy(hawaii, &word[7], 7); //7 ������ ������� � �������� � �������� 7
    hawaii[7] = 0; //����� ������

    printf("\n%s\n%s\n", aloha, hawaii);

    //printf("\n%s, %s\n", aloha, hawaii);
}

//strcat(1�� ������, 2�� ������) -> ����������� 2�� ������ � ����� 1��, ���������� ���������� 1��.
//������ ������ 2�� ������ �������� �� ����� �������� (\0) ������

int t6(void)
{
    char a[80];
    char b[80];

    scanf("%s", a);
    scanf("%s", b);

    strncat(a, b, strlen(b) / 2); //��������� � ����� ������ a �������� �������� ������ b

    printf("\n%s\n", a);
}

int cmp(const void* a, const void* b);

int cmp(const void* a, const void* b)
{
    return strncmp((char*)a, (char*)b, 3); //��������� ����� �� ������ ���� ��������
}

int t7(void)//��������� �����
{
    int i;
    char words[5][79] =
    {
        "Solar",
        "Obscurus",
        "Tempestus",
        "Ultima",
        "Pacificus"
    };

    for (i = 0; i < 5; i++)
    {
        printf("%s\n", words[i]);
    }

    qsort(words, 5, 80, cmp); //������, ���-�� �����, ������ �����, ������������ �������� ������� cmp

    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", words[i]);
    }
}


int t8(void) //����� \0 � ������
{
    char str[] = "Hello World!";
    char* ptr = NULL;

    printf("%s\n", str);

    ptr = (char*)memchr(str, '\0', 4000); //����� \0 � str, ��������� ��������� �� ����. ��.

    if (ptr != NULL)
    {
        printf("first zero byte address is %p, strlen = %d", ptr, ptr - str);
    }
    else
    {
        printf("no null byte in memory block");
    }
}


int t9(void) //����� ��������� ���� ������� � ������
{
    char str[] = "So if you want to love me\n"
        "Then darling don't refrain\n"
        "Or I'll just end up walking\n"
        "In the cold November rain\n";
    char vowels[] = "aeiouy";
    int i = 0;
    while (str[i])
    {
        //strcspn �������� ������ ������ � ����

        i = i + strcspn(&str[i], vowels); //���������� ����� ������� ��������� ����� ����� �� ������ vowels � ������ str. 

        printf("%d ", i);
        i++;
    }
}


int t10(void) //����� ���� ������� � ������
{
    char str[] = "Cos' it's a bittersweet symphony this life...\n"
        "Trying to make ends meet, you're a slave to the money then you die.";
    char vowels[] = "aeiouy";
    char* p = NULL;

    p = strpbrk(str, vowels); //���������� ��������� �� ������ ������ �� ������ str, ������� ���� � ������ vowels 

    while (p)
    {
        printf("%c ", *p);
        p++;
        p = strpbrk(p, vowels); //���������� �������, ����� ����� ��������� ������� � ������
    }
}


int t11(void) //������� �����, ������� ����������� � ������ 
{
    char str[] = "on 21st of May";
    char nums[] = "0123456789";
    char number[10];

    //uintptr_t - ������������� ��� ��� �����, ������� ����� ������� ��������� ������
    uintptr_t i;

    //����������, ��� ���������� �����
    // size_t - ������������ ��� ���������� ������� � �������� ������ 
    // ������������� ��� ������ ��� �����
    size_t start = strcspn(str, nums); //���������� ����� ������� ��������� ����� ����� �� ������ nums � ������ str 

    //����������, ��� ��� �������������, ������������ start 
    size_t end = strspn(&str[start], nums); //���������� ����� ����� ������ str, ������� �� ������, ������� ������� ������ �� ���� ������ nums
    for (i = 0; i < end; i++)
    {
        printf("%c", str[start + i]);
    }
}

int t12(void) //���������� ��������� �� ������ ��������� ������ str2 (niece) � ������ str1 (str)
{
    char str[] = "I'll drown my beliefs\n"
        "To have you be in peace\n"
        "I'll dress like your niece\n"
        "And wash your swollen feet\n";
    char niece[] = "niece";
    char* p = strstr(str, niece);

    printf("%s", p);
}


int t13(void) //��������� ������ �� ������
{
    char str[] = "After working in India during the late 1970s and 1980s, "
        "Shankar's profile in the West began to rise again in the mid-1990s "
        "as his music found its way into club DJ sets, particularly in London.";
    char delim[] = " \t\n\,.-";
    char* p = strtok(str, delim); //��������� �� ��������� �����

    while (p != NULL) //���� ���� ������
    {
        printf("%s\n", p);
        p = strtok(NULL, delim);
    }
}