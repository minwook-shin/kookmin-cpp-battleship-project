#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int tmp;
    int total;
    int result;
    ifstream file("turn.txt");

    for (int i = 0; i < 10; i++)
    {
        file >> tmp;
        v.push_back(tmp);
    }

    cout << "배틀쉽 판마다 진행된 횟수 : "<<endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i+1 << "->"<< v[i]<<" ";
        total += v[i];
    }
    cout << endl;

    result = total / 10;

    cout << "평균 결과 :"<< result << endl;

    return 0;
}
