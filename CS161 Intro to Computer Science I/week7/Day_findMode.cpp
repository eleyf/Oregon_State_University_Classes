#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMode(int inputList[], int numValues){

    int maxFrequency = 1;
    vector<int> highFrequencyList;

    // loop over each member of the array
    for(int outterLoopIter = 0; outterLoopIter < numValues; outterLoopIter++){

        int thisFrequency = 1;

        // compare against every member forward in the list
        for(int innerLoopIter = outterLoopIter + 1; innerLoopIter < numValues; innerLoopIter++){
            // check to see if we have a repeat number, and increase the counter
            if (inputList[outterLoopIter] == inputList[innerLoopIter]){
                thisFrequency++;
            }
        }

        if (thisFrequency == maxFrequency){
            // we've tied for the most frequeny, add it to the list!
            highFrequencyList.push_back(inputList[outterLoopIter]);
        } else if (thisFrequency > maxFrequency){
            // we've passed the previous most frequent, set the new bar here
            maxFrequency = thisFrequency;
            // then clear the list and add just this number
            highFrequencyList.clear();
            highFrequencyList.push_back(inputList[outterLoopIter]);
        }

    }
    // sort the result and return it.
    std::sort(highFrequencyList.begin(),highFrequencyList.end());
    return highFrequencyList;

}

#include <iostream>

int main()
{   
    const int SIZE = 5; 
    int input[SIZE] = {3, 1, 6, 4, 6};

    vector<int> modeVector = findMode(input, SIZE);

    for(int i = 0; i < modeVector.size(); i++)
    {
        cout << modeVector[i] << endl;
    }
    
    return 0;
}