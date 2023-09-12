void intersection(int a[], int b[], int n, int m)
{
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] > b[j]) {
			j++;
		}
		else if (b[j] > a[i]) {
			i++;
		}
		else {

			// when both are equal
			cout << a[i] << " ";
			i++;
			j++;
		}
	}
}
