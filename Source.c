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
    printf("Input number : ");
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
    
    //(1) { 1 2 3 4 5 6 7 8 9 10} - исходный массив
    //(2) { 1 [2] 3 4 5 6 7 8 9 10 } - ввели 1
    //(3) { 1 [2] (3 4 5 6 7 8 9 10) } - (..) - кусок, который копируем
    //(4) { .. [] <- (..) .. }
    //(5) { 1 (3 4 5 6 7 8 9 10) 10 } - вставили скопированное начиная с эл-та с индексом = 1
    //(6) { 1 3 4 5 6 7 8 9 10 10 } - результат
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


int example3(void)
{
    char str[] = "abc def "
}

int example4_1(void)
{

}

example4_2(void)
{

}

int example5(void)
{
}

int example6(void)
{

}

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