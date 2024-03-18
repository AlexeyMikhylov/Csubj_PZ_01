#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    run();
	return 0;
}

int run(void)
{
    int number;
    printf("\nInput number: \n");
    if (scanf("%d", &number) != NULL)

    switch (number)
    {
    case 0:
        puts("Exit");
        exit(0);
    case 1:
        example1(); run();
    case 2:
        example2(); run();
    case 3:
        example3(); run();
    case 41:
        example4_1(); run();
    case 42:
        example4_2(); run();
    case 5:
        example5(); run();
    case 6:
        example6(); run();
    case 7:
        example7(); run();
    case 8:
        example8(); run();
    case 9:
        example9(); run();
    case 10:
        example10(); run();
    case 11:
        example11(); run();
    case 12:
        example12(); run();
    case 13:
        example13(); run();
    default:
        break;
    }
}

void swap(void* a, void* b, size_t size);

int example1(void)
{
    float a = 300.456;
    float b = 0.645;

    printf("a = %.3f\nb = %.3f\n", a, b);

    swap(&a, &b, sizeof(float));

    printf("\n");
    printf("a = %.3f\nb = %.3f\n\n", a, b);
}

// функция меняет местами две переменные
// memcpy(куда, откуда, сколько памяти);
void swap(void* a, void* b, size_t size)
{
    void* tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}

//удаляем элемент из массива по индексу и сдвигаем остаток влево
int example2(void)
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

//копируем участок строки и вставляем его 
int example3(void)
{
    char str[] = "memmove can be very useful......";
    puts(str);
    memmove(str + 20, str + 15, 11); //'very'
    puts(str);
}

//копирование одной строки в другую c помощью strcpy(куда, откуда)
int example4_1(void)
{
    char buffer[128];
    char* word = NULL;

    scanf("%127s", buffer);

    word = (char*)malloc(strlen(buffer) + 1);

    strcpy(word, buffer);

    printf("%s\n", word);

    free(word);
}

example4_2(void)
{
    char buffer[128];
    char* word = NULL;
    char* other = NULL;
    
    scanf("%127s", buffer);
    
    word = (char*)malloc(strlen(buffer) + 1);
    
    other = strcpy(word, buffer);
    
    printf("%s\n", other);

    free(other);
}

//strncpy(куда, откуда, сколько)
//при копировании из строки в эту же строку, не должно быть пересечения
int example5(void)
{
    char word[] = "Aloha, Hawaii";
    char aloha[20];
    char hawaii[20];

    printf("%s", word);

    strncpy(aloha, word, 5); //5 первых букв
    aloha[5] = 0; //конец строки

    strncpy(hawaii, &word[7], 7); //7 первых начиная с элемента (буквы) с индексом 7
    hawaii[7] = 0; //конец строки

    printf("\n%s\n%s\n", aloha, hawaii);
    
    printf("\n%s, %s\n", aloha, hawaii);
}

//конкатенация (склеивание) строк
//strcat(1ая строка, 2ая строка) -> приклеивает 2ую строку к концу 1ой, возвращает измененную 1ую.
//первый символ 2ой строки ставится на места нулевого (\0) первой
//
//strncat(1ая, 2ая, сколько символов)
int example6(void)
{
    char a[80];
    char b[80];

    scanf("%s", a);
    scanf("%s", b);
    
    strncat(a, b, strlen(b) / 2); //приклеивает половину второй строчки
    
    printf("\n%s\n", a);
}

//сравнение строк
//strcmp(1ая, 2ая) -> 0 - строки равны; 1 = 1ая больше; -1 = вторая больше;
//qsort() - функция сортировки (из <stdlib.h>)

int cmp(const void* a, const void* b);

//сортировка строк по первым трем символам
int cmp(const void* a, const void* b)
{
    return strncmp((char*)a, (char*)b, 3);
}

int example7(void)
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

    qsort(words, 5, 80, cmp); //words - массив, 5 - строк, 80 - размер строк, cmp - возвращаемое значение функции cmp

    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", words[i]);
    }
}


//поиск
//memchr()
int example8(void)
{
    char str[] = "Hello World!";
    char* ptr = NULL;

    printf("%s\n", str);

    ptr = (char*)memchr(str, 'H', 4000);

    if (ptr != NULL)
    {
        printf("first zero byte address is %p, strlen = %d", ptr, ptr - str);
    }
    else
    {
        printf("no null byte in memory block");
    }
}

//
int example9(void)
{
    char str[] = "So if you want to love me\n"
        "Then darling don't refrain\n"
        "Or I'll just end up walking\n"
        "In the cold November rain\n";
    char vowels[] = "aeiouy";
    
    int i = 0;
    while (str[i])
    {
        //printf("\n%d\n", i); printf("%d\n\n", strcspn(&str[i], vowels));
        //strcspn начинает отсчет всегда с нуля

        i = i + strcspn(&str[i], vowels);

        printf("%d ", i);
        i++;
    }
}

//
int example10(void)
{
    char str[] = "Cos' it's a bittersweet symphony this life...\n"
        "Trying to make ends meet, you're a slave to the money then you die.";
    char vowels[] = "aeiouy";
    char* p = NULL;

    p = strpbrk(str, vowels);

    while (p)
    {
        printf("%c ", *p);
        p++;
        p = strpbrk(p, vowels);
    }
}

//
int example11(void)
{
    char str[] = "I'll drown my beliefs\n"
        "To have you be in peace\n"
        "I'll dress like your niece\n"
        "And wash your swollen feet\n";
    char niece[] = "niece";
    char* p = strstr(str, niece);

    printf("%s", p);
}

//
int example12(void)
{
    char str[] = "on 21st of May";
    char nums[] = "0123456789";
    char number[10];

    /* uintptr_t - целочисленный тип без знака, который может хранить указатель данных */
    uintptr_t i;

    //Определяем, где начинаются цифры
    /* size_t - используется для индексации массива и подсчета циклов */
    // целочисленный тип данных без знака
    size_t start = strcspn(str, nums);

    /* Определяем, где они заканчиваются, относительно start */
    size_t end = strspn(&str[start], nums);
    for (i = 0; i < end; i++)
    {
        printf("%c", str[start + i]);
    }
}

//
int example13(void)
{
    char str[] = "After working in India during the late 1970s and 1980s, "
        "Shankar's profile in the West began to rise again in the mid-1990s "
        "as his music found its way into club DJ sets, particularly in London.";
    char delim[] = " \t\n\,.-";
    char* p = strtok(str, delim);

    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, delim);
    }
}