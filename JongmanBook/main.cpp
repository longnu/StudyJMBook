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
    fast_io; // ���� ����� ����

    // ���� �ð� ����
    auto start = chrono::high_resolution_clock::now();

    // �˰��� ���� �ذ� �Լ� ȣ��
    pick(7, picked, 4);

    // ���� �ð� ���� �� ���� �ð� ���
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cerr << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}



