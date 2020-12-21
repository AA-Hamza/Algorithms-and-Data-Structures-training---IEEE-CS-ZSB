/* 
 * Proble Link https://codeforces.com/problemset/problem/834/B
 * Time complexity O(n)
*/

#include <iostream>
#include <algorithm>

#define ALPHA_NUM ('Z'-'A'+1)

using namespace std;
enum class GateState {closed=-1, neutral=0, opened=1};

struct Gate {
    GateState currState;
    int index;
    Gate(): currState{GateState::neutral}, index{-1} {};
};


struct compare_indexes
{
    inline bool operator() (Gate& a, Gate& b)
    {
        if (a.index == b.index) {
            if (b.currState == GateState::closed) {
                b.currState = GateState::opened;
                a.currState = GateState::closed;
            }
        }
        return (a.index < b.index);
    }
};


int main()
{
    int n, guards;
    cin >> n >> guards;

    //Every char (gate) would have 2 elements opening & closing [A, B, C, ..., ALPHANUM, A, B, C, ..., ALPHANUM*2]
    Gate *gateIndexes = new Gate[ALPHA_NUM*2];

    char curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (gateIndexes[(int)(curr-'A')].currState == GateState::neutral) {
            gateIndexes[(int)(curr-'A')].currState = GateState::opened;
            gateIndexes[(int)(curr-'A')].index     = i;
        }
        gateIndexes[(int)(curr-'A')+(ALPHA_NUM)].index = i;
        gateIndexes[(int)(curr-'A')+(ALPHA_NUM)].currState= GateState::closed;
    }

    sort(gateIndexes, gateIndexes+(ALPHA_NUM*2), compare_indexes());

    int result = 0;
    for (int i = 0; i < (ALPHA_NUM*2); ++i) {
        result += (int)gateIndexes[i].currState;
        if (result > guards) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
