#include <cstdlib>
#include <iostream>
using namespace std;

//lab2

// Initializes the array for testing
void populateTest(int * &array)
{
    array = new int[10];
    array[0] = 31;
    array[1] = -41;
    array[2] = 59;
    array[3] = 26;
    array[4] = -53;
    array[5] = 58;
    array[6] = 97;
    array[7] = -93;
    array[8] = -23;
    array[9] = 87;
}

void populate(int * &array, int size)
{
    srand(0);
    array = new int[size];
    
    for(int i = 0; i < size ; i++)
    {
        //Generate values between -5 * size and 5 * size
        array[i] = rand() % (size * 10 + 1) - size * 5;
    }
}

//lab9

void sort(int *seq, int size)
{
    if (size == 0 || size == 1) {
        return;
    }
    
    int smallest = seq[0];
    int a = 0;
    
    for (int i = 0; i < size; i++){
        if (seq[i] < smallest){
            smallest = seq[i];
            a = i;
        }
    }
    
    seq[a] = seq[0];
    seq[0] = smallest;
    
    sort(seq+1, size-1);
}

void print(int * array, int size)
{
    for(int i = 0; i < size; i++)
        cout << "Array[" << i << "]= " << array[i] << endl;
}

int binarySearch(int*a, int left, int right, int x)
{
    if (right >= left){ 
        int mid = left + (right - left) / 2; 
  
        if (a[mid] == x){ 
            return mid; 
        }
        
        if (a[mid] > x){
            return binarySearch(a, left, mid - 1, x); 
        }
  
        return binarySearch(a, mid + 1, right, x); 
    } 
    return -1; 
}

int linearSearch(int*a, int left, int right, int x)
{
    if (right < left){
        return -1;
    }
    
    if (a[left] == x){
        return left; 
    }
    
    if (a[right] == x){
        return right; 
    }
    
    return linearSearch(a, left + 1,  right - 1, x);
}

int subseqSum(int prefixToaj, int aj) //SS function used in Lab02 iterative MSS
{
    int sum = 0;
    sum = prefixToaj+aj;
    
    return sum;
}

int mss_2(int * seqArray, int size) //Lab02 MSS
{
   int sum_max = seqArray[0];
    
    for (int a = 0; a < size; a++){
        int prevSum= 0;
        
        for (int b = a; b < size; b++){
            int sum_current = subseqSum(prevSum, seqArray[b]);
            
            prevSum = sum_current;
            
            if (prevSum > sum_max){
                sum_max = prevSum;
            }
        }
    }
    return sum_max;
}

int max_midSum(int *a, int left, int right) // function used in Lab10 recursive MSS
{
    int sum = 0;
    int middle = (left+right)/2;
    
    int lsum = -2147483648; //INT_MIN
    for (int i = middle; i >= left; i--){
        sum += a[i];
        if (sum > lsum){
            lsum = sum;
        }
    }
    
    sum = 0;
    int rsum = -2147483648; //INT_MIN
    for (int i = middle + 1; i <= right; i++){
        sum += a[i];
        if (sum > rsum){
            rsum = sum;
        }
    }
    return (lsum + rsum);
}

int mss_10(int*a, int left, int right) //Lab 10 MSS
{
    if (left == right){
        return a[left];
    }
    
    int middle = (left + right)/2;
    int left_max = mss_10(a, left, middle);
    int right_max = mss_10(a, middle + 1, right);
    int mid_max = max_midSum(a, left, right);
    
    if ((left_max >= right_max) && (left_max >= mid_max)){
        return left_max;
    }
    else if ((right_max >= left_max) && (right_max >= mid_max)){
        return right_max;
    }
    else{
        return mid_max;
    }
}

int main()
{
    int * array; 
    int size, result;
    clock_t start, end; // For timing of the code

// === Testing ===
    // Create and print the example sequence
    size = 10;
    populateTest(array);
    print(array,size);
    cout << endl;
    
    // Test Lab 2 MSS
    if (mss_2(array, 10) == 187){
        cout << "Lab 2 MSS Passes" << endl;
    }
    else{
        cout << "Lab 2 MSS Fails" << endl;
    }
    
    // Test Lab 10 MSS
    if (mss_10(array, 0, 9) == 187){
        cout << "Lab 10 MSS Passes" << endl;
    }
    else{
        cout << "Lab 10 MSS Fails" << endl;
    }

    sort(array, size); //sort the array for Search functions
    print(array,size); //print sorted array
    
    // Test Linear Search
    if (linearSearch(array, 0, 9, -53) == 1){
        cout << "Linear Search Passes" << endl;
    }
    else{
        cout << "Linear Search Fails" << endl;
    }
    
    if (linearSearch(array, 0, 9, 5000) == -1){
        cout << "Linear Search Passes" << endl;
    }
    else{
        cout << "Linear Search Fails" << endl;
    }
    
    // Test Binary Search
    if (binarySearch(array, 1, 9, -53) == 1){
        cout << "Binary Search Passes" << endl;
    }
    else{
        cout << "Binary Search Fails" << endl;
    }
    
    if (binarySearch(array, 0, 9, 5000) == -1){
        cout << "Binary Search Passes" << endl;
    }
    else{
        cout << "Binary Search Fails" << endl;
    }
    
// === Timing ===
    int loop = 1000; // # of times the function is looped
    size = 1000; // input size

    // --- Maximum Subsequence Sum ---
    populate(array, size);
    cout << endl;
    
    // Execute and time Lab2 Algorithm
    start  = clock();
    for (int i = 0; i < loop; i++){
        result = mss_2(array, size);
    }
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for the Lab2 MSS to obtain the result.\n" << endl;
    
    // Execute and time Lab10 Algorithm
    start  = clock();
    for (int i = 0; i < loop; i++){
        result = mss_10(array, 0, size-1);
    }
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for the Lab10 MSS to obtain the result.\n" << endl;

    cout << "#############################################################################\n" << endl;
    
    sort(array, size); //sort the array for Search functions
// --- Search when value is in the array ---
    int x = array[(rand() % (size-1))]; //random value within the array
    cout << "x is within the array\n" << endl;
    
    // Execute and time Linear Search
    start  = clock();
    for (int i = 0; i < loop; i++){
        result = linearSearch(array, 0, size-1, x);
    }
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for the Linear Search to obtain the result.\n" << endl;
    
    // Execute and time Binary Search
    start  = clock();
    for (int i = 0; i < loop; i++){
        result = binarySearch(array, 0, size-1, x);
    }
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for the Binary Search to obtain the result.\n" << endl;
    
// --- Search when value is NOT in the array ---
    x = (5*size) + 1; //NOT within array
    cout << "x is NOT within the array\n" << endl;
    
    // Execute and time Linear Search
    start  = clock();
    for (int i = 0; i < loop; i++){
        result = linearSearch(array, 0, size-1, x);
    }
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for the Linear Search to obtain the result.\n" << endl;
    
    // Execute and time Binary Search
    start  = clock();
    for (int i = 0; i < loop; i++){
        result = binarySearch(array, 0, size-1, x);
    }
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for the Binary Search to obtain the result.\n" << endl;
    
    return 0;
}