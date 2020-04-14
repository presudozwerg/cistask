/* 1) Это, конечно же, не работает, потому что времени мне не хватило.
   
   2) Сделал так, что при достижении мин или макс одним из игроков
      засчитывается победа.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int det(double **T, int N)
{
  int det__;
  int sub_j, s;
  int **subT;    
  switch (N)
  {
  	case 1:
    		return T[0][0];
  	case 2:
    		return T[0][0] * T[1][1] - T[0][1] * T[1][0];
  	default: 
    		subT = new int*[N-1];
    		det__ = 0;
    		s = 1;
    		for (int i = 0; i < N; i++)
    		{
      			sub_j = 0;
      			for (int j = 0; j < N; j++)
        		if (i != j)
          			subT[sub_j++] = T[j] + 1; 

      			det__ = det__ + s * T[i][0] * det(subT, N-1);
      			s = -s;
    		};
    	delete[] subT;
    	return det__;
  	};
};

void printmatr(int **M, int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
}

int mindet()
int maxdet() 
/* Тут либо перебрать, но это слишком долго (О(n!))
   либо по определению через перестановки, но не понятно как,
   может быть, жадный алгоритм [ не успеваю ] */

void botstep(int **T, int n)
{
	int i1, i2, j1, j2, comm;
	
	i1 = random(n);
	i2 = random(n);
	j1 = i1 + random(n - i1);
	j2 = i2 + j1 - i1;

	comm = random(2);
	if (comm == 0)
		mainrotate(T, i1, i2, j1, j2);
	else
		subrotate(T, i1, i2, j1, j2);
}

void gamerstep(int **T, int n)
{
	int i1, i2, j1, j2;
	printf("\n Введите крайний левый и правый элементы подматрицы, которую повернуть: ")
	scanf("%d %d %d %d", &i1, &i2, &j1, &j2);
	char comm[20];
	printf("\n Команда: ");
	gets(comm);
	if (comm == "mainrotate")
		mainrotate(T, i1, i2, j1, j2);
	else if (comm == "subrotate")
		subrotate(T, i1, i2, j1, j2);
	else 
		printf("\n ERROR \n");
}

void mainrotate(int **T, int i1, int i2, int j1, int j2)
{
	int size = j2 - i2;
	int (*arrPtr)[size] = T;
  	int i, j;
 
        for (i = i1; i < size; i++) {
		for (j = j1; j < size; j++)
			T[j][i] = arrPtr[i][j];
	}
}

void subrotate(int **T, int i1, int i2, int j1, int j2)
{
	int size = j2 - i2;
	int (*arrPtr)[size] = T;
	int i, j;

	for (i = i2; i >= i1; i--)
		for (j = j2; j >= j1; j--)
			T[j][i] = arrPtr[i][j];
}

int main()
{
	int **T;
	int n;
	printf("Правила: команда mainrotate(i1,i2,j1,j2) поворачивает вокруг главной диагонали\n
	команда subrotate(i1,i2,j1,j2) вокруг побочной диагонали")
	printf("Размер матрицы: \n")
	scanf("%d", &n);
	T = (int**)malloc(n*n*sizeof(int));
	printf("Написать матрицу: \n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	int det, dmin, dmax;
	dmin = detmin(T, n);
	dmax = detmax(T, n);
	char ans;
	printf("Каким хотите начать? Напишите 1 или 2:  ")ж
	scanf("%c", &ans);
	if (ans == 1)
		i = 1;
	else
		i = 0; /* ходит сначала бот */

	while ((det != detmin) || (det != detmax)) /* ход игры */
	{
		if (i % 2 == 0)
			botstep(T, n);
		else
			gamerstep(T, n);
		det = det(T, n);
		printmatr(T, n);
		i++;
	}

	if (i % 2 == 0)
		printf("Победил игрок");
	else 
		printf("Победил бот");
	free(T);
}
