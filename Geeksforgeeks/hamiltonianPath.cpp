#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int isHamiltonianPath(int ** inputArray, int vert, int edge){
    int* array = new int[vert];
    int prevVert=0;
    stack<int> s;

    int i=0;
    int j=0;
	int k;
    int start=0;
    i = start;
    memset( array, 0, sizeof(int)*vert);
	
    while (i<vert){
        if ( j >= vert ){
            if (s.empty()) { 
                start = start+1;
                i = start;
                if (start >= vert ) return 0;
                j=0;
            } else {
                i = s.top();
                s.pop();
                j = array[i]+1;
				array[i] = 0;
            }
            continue;
        }
		
        if ( array[i] == 0 ){
            if ( inputArray[i][j]==1 ){
                array[i] = j;
                s.push(i);
                i = j;
                j=0;
            } else {
                j++;
            }
        }else{
            if (s.size()==vert) return 1;
            
            i = s.top();
            s.pop();
            j = array[i]+1;
			array[i] = 0;
        }
    }
}

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

