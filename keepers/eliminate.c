#include "gsudoku.h"//<stdlib.h>
#include <stdio.h>

int		***eliminate(int ***cube)
{
	printf("inside elim\n");
	int flag;
	int i;
	int j;
	int k;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("On space %d,%d value: %d\n", i, j, cube[i][j][0]);
			if (cube[i][j][0])
			{
				printf("continue on space %d,%d value: %d\n\n", i, j, cube[i][j][0]);
				j++;
				continue;
			}
			k = 1;
			flag = 0;
			printf("flag is %d, k is %d\n", flag, k);
			while (k < 10)
			{
				printf("inside k for %d,%d value cube(i,j,k): %d \n", i, j, cube[i][j][k]);	
				if (!cube[i][j][k] && flag == 0)
				{
					flag = k;
					printf("flag set to %d\n", k);
				}
				else if (cube[i][j][k])
					;//printf("skip has value %d\n", cube[i][j][k]);
				else if (!cube[i][j][k])
				{
					flag =  -1;
					printf("flag set to:%d\n", flag);
				}
				printf("value cube after loop (i,j,k):%d\n\n", cube[i][j][k]);
				k++;
			}
			if (flag > 0)
			{
				cube[i][j][0] = flag;
				printf("flag set, space %d,%d is:%d\n", i, j, cube[i][j][0]);
			}
			printf("cube[i][j][0] is:%d\n\n", cube[i][j][k]);
			j++;
			break;
		}
		i++;
		break;
	}
	return (cube);
}
/*
[nbr,1,2,3,4,5,6,7,8,9]
[nbr,1,0,0,0,0,1,0,0,1]
*/








