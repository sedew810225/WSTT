class Solution {
public:
    int maxRow, maxCol;
    int maxLevel;
    int **levelArray;
    
    int getLevel ( vector<vector<char>>& matrix, int row, int col) {
        int level1=-1, level2=-1, level3=-1;
        int level=-1;
        
        // if the value is 1, it's minimum size
        if ( matrix[row][col] == '0') level = 0;
        else level = 1;
        
        // check left the previous level of (row+1 , col)
        if ( row+1 < maxRow) {
            if ( levelArray[row+1][col] <0 ) level1 = getLevel(matrix, row+1, col);
            else level1 = levelArray[row+1][col];
        }

        // check bottom the previous level of (row , col+1)
        if ( col+1 < maxCol ){
            if ( levelArray[row][col+1] <0 ) level2 = getLevel(matrix, row, col+1);
            else level2 = levelArray[row][col+1];
        }

        // check left-bottom the previous level of (row+1 , col+1)
        if (row+1 < maxRow && col+1 < maxCol ) {
            if ( levelArray[row+1][col+1] <0 ) level3 = getLevel(matrix, row+1, col+1);
            else level3 = levelArray[row+1][col+1];
        }

        // if all direction has posivive level, 
        // then current cell will have 1 more level of minimum
        if ( level1>0 && level2>0 && level3>0 && level!=0) {
            level = min(level1, level2);
            level = min(level3, level)+1;
        }

        // update level info for memoization to use from other cells
        levelArray[row][col] = level;
        
        // update maxLevel for answering
        if ( level > maxLevel ) maxLevel = level;
        
        return level;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {  
        maxRow=0, maxCol=0, maxLevel=0;

        // boundary check
        maxRow = matrix.size();
        if ( maxRow==0 ) return 0;
        maxCol = matrix[0].size();

        // array for memoization of level
        levelArray = new int*[maxRow];
        for ( int i=0; i< maxRow;i++){
            levelArray[i] = new int[maxCol];
            memset(levelArray[i], -1, sizeof(int)*maxCol);
        }
        
        getLevel(matrix, 0, 0);
        
        // debug print
        #if 0
        for (int i=0;i<maxRow;i++){
            for (int j=0;j<maxCol;j++){
                cout << levelArray[i][j] <<" ";
            }
            cout << endl;
        }
        #endif
        
        // memory de-initialization
        for ( int i=0; i< maxRow;i++){
            delete[] levelArray[i];
        }
        delete[] levelArray;
        
        //The size of squre will be maxLev*maxLev
        return maxLevel*maxLevel;
    }
};