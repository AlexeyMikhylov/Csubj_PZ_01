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

//удалить элемент из массива и сдвинуть влево
int example1(void)
{

}

int example2(void)
{

}


int example3(void)
{

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