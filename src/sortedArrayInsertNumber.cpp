/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i,pos;
	if (Arr == NULL || len <= 0) return NULL;
	int *newp = (int *)realloc(Arr, (len + 1)*sizeof(int));
	if (newp != NULL){
		Arr = newp;
	}
	else{
		return NULL;
	}
	len = len + 1;//updating array length to insert num in the array 

	if (num <= Arr[0]){//if num is <= first element then insert at first
		for (i = len; i > 0; i--){
			Arr[i] = Arr[i - 1];
		}
		Arr[0] = num;
	}

	else if (num >= Arr[len-2]){//if num is >=last element then insert at last
		Arr[len-1] = num;
	}
	else{//insert in between first and last elements

		for (i = 0; i <len - 2; i++){
			if (Arr[i] <= num&&Arr[i + 1] > num){
				pos = i + 1;
				break;
			}
		}
		for (i = len-1; i >pos; i--){
			Arr[i] = Arr[i - 1];
		}
		Arr[pos] = num;
	}
	return Arr;

	return NULL;
}