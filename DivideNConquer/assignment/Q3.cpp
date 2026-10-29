#include <iostream>
#include <vector>
using namespace std;

/**
 * Basically instead of couting one by one all the pairs
 * where i < j but arr[i] > arr[j, we do it in a group using a 
 * logic. 
 * 
 * For merge sort, because when it comes to this merge step, it 
 * is like the left and right portions are sorted. Hence, if there
 * is an element in the left array where arr[left] > arr[right], all
 * the elements coming AFTER arr[left] is going to be NATURALLY greater
 * than arr[right]. That is the simple logical trick!!
 */

int merge(vector<int> &arr, int start, int mid, int end){

    int left = start;
    int right = mid+1;
    int inversions = 0;

    vector<int> temp;

    while(left <= mid && right <= end){
        
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        } else{
            temp.push_back(arr[right++]);
            inversions += (mid-left+1);
        }
    }

    while(left <= mid){
        temp.push_back(arr[left++]);
    }

    while(right <= end){
        temp.push_back(arr[right++]);
    }

    for(int i = start, x = 0; i <= end; i++){
        arr[i] = temp[x++];
    }

    return inversions;
}


/**
 * 
 * Here, we need to "remember" the total inversion count from all 
 * the recursive calls made. We cannot lose the count because we didn't
 * return it. Hence, we have to return it. 
 * 
 * At each recursive call, it will either return 0 or return the inversion count.
 * 
 * Let's take {2,3,1,4} as an example and trace the recursive call:
 * 
 * mid = 1 (1)
 * enter left inversion from idx 0 to 1 (1)
 * mid = 0 (2)
 * enter left inversion from idx 0 to 0 (2)
 * return 0 (2)
 * enter right inversion from idx 1 to 1 (2)
 * return 0 (2)
 * merge idx 0 to 1 (2)
 * return inversion count = 0 (2)
 * 
 * enter right inversion from idx 2 to 3 (1)
 * mid = 2 (3)
 * enter left inversion from idx 2 to 2 (3)
 * return 0
 * enter right inversion from idx 3 to 3 (3)
 * return 0
 * enter merge from idx 2 to 3 (3)
 * return inversion count = 0 (3)
 * 
 * enter merge from idx 0 to 3 (1)
 * return inversion count = 2 (1)
 * 
 */

int inversionCount(vector<int> &arr, int start, int end){

    if(start < end){

        int mid = start + ((end-start)/2);
        int leftInversionCount = inversionCount(arr,start,mid);   // to remember the prev inversions no.
        int rightInversionCount = inversionCount(arr,mid+1,end);
        int totalInversionCount = merge(arr, start, mid, end);

        return leftInversionCount+rightInversionCount+totalInversionCount;
    }

    return 0;
}

int main(){

    vector<int> arr = {2,4,1,3,5};
    int inversions = inversionCount(arr, 0, arr.size()-1);
    cout << inversions << endl;
}