#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10

int main()
{
    run();
	return 0;
}

int run(void)
{
    int number;
    printf("\n\nExamples [1..13]; 0 for exit\n");
    printf("Input number: ");
    if (scanf("%d", &number) != NULL)

    switch (number)
    {
    case 0:
        puts("Exit");
        exit(0);
    case 1:
        printf("\n");
        example1(); run();
    case 2:
        printf("\n");
        example2(); run();
    case 3:
        printf("\n");
        example3(); run();
    case 41:
        printf("\n");
        example4_1(); run();
    case 42:
        printf("\n");
        example4_2(); run();
    case 5:
        printf("\n");
        example5(); run();
    case 6:
        printf("\n");
        example6(); run();
    case 61:
        printf("\n");
        example6_1(); run();
    case 7:
        printf("\n");
        example7(); run();
    case 8:
        printf("\n");
        example8(); run();
    case 91:
        printf("\n");
        example9_1(); run();
    case 92:
        printf("\n");
        example9_2(); run();
    case 93:
        printf("\n");
        example9_3(); run();
    case 10:
        printf("\n");
        example10(); run();
    case 11:
        printf("\n");
        example11(); run();
    case 12:
        printf("\n");
        example12(); run();
    case 13:
        printf("\n");
        example13(); run();
    default:
        break;
    }
}

//удалить элемент из массива и сдвинуть влево
int example1(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr_size = sizeof(arr) / sizeof(arr[0]); //размер массива
    int arr_index;

    //выводим маассив
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nInput index of element of array you want to delete: ");
    scanf("%d", &arr_index);
    arr_index = abs(arr_index); //исключаем отрицательные значения индекса

    if (arr_index > arr_size)
        arr_index = arr_size - 1; //последний элемент

    //размер части массива, который стоит после удаляемого элемента
    int arr_size_to_move = sizeof(int) * (arr_size - arr_index - 1);
    // например, если удаляем 0й эл-т, то эта переменная = размер инта * (10 - 0 - 1)
    // = 4*9 = 36
    // размер изначального массива = 4 * 10 = 40

    //на место элемента, индекс которого вели, сдвигаем всю правую часть массива
    memcpy(&arr[arr_index], &arr[arr_index + 1], arr_size_to_move);

    //выводим маассив
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d  ", arr[i]);
    }
    //т.к. мы копируем "кусок памяти", то то, что было, не меняется, отсюда остается 10 в конце
    
    //(1) { 1 2 3 4 5 6 7 8 9 10 } - исходный массив
    // 
    //(2) { 1 [2] 3 4 5 6 7 8 9 10 } - ввели 1; arr[1] = 2
    // 
    //(3) { 1 [2] (3 4 5 6 7 8 9 10) } - (..) - кусок, который копируем
    // 
    //(4) { .. [] <- (..) .. }
    //         /\     \/
    //          \_____/
    // 
    //(5) { 1 (3 4 5 6 7 8 9 10) 10 } - вставили скопированное начиная с эл-та с индексом = 1
    // 
    //(6) { 1 3 4 5 6 7 8 9 10 10 }    - результат
}

//поменять местами 2 переменные
int example2(void)
{
    float a = 300.456;
    float b = 0.645;
    float temp;

    printf("a = %.3f \nb = %.3f\n ", a, b);

    //temp = a
    memcpy(&temp, &a, sizeof(float));
    //a = b
    memcpy(&a, &b, sizeof(float));
    //b = temp
    memcpy(&b, &temp, sizeof(float));

    printf("\na = %.3f \nb = %.3f", a, b);
}

