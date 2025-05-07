// function for DFS traversal
void dfs(char** grid, int rows, int cols, int i, int j) {
   // Boundary and base condition checks
   if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
       return;
   // Mark the current land as visited
   grid[i][j] = '0';
   // Visit all 4 directions (up, down, left, right)
   dfs(grid, rows, cols, i + 1, j);
   dfs(grid, rows, cols, i - 1, j);
   dfs(grid, rows, cols, i, j + 1);
   dfs(grid, rows, cols, i, j - 1);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
   if (grid == NULL || gridSize == 0 || gridColSize == NULL) return 0;
   int count = 0;
   int cols = gridColSize[0];  // Same amount of rows as columns 
   for (int i = 0; i < gridSize; i++) {
       for (int j = 0; j < cols; j++) {
           if (grid[i][j] == '1') {
               count++;                 // Island found
               dfs(grid, gridSize, cols, i, j);  // Sink island
           }
       }
   }
   return count;
}
