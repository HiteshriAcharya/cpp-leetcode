#include <iostream>
#include <vector>
using namespace std;

/**
 * * ALGORITHM TYPE * : 2 POINTER APPROACH 
 */

vector<int> PairSum(vector<int> input, int target){

    int startIdx = 0;
    int endIdx = input.size() - 1;
    int tempSum = 0;

    vector<int> result(2,-1);

    // In this case, we cannot have startIdx = endIdx because the sum needs to be with
    // unique elements.

    while(startIdx < endIdx){

        tempSum = input.at(startIdx) + input.at(endIdx);

        if(tempSum == target){

            result.at(0) = startIdx;
            result.at(1) = endIdx;

            return result;

        } else if(tempSum < target){

            startIdx += 1;
        } else {

            endIdx -= 1;
        }
    }

    // C++ requires that every possible control path in a non-void function returns a value.

    return result;
}

int main(){

    /** 
     * When we want to get a vector as an input from the user, we need to either 
     * initialise the size or we need to use push_back(). This is because if 
     * we dont specify the size, it is initially 0. Hence, when we try to use it as
     * vector[i], we will exceed the size of the vector, 0.
     */

    int size, target;

    cout << "Enter size: ";
    cin >> size;

    vector<int> input(size);

    for(int i = 0; i < size; i++){
        cout << "Enter " << i << " th element: ";
        cin >> input[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector <int> result(2,-1);

    result = PairSum(input, target);

    cout << "We get the target by adding " << input[result.at(0)] << " at index " << result[0] 
         << " and " << input[result.at(1)] << " at index " << result[1] << endl;
}