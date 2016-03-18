/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0)
		return NULL;
	int i, j = 0, p, temp;
	for (i = 0; i < len - 1; i++){
		if (Arr[i] > Arr[i + 1]){
			p = i + 1;
			break;
		}
	}
	if (i + 2 < len){
		for (j = i + 2; j < len; j++){
			if (Arr[j] <= Arr[p]){
				break;
			}
		}

	}
	if (j != 0 && (j != len) && i<len - 1){
		temp = Arr[i];
		Arr[i] = Arr[j];
		Arr[j] = temp;
	}
	else if (i<len - 1){
		temp = Arr[i];
		Arr[i] = Arr[i + 1];
		Arr[i + 1] = temp;
	}
	return NULL;
}