//
int example3(void)
{
    char str[] = "abc def ... .";
    //...........[ a b c _ d e f _ . . .  _  . ]
    // ..........[ 0 1 2 3 4 5 6 7 8 9 10 11 12] 
    puts(str);

    memmove(str + 8, str + 4, 3);
    //...........[ a b c _ d e f _ |.| . .  _  . ]
    // ..........[ 0 1 2 3 4 5 6 7 |8| 9 10 11 12] - str+8
    // 
    //...........[ a b c _ |d| e f _ . . .  _  . ]
    // ..........[ 0 1 2 3 |4| 5 6 7 8 9 10 11 12] - str+4
    // 
    //...........[ a b c _ |d e f| _ . . .  _  . ]
    // ..........[ 0 1 2 3 |4 5 6| 7 8 9 10 11 12] - 3 (от str+4 до str+6) ; (4,5,6) = 3
    // 
    //...........[ a b c _ |d e f| _ |.| . . _  . ]
    // ..........[ 0 1 2 3 |4 5 6| 7 |8|9 10 11 12] - memmove(str+8, str+4, ?)
    //                       \/       /\ 
    //                        \_______/
    // 
    //...........[ a b c _ |d e f| _ |d e f | _  . ]
    // ..........[ 0 1 2 3 |4 5 6| 7 |8 9 10| 11 12] - memmove(str+8, str+4, 3)
    //                       \/         /\ 
    //                        \_________/
    //                         |d e f |
    //

    puts(str);
}

//копирование строки
int example4_1(void)
{
    char str1[128];
    char str2[128];

    scanf("%127s", str1); //записываем данные в str1
    printf("str1 = %s\n\n", str1);

    strcpy(str2, str1); //копируем str1 в str2

    printf("str2 = %s", str2);
}

example4_2(void)
{
    // то же, что 4_1, только результат записывается в еще одну строку
    // ...
    // str3 = strcpy(str2, str1);
    // ...
}

//копирование n символов строки
int example5(void)
{
    char str1[] = "Aloha, Hawaii";
    char str2[16];
    char str3[16];

    printf("str1 = %s\n\n", str1);

    strncpy(str2, str1, 5);     //копируем 5 символов str1, начиная с 0го, в str2
    str2[5] = '\0';
    strncpy(str3, str1 + 7, 7); //копируем 7 символов str1, начиная с 7го, в str2

    printf("str2 = %s\n", str2);
    printf("\nstr3 = %s", str3);
}

//конкатенация строк
// присоединение (приклеивание) одной строки к другой
int example6(void)
{
    char str1[14] = "123456"; //str1 должна быть минимум в два раза больше str2
    char str2[7] = "qwerty";

    strcat(str1, str2);

    puts(str1);
}

//strncat - присоединение n символов одной строки к другой
//задание: присоединение половинки второй строки к первой
int example6_1(void)
{
    char str1[20]; //str1 должна быть минимум в два раза больше str2
    char str2[10];

    scanf("%s", str1);
    scanf("%s", str2);

    strncat(str1, str2, strlen(str2) / 2);
    //strlen() - возвращает длину строки

    puts(str1);
}

//сравнение строк
//сортирует строки по алфавиту
int cmp(const void* a, const void* b) {
    return strncmp((char*)a, (char*)b, 3); // 3 - первые n букв, по которым происходит сортировка, т.е. например n = 2; МИ и МА отсортирует как МА и МИ
}

int example7(void)
{
    int i;
    /*char words[5][79] = {
        "Solar",
        "Obscurus",
        "Tempestus",
        "Ultima",
        "Pacificus"
    };*/

    char words[6][79] = {
        "B_Solar",
        "D_Obscurus",
        "C_Tempestus",
        "A_Ultima",
        "A_Altima",
        "E_Pacificus"
    };

    for (i = 0; i < 6; i++) {
        printf("%s\n", words[i]);
    }

    qsort(words, 6, sizeof(words[0]), cmp); // Исправленный вариант

    printf("\n");

    for (i = 0; i < 6; i++) {
        printf("%s\n", words[i]);
    }
}


