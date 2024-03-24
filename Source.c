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
    case 9:
        printf("\n");
        example9(); run();
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
    //...........[ a b c _ |d e f| _ |d e f | _  . ]
    // ..........[ 0 1 2 3 |4 5 6| 7 |8 9 10| 11 12] - memmove()

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
int example7(void)
{

}


//поиск
//memchr()
int example8(void)
{

}

//
int example9(void)
{

}

//
int example10(void)
{

}

//
int example11(void)
{

}

//
int example12(void)
{

}

//
int example13(void)
{

}