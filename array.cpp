#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int Length;
    void swap(int *a, int *b);
    public:
    Array();
    Array(int size);
    void display();
    void insert(int index, int x);
    void add(int x);
    int deleteElement(int index);
    int Lsearch(int x);
    int Bsearch(int x);
    int RbinarySearch(int l, int h, int x);
    int getElement(int index);
    void setElement(int index, int ele);
    int maxElement();
    int minElement();
    void reverseArray();
    void leftShift();       //left shift of array or rotate the array
    int isSorted();
    void negativeLeftSide();// put -ve number on the left hand side and +ve on the right side
    Array * merge(Array *arr2);//merging of two array or union of an array
    Array * intersection(Array *arr2);//finding common element b/w two array
    Array * difference(Array *arr2);//finding set diiference b/w arr1 and arr2 and copy only those element of arr1 to arr3 which are not present in arr2

    void singleMissingElement();//to find a single missing element in a sorted array
    void multiMissingElement();//to find multiple missing element in a sorted array
    void missingElementUnsortedArray();// to find the missing number of element in an unsorted Array
    ~Array();
};
void Array :: swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
Array :: Array(){
    size=12;
    A = new int[size];
    Length = 0;
}
Array :: Array(int size){
    this->size = size;
    A = new int[size];
    Length = 0;
}
Array :: ~Array(){
    delete[] A;
}
void Array :: insert(int index, int x){
    if(index>=0 || index<=Length){
        for(int i = Length; i>=index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        Length++;
    }
    
}
void Array :: display(){
    for(int i=0; i<Length; i++){
        cout<<A[i]<<" ";
    }
}
void Array :: add(int x){
    A[Length] = x;
    Length++;
}
int Array :: deleteElement(int index){
    int x = A[index];
    for(int i = index; i<Length-1; i++)
        A[i] = A[i+1];
    Length--;
    return x;
}
int Array :: Lsearch(int x){
    for(int i=0; i<Length; i++){
        if(A[i] == x)
            return true;
    }
    return false;
}
int Array :: Bsearch(int x){
    int low = A[0];
    int high = Length-1;
    int mid;
    while(low <= high){
        mid = low+high/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid] > x)
            high = mid-1;
        else 
            low = mid+1;
    }
    return -1;
}
int Array :: RbinarySearch(int l, int h, int x){
    while(l<=h){
        int mid = l+h/2;
        if(A[mid] == x)
            return mid;
        if(A[mid] < x)
            return RbinarySearch(mid+1, h, x);
        else
            return RbinarySearch(l, mid-1, x);
    }
    return -1;
}
int Array :: getElement(int index){
    if(index<0 || index>Length-1)
        return -1;
    int x = A[index];
    return x;
}
void Array :: setElement(int index, int ele){
    if(index<0 || index>Length-1)
        return;
    A[index] = ele;

}
int Array :: maxElement(){
    int max = INT16_MIN;
    for(int i=0; i<Length; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;

}
int Array :: minElement(){
    int min = INT16_MAX;
    for(int i=0; i<Length; i++){
        if(A[i] < min)
            min = A[i];
    }
    return min;
}
void Array :: reverseArray(){
    // approach - 1
    // int *B;
    // B = new int[size];
    // for(int i=Length-1,j=0; i>=0; i--, j++)
    //     B[j] = A[i];
    // for(int i=0; i<Length; i++)
    //     A[i] = B[i];
    // delete[] B;
    

    //approach - 2
    for(int i=Length-1,j=0; j<i; i--, j++)
        swap(&A[i], &A[j]);

}
void Array :: leftShift(){
    int x = A[0];
    for(int i = 0; i<Length; i++){
        A[i] = A[i+1];
    }
    A[Length-1] = x;
}
int Array :: isSorted(){
    for(int i=0; i<Length-1; i++){
        if(A[i]>A[i+1])
            return false;
    }
    return true;
}
void Array :: negativeLeftSide(){
    int i=0;
    int j = Length-1;
    while(i<j){
        if(A[i] < 0)
            i++;
        else if(A[j] > 0)
            j--;
        if(i<j)
            swap(&A[i], &A[j]);
    }
}
Array * Array :: merge(Array *arr2){
    int i=0;
    int j=0;
    int k=0;
    Array *arr3 = new Array[Length + arr2->Length];
    while(i<Length && j<arr2->Length){
        if(A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if(A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];       
    }
    for(; i<Length; i++)
        arr3->A[k++] = A[i];
    for(; j<arr2->Length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->Length = k;
    arr3->size = 10;

    return arr3;

}
Array *Array :: intersection(Array *arr2){
    int i, j,k;
    i=j=k=0;
    Array *arr3 = new Array[Length + arr2->Length];
    while(i<Length && j<arr2->Length){
        if(A[i] < arr2->A[j])
            i++;
        else if(A[i] > arr2->A[j])
            j++;
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->Length = k;
    arr3->size = 10;

    return arr3;
}
Array *Array :: difference(Array *arr2){
    int i,j,k;
    i=j=k=0;
    int c=0;
    Array *arr3 = new Array[Length+arr2->Length];

    for(i=0; i<Length; i++){
        for(j=0; j<arr2->Length; j++){
            if(A[i] == arr2->A[j]){
                c++;
                break;
            }
        }
        if(c==0){
            arr3->A[k++] = A[i];
        }
        c=0;
    }
    for(; i<Length; i++){
        arr3->A[k++] = A[i];
    }
    cout<<k<<endl;
    arr3->Length = k;
    arr3->size = 10;
    return arr3;
}
void Array :: singleMissingElement(){
    int l = A[0];
    int diff = l;
    for(int i=0; i<Length; i++){
        if(A[i] - i != diff){
            cout<<"Missing Element is "<<i+diff<<endl;
            break;
        }
    }
}
void Array :: multiMissingElement(){
    int l = A[0];
    int diff = l;
    for(int i=0; i<Length; i++){
        if(A[i] - i != diff){
            cout<<"Missing Element is "<<i+diff<<endl;
            diff++;
        }         
    }
}
void Array :: missingElementUnsortedArray(){
    int l = minElement();
    int h = maxElement();
    int *H[h];
    for(int i=l; i<h; i++)
        H[i] = 0;
    for(int i=0; i<Length; i++)
        H[A[i]]++;
    for(int i=0; i<=h; i++){
        if(H[i] == 0)
            cout<<"Missing Element is "<<i<<endl;
    }
}
int main(){
    int size;
    // cout<<"Enter the size of an Array : ";
    // cin>>size;

    Array a;
    a.insert(0,1);
    a.insert(1,2);
    a.insert(2,3);
    a.insert(3,4);
    a.insert(4,5);
    a.insert(5,6);
    a.insert(6,8);
    a.insert(7,9);
    // a.insert(8,10);
    a.insert(8,11);
    a.insert(9,12);
    a.display();
    cout<<endl;
    a.missingElementUnsortedArray();
    // cout<<endl;
    // Array b;
    // b.insert(0,3);
    // b.insert(1,4);
    // b.insert(2,5);
    // b.insert(3,7);
    // b.insert(4,8);
    // b.display();
    // cout<<endl;
    // Array *arr3;
    // arr3 = a.intersection(&b);

    // arr3 = a.difference(&b);
    // arr3->display();
    return 0;
    


}