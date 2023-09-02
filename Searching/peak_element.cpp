

//psuedo code

int findPeak(int arr[], int n)
{
	int l = 0;
	int r = n-1;
	int mid;

	while (l <= r) {
	
		// finding mid by binary right shifting.
		mid = (l + r) >> 1;
	
		// first case if mid is the answer
		if ((mid == 0 || arr[mid - 1] <= arr[mid])
			and (mid == n - 1 || arr[mid + 1] <= arr[mid]))
			break;
	
		// move the right pointer
		if (mid > 0 and arr[mid - 1] > arr[mid])
			r = mid - 1;
	
		// move the left pointer
		else
			l = mid + 1;
	}

	return mid;
}
