int max(int a, int b){
    if( a > b ){
        return a;
    }
    else return b;
}
int min(int a, int b){
    if( a < b ){
        return a;
    }
    else return b;
}
int find_left_max(int arr[], int n, int index){
	int maximum = 0;
	for( int i = 0; i <= index; i++){
		maximum = max(maximum, arr[i]);
	}
    return maximum;
}
int find_right_max(int arr[], int n, int index){
	int maximum = 0;
	for( int i = n - 1; i >= index; i--){
		maximum = max(maximum, arr[i]);
	}
    return maximum;
}
/* 
arr[]: 
n: Size of the array
*/
int trap(int* height, int heightSize){
	int total_water = 0;
	// We will not have any water in the first and last building, so we ignore the first and last index
	for( int i = 1; i < heightSize - 1; i++){
		int left_max = find_left_max(height, heightSize, i);
		int right_max = find_right_max(height, heightSize, i);
		total_water = total_water + ( min(left_max, right_max) - height[i] );
	}
	return total_water;
}



