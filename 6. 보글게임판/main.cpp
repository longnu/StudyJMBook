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

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

char board[5][5] = {
        {'U', 'R', 'L', 'P', 'M'},
        {'X', 'P', 'R', 'E', 'T'},
        {'G', 'I', 'A', 'E', 'T'},
        {'X', 'T', 'N', 'Z', 'Y'},
        {'X', 'O', 'Q', 'R', 'S'}
};

bool inRange(int y, int x)
{
    return y >= 0 && y < 5 && x >= 0 && x < 5;
}

bool hasWord(int y, int x, const string& word)
{
    if (!inRange(y, x)) return false;
    if (board[y][x] != word[0]) return false;
    if (word.size() == 1) return true;
    for (int direction = 0; direction < 8; ++direction)
    {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}


int main() {
    fast_io; // 빠른 입출력 설정

    // 시작 시간 측정
    auto start = chrono::high_resolution_clock::now();

    string word = "PRETTY";
    // 알고리즘 문제 해결 함수 호출
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << hasWord(i, j, word);
        }
    }

    // 종료 시간 측정 및 실행 시간 출력
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cerr << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}



