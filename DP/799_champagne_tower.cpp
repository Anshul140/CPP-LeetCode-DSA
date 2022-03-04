/*
Algorithm: 
   -> Each glass contributes to the two glasses down the glass
   -> Initially, we put all water in the first glass
   -> Then we keep 1 litre (or less than 1 litre) in it and move rest of the water to two glasses down to it
   -> We follow the same process for the two glasses and all other glasses till the ith row
   -> There will be i*(i+1)/2 glasses till ith row. 
*/

double champagneTower(int poured, int q_row, int q_glass) {
    if(poured == 0) return 0;
    
    double arr[105][105];
    
    memset(arr, 0, sizeof(arr));
    arr[0][0] = poured;
    
    for(int i = 0; i<q_row; i++)
    {
        for(int j = 0; j<= q_glass; j++)
        {
            double rem = max(arr[i][j] - 1, 0.0);
            arr[i+1][j] += rem/2.0;
            arr[i+1][j+1] += rem/2.0;
        }
    }
    
    return min(arr[q_row][q_glass], 1.0);
}