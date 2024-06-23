#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// 유용한 매크로 정의
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

vector<int> picked;
void printPicked(vector<int> picked)
{
    for (vector<int>::iterator it = picked.begin(); it != picked.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void pick(int n, vector<int>& picked, int toPick)
{
    if (toPick == 0) { printPicked(picked); return; }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for (int next = smallest; next < n; ++next) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main() {
    fast_io; // 빠른 입출력 설정

    // 시작 시간 측정
    auto start = chrono::high_resolution_clock::now();

    // 알고리즘 문제 해결 함수 호출
    pick(7, picked, 4);

    // 종료 시간 측정 및 실행 시간 출력
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cerr << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}



