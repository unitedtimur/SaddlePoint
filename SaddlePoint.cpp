#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(){
    int n, m;
    printf("Enter the size of Matrix, please: ");
    scanf("%d%d", &n, &m);

    int** Matrix = new int*[n];
    int* Min = new int [n];
    int* Max = new int [m];


    for (int i = 0; i < n; i++)
        Matrix[i] = new int [m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            Matrix[i][j] = rand()%10;
            //scanf("%d", &Matrix[i][j]);
        }
    }

    printf("\nOur Matrix.\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%2d", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    /*-----Finding the saddle point-----*/
    /*------------xD--------------------*/
    /*-----------------xD---------------*/
    /*----------------------xD----------*/

    /*---Finding the minimal elements---*/
    for (int i = 0; i < n; i++){
        Min[i] = Matrix[i][0]; //Каждый элемент массива равен 999999 Максимальное значение INT_MAX
        for (int j = 1; j < m; j++){
            if (Matrix[i][j] < Min[i])//Если элемент матрицы меньше Min, то в Min записываем знач этого элемента
            {
                Min[i] = Matrix[i][j]; //На место элемента в массиве Min по i записываю найденный элемент матрицы
            }
        }
    }
    /*---Finding the maximum elements---*/
    for (int j = 0; j < m; j++){
        Max[j] = Matrix[0][j]; //Каждый элемент массива равен -999999 Минимальное значение INT_MIN
        for (int i = 1; i < n; i++){
            if (Matrix[i][j] > Max[j]){ //Если элемент матрицы большее Max, то в Max записываем знач этого элемента
                Max[j] = Matrix[i][j]; //На место элемента в массиве Max по i записываю найденный элемент матрицы
            }
        }
    }

    /*---Test Min and Max---*/
    int Propusk = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (Min[i] == Max[j]){ //Если i-й элемент Минимума и Максимума совпадает, то вы водим индекс, этого элемента.
                printf("Index saddle point === [%d][%d]\n", i+1,j+1);
                Propusk++;
            }
        }
    }

    if (Propusk == 0) printf("Saddle point not found.");

    /*---Remove memory---*/
    for (int i = 0; i < n; i++){
        delete[] Matrix[i];
    }
    delete[] Min;
    delete[] Max;
	//byUnitedTimur
}


