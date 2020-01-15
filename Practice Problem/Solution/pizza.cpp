#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <vector>

using namespace std;
// double pi = 2*acos(0.0);

typedef long long ll;
typedef unsigned long long ull;

int maxSum(int slices[], int NumSlices, int MaxSlices)
{
    int curr_sum = slices[0], max_sum = 0, start = 0;
    for (int i = 0; i < NumSlices; i++)
    {
        if (curr_sum <= MaxSlices)
            max_sum = max(max_sum, curr_sum);
        while (curr_sum + slices[i] > MaxSlices && start < i)
            curr_sum -= slices[start++];
        curr_sum += slices[i];
    }
    if (curr_sum <= MaxSlices)
        max_sum = max(max_sum, curr_sum);
    return max_sum;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    if (argc != 2) {
        std::cout << "Usage: ./a.out 'input_file_name'\n";
    }
    else
    {
        string input_file = argv[1];
        ifstream ifs ("input/" + input_file + ".in");

        if (!ifs.is_open())
            throw std::ios_base::failure("Cannot open the input file.");

        int MaxSlices, NumSlices;
        ifs >> MaxSlices >> NumSlices;
        cout << MaxSlices << "\t" << NumSlices << endl;

        int slices[NumSlices];
        for (int i = 0; i < NumSlices; i++)
            ifs >> slices[i];
        cout << maxSum(slices, NumSlices, MaxSlices) << endl;

        ifs.close();
    }
    return (0);
}