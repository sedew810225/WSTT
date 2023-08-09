#include <cstdio>
using namespace std;

#if 0
int find(int);
int rootArray[1000001];

int main(void) {
    int n, m;
    int cmd, a, b;

    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        rootArray[i] = i;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &cmd, &a, &b);

        if (cmd == 0) {
            if (a != b) {
                a = find(a);
                b = find(b);

                if (a < b)  rootArray[b] = a;
                else rootArray[a] = b;
            }
        }
        else {
            a = find(a);
            b = find(b);

            if (a == b) printf("YES\n");
            else printf("NO\n");
        }
    }
}

int find(int i) {
    if (rootArray[i] == i) return i;  //find root
    else {
        rootArray[i] = find(rootArray[i]);
        return rootArray[i];
    }
}
#endif