//поиск - memchr()
//задание: найти конец строки ('\0')
int example8(void)
{
    char str[] = "Hello world!";
    char* ptr = NULL;
    char symbol = '\0';
    
    printf("string - %s\n\n", str);

    ptr = (char*)memchr(str, symbol, strlen(str)+1);
    //strlen(str)+1 - диапазон поиска вся строка

    if (ptr != NULL)
    {
        printf("first '%c' have this address - %p", symbol, ptr);
    }
    else
    {
        printf("symbol not found");
    }

    //memchr() возвращает указатель на адрес найденного элемента,
    //таким образом, длину строки можно найти таким образом:
    printf("\n\nptr = %d, str = %d", ptr, str);
    printf("\n\nlength of string (ptr-str) = %d", ptr - str);
    printf("\n\nlength of string (strlen()) = %d", strlen(str));
}

// strchr - поиск символа в строке
// как memchr только работает конкретно со строками, а не с блоками памяти
// задание: найти все гласные в строке
//1ый споособ - strchr()
int example9_1(void)
{
    char str[] = "So if you want to love me\n"
                 "Then darling don't refrain\n"
                 "Or I'll just end up walking\n"
                 "In the cold November rain\n";

    char vowels[] = "eyuioaEYUIOA";

    printf("\nstring: %s\n", str);
    
    printf("Vowels in string:\n");

    for (int i = 0; i < strlen(str); i++)
    {
        char* vowel = strchr(vowels, str[i]);
        if (vowel != NULL)
        {
            printf("[%d] = %c \n", i, str[i]);  
        }
    }
}

//2ой способ - strcspn()
int example9_2(void)
{
    char str[] = "So if you want to love me\n"
        "Then darling don't refrain\n"
        "Or I'll just end up walking\n"
        "In the cold November rain\n";

    char vowels[] = "eyuioaEYUIOA";

    printf("\nstring: %s\n", str);

    printf("Vowels in string:\n");

    for (int i = 0; i < strlen(str); i++)
    {
        if (strcspn(&str[i], vowels) == NULL)
        {
            printf("[%d] = %c\n", i, str[i]);
        }
    }
}

//3ий способ - strpbrk()
int example9_3(void)
{
    char str[] = "So if you want to love me\n"
        "Then darling don't refrain\n"
        "Or I'll just end up walking\n"
        "In the cold November rain\n";

    char vowels[] = "eyuioaEYUIOA";
    char* ptr = NULL;

    printf("\nstring: %s\n", str);

    printf("Vowels in string:\n");

    ptr = strpbrk(str, vowels);

    for (int i = 0; i < strlen(str); i++)
    {
        if (ptr)
        {
            printf("[%d] = %c\n", ptr-str, *ptr);
            ptr++;
            ptr = strpbrk(ptr, vowels);
        }
    }
}

//strrchr()
// 
//strspn(str1, str2) - возвращает длину участка строки str, который состоит только из символов строки str2
//задание: вывести число, которое встречается в строке
int example10(void)
{
    char str[] = "On 21st of May";
    char nums[] = "1234567890";

    int length = strcspn(str, nums);

    printf("\n%s\n", str);

    if (length > 0)
    {
        char number[10];

        strncpy(number, str + length, length);

        number[length-1] = '\0';
        
        printf("Number from string - %s", number);
    }
    else
    {
        puts("No numbers in string");
    }
}

//ctrstr()
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

//strtok(str1, str2) разбивает строку str1 на кусочки ("токены") ограниченные символами, входящими в строку str2
int example12(void)
{
    char str[] = "After working in India during the late 1970s and 1980s, "
                 "Shankar's profile in the West began to rise again in the mid-1990s "
                 "as his music found its way into club DJ sets, particularly in London.";
    
    char delim[] = " \t\n\,.-";
    char* p = strtok(str, delim); //разбили текст по словам
    
    //выводим текст по словам
    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, delim);
    }
}

//sprintf() - как printf() только записывает в строку
int example13(void)
{
    char str[16] = "Number is: ";
    int number = 5;

    sprintf(&str[11], "%d", number);
    puts(str);
}