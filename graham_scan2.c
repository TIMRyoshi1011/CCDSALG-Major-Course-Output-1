void merge(int A[], int left, int mid, int right) 
{
	
    int i, j, k; 

    
    int lSize = mid - left + 1;
    int rSize = right - mid;

    int L[lSize];
    int R[rSize];

    for (i = 0; i < lSize; i++) 
	{
        L[i] = A[left + i];
    }
 
    for (j = 0; j < rSize; j++) 
	{
        R[j] = A[mid + 1 + j];
    }

    i = 0;          
    j = 0;          
    k = left;   

    while (i < lSize && j < rSize) 
	{
        if (L[i] <= R[j]) 
		{
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++; 
    }

    while (i < lSize) 
	{
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < rSize) 
	{
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int left, int right) 
{
    
    if (left >= right) 
	{
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(A, left, mid);

    mergeSort(A, mid + 1, right);

    merge(A, left, mid, right);
}
