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

int t1(void) //удаление элемента из массива по индексу и сдвиг остатка массива влево 
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

int t2(void) //Функция меняет местами две переменные
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

    memcpy(tmp, a, size); //копирование из а в tmp и сколько выделить памяти
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}


int t3(void) //копирует участок строки и вставляет его
{
    char str[] = "memmove can be very useful......";
    puts(str);
    memmove(str + 20, str + 15, 11); // куда, откуда и сколько
    puts(str);
}


int t4(void) //Копирует одну строку в другую, вместе с нулевым символом
{
    char buffer[128];
    char* word = NULL;

    scanf("%127s", buffer);

    word = (char*)malloc(strlen(buffer) + 1); //+1 для нуль символа

    strcpy(word, buffer); //куда, откуда

    printf("%s\n", word);

    free(word);
}


int t5(void)//При копировании из строки в эту же строку части не должны пересекаться 
{
    char word[] = "Aloha, Hawaii";
    char aloha[20];
    char hawaii[20];

    printf("%s", word);

    strncpy(aloha, word, 5); //копируются только 5 первых букв
    aloha[5] = 0; //конец строки

    strncpy(hawaii, &word[7], 7); //7 первых начиная с элемента с индексом 7
    hawaii[7] = 0; //конец строки

    printf("\n%s\n%s\n", aloha, hawaii);

    //printf("\n%s, %s\n", aloha, hawaii);
}

//strcat(1ая строка, 2ая строка) -> приклеивает 2ую строку к концу 1ой, возвращает измененную 1ую.
//первый символ 2ой строки ставится на места нулевого (\0) первой

int t6(void)
{
    char a[80];
    char b[80];

    scanf("%s", a);
    scanf("%s", b);

    strncat(a, b, strlen(b) / 2); //Добавляет в конец строки a половину символов строки b

    printf("\n%s\n", a);
}

int cmp(const void* a, const void* b);

int cmp(const void* a, const void* b)
{
    return strncmp((char*)a, (char*)b, 3); //сравнение строк по первым трем символам
}

int t7(void)//сравнение строк
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

    qsort(words, 5, 80, cmp); //массив, кол-во строк, размер строк, возвращаемое значение функции cmp

    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", words[i]);
    }
}


int t8(void) //поиск \0 в строке
{
    char str[] = "Hello World!";
    char* ptr = NULL;

    printf("%s\n", str);

    ptr = (char*)memchr(str, '\0', 4000); //поиск \0 в str, возращает указатель на найд. эл.

    if (ptr != NULL)
    {
        printf("first zero byte address is %p, strlen = %d", ptr, ptr - str);
    }
    else
    {
        printf("no null byte in memory block");
    }
}


int t9(void) //найти положение всех гласных в строке
{
    char str[] = "So if you want to love me\n"
        "Then darling don't refrain\n"
        "Or I'll just end up walking\n"
        "In the cold November rain\n";
    char vowels[] = "aeiouy";
    int i = 0;
    while (str[i])
    {
        //strcspn начинает отсчет всегда с нуля

        i = i + strcspn(&str[i], vowels); //Возвращает адрес первого вхождения любой буквы из строки vowels в строке str. 

        printf("%d ", i);
        i++;
    }
}


int t10(void) //Вывод всех гласных в строке
{
    char str[] = "Cos' it's a bittersweet symphony this life...\n"
        "Trying to make ends meet, you're a slave to the money then you die.";
    char vowels[] = "aeiouy";
    char* p = NULL;

    p = strpbrk(str, vowels); //возвращает указатель на первый символ из строки str, который есть в строке vowels 

    while (p)
    {
        printf("%c ", *p);
        p++;
        p = strpbrk(p, vowels); //вызывается функция, чтобы найти следующую гласную в строке
    }
}


int t11(void) //вывести число, которое встречается в строке 
{
    char str[] = "on 21st of May";
    char nums[] = "0123456789";
    char number[10];

    //uintptr_t - целочисленный тип без знака, который может хранить указатель данных
    uintptr_t i;

    //Определяем, где начинаются цифры
    // size_t - используется для индексации массива и подсчета циклов 
    // целочисленный тип данных без знака
    size_t start = strcspn(str, nums); //Возвращает адрес первого вхождения любой буквы из строки nums в строке str 

    //Определяем, где они заканчиваются, относительно start 
    size_t end = strspn(&str[start], nums); //Возвращает длину куска строки str, начиная от начала, который состоит только из букв строки nums
    for (i = 0; i < end; i++)
    {
        printf("%c", str[start + i]);
    }
}

int t12(void) //Возвращает указатель на первое вхождение строки str2 (niece) в строку str1 (str)
{
    char str[] = "I'll drown my beliefs\n"
        "To have you be in peace\n"
        "I'll dress like your niece\n"
        "And wash your swollen feet\n";
    char niece[] = "niece";
    char* p = strstr(str, niece);

    printf("%s", p);
}


int t13(void) //Разбивает строку на токены
{
    char str[] = "After working in India during the late 1970s and 1980s, "
        "Shankar's profile in the West began to rise again in the mid-1990s "
        "as his music found its way into club DJ sets, particularly in London.";
    char delim[] = " \t\n\,.-";
    char* p = strtok(str, delim); //указатель на следующий токен

    while (p != NULL) //пока есть токены
    {
        printf("%s\n", p);
        p = strtok(NULL, delim);
    }
}