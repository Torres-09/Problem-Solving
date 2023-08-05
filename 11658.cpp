#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1025 * 1025;
int n, m;
long arr[1025][1025];
long tree[MAX * 4];
pair<int, int> p[MAX];

// end를 2차원 배열로 변환해야 함
long make_segment_tree(int start, int end, int node)
{

    if (start == end)
    {
        return tree[node] = arr[p[end].first][p[end].second];
    }

    int mid = (start + end) / 2;

    return tree[node] = make_segment_tree(start, mid, node * 2) + make_segment_tree(mid + 1, end, node * 2 + 1);
}

// 1, 16, 6, 8, 1
// 1, 16, 12, 12, 1
long find_sum(int start, int end, int left, int right, int node)
{
    if (left <= start && right >= end)
        return tree[node];
    if (left > end || right < start)
        return 0;

    int mid = (start + end) / 2;
    return find_sum(start, mid, left, right, node * 2) + find_sum(mid + 1, end, left, right, node * 2 + 1);
}

void update_tree(int start, int end, int node, int index, int diff)
{
    if (index < start || index > end)
        return;
    tree[node] += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update_tree(start, mid, node * 2, index, diff);
        update_tree(mid + 1, end, node * 2 + 1, index, diff);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    // 표 입력받기 ( n*n -> 백만)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    p[1].first = 1;
    p[1].second = 1;
    // ( 백만 )
    for (int i = 1; i <= n * n; i++)
    {
        // 다음 행으로 넘어갈 때
        if (p[i - 1].second % n == 0)
        {
            // 행 증가
            p[i].first = p[i - 1].first + 1;
            // 열은 1부터
            p[i].second = 1;
            continue;
        }
        // 열을 이동할 때
        p[i].first = p[i - 1].first;
        p[i].second = p[i - 1].second + 1;
    }

    // make_segment_tree(1, 16, 1);
    // 여기까지 잘 된다.

    make_segment_tree(1, n * n, 1);

    for (int i = 0; i < m; i++)
    {
        // 커맨드 선택
        int w;
        cin >> w;

        // 좌표 입력받기
        int x, y;
        int x2, y2;

        // 값을 변경합니다.
        if (w == 0)
        {
            long c;
            cin >> x >> y >> c;
            int Point = (x - 1) * n + y;
            // 새로운 값 - 원래 값
            long diff = c - arr[x][y];
            update_tree(1, n * n, 1, Point, diff);
        }
        // 합을 출력합니다.
        else if (w == 1)
        {
            long sum = 0;
            cin >> x >> y >> x2 >> y2;
            // (x,y) -> n * (x-1) + y,  (x2,y2) -> n * (x2 -1) + y2
            for (int i = x; i <= x2; i++)
            {
                int p1 = (i - 1) * n + y;
                int p2 = (i - 1) * n + y2;
                sum += find_sum(1, n * n, p1, p2, 1);
            }
            cout << sum << "\n";
        }
    }
}

//  node가 십만개
// height -> 20층 최대
// 커맨드에서 수정 -> 
// 커맨드가 십만개