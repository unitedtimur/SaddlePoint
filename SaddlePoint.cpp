/*
*
*Created by UnitedTimur
*
*/

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
        Min[i] = Matrix[i][0]; 
        for (int j = 1; j < m; j++){
            if (Matrix[i][j] < Min[i])
            {
                Min[i] = Matrix[i][j];
            }
        }
    }
    /*---Finding the maximum elements---*/
    for (int j = 0; j < m; j++){
        Max[j] = Matrix[0][j]; 
        for (int i = 1; i < n; i++){
            if (Matrix[i][j] > Max[j]){
                Max[j] = Matrix[i][j]; 
            }
        }
    }

    /*---Test Min and Max---*/
    int Propusk = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (Min[i] == Max[j]){ 
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


