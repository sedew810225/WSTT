#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int isHamiltonianPath(int ** inputArray, int vert, int edge){
    int* NextVert = new int[vert];
    stack<int> s;

    int start=0, curVert=0, prevVert=-1;
	int v;

    curVert = start;
    memset( NextVert, -1, sizeof(int)*vert);
	
    while (start < vert) {

        if (s.size() == vert) return 1;

        if (NextVert[curVert] == -1) {

            v = prevVert + 1;
            while (v < vert) {
                if (inputArray[curVert][v] == 1) break;
                v++;
            }

            if (v < vert) {
                s.push(curVert);
                NextVert[curVert] = v;
                curVert = v;
                prevVert = NextVert[curVert];
                continue;
            }
        }

        if (s.empty() != true) {
            curVert = s.top();
            s.pop();
            prevVert = NextVert[curVert];
            NextVert[curVert] = -1;
        }
        else {
            start++;
            curVert = start;
            prevVert = -1;
            memset(NextVert, -1, sizeof(int) * vert);
        }
    }

    return 0;
}

#if 0
int main() {
	int cntProg;
	int nVert, nEdge;
	int u,v;
	int ** array;
	
	cin >> cntProg ;

    for (int i=0;i<cntProg;i++){	
        cin >> nVert >> nEdge;
        
        array = new int*[nVert];
        for (int j=0;j<nVert;j++){
            array[j] = new int[nVert];
			memset (array[j], 0, sizeof(int)*nVert);
        }
        
        for (int j=0;j<nEdge;j++){
            cin >> u >> v;
            array[u-1][v-1] = 1;
            array[v-1][u-1] = 1;
        }
        
        cout << isHamiltonianPath(array, nVert, nEdge) << "\n";
        
        delete[] array;
    }
    
	return 0;
}
#endif

