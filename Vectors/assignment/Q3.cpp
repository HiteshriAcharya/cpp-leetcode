#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/**
 * A vector has multiple constructors:
 * 
 * 1. Default: vector<int> v;
 * 
 * 2. Size constructor: vector<int> v(5);   // 5 elements, default-initialized
 *
 * 3. Fill constructor: vector<int> v(5, 10);  // {10,10,10,10,10}
 * 
 * 4. Range constructor: vector<int> v(startIterator, endIterator);
 * 
 */

vector<vector<int>> threeSum(vector<int> nums){

    vector<int> copySorted = nums;
    set<vector<int>> uniqueResult;

    sort(copySorted.begin(), copySorted.end());

    for (int i = 0; i < copySorted.size(); i++)
    {

        int target = 0 - copySorted.at(i);
        int start = i + 1;
        int end = copySorted.size() - 1;

        while (start < end)
        {

            int sum = copySorted.at(start) + copySorted.at(end);

            if (sum == target)
            {
                vector<int> temp = {copySorted.at(i), copySorted.at(start), copySorted.at(end)};
                sort(temp.begin(), temp.end());
                uniqueResult.insert(temp);

                start += 1;
                end -= 1;
            }
            else if (sum < target)
            {
                start += 1;
            }
            else
            {
                end -= 1;
            }
        }
    }

    vector<vector<int>> result(uniqueResult.begin(), uniqueResult.end());
    return result;
}

int main(){

    int size;

    cout << "Enter size: ";
    cin >> size;

    vector<int> input(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " th element: ";
        cin >> input[i];
    }

    vector<vector<int>> result = threeSum(input);

    for(int i = 0; i < result.size(); i++){

        for(int j = 0; j < 3; j++){

            cout << result[i][j] << " ";
        }

        cout << endl;
    }
}