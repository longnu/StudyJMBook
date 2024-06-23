#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// ������ ��ũ�� ����
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
    fast_io; // ���� ����� ����

    // ���� �ð� ����
    auto start = chrono::high_resolution_clock::now();

    string word = "PRETTY";
    // �˰��� ���� �ذ� �Լ� ȣ��
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << hasWord(i, j, word);
        }
    }

    // ���� �ð� ���� �� ���� �ð� ���
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cerr << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}



