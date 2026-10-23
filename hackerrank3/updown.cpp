// total amount of valleys

int countingValleys(int steps, string path)
{
    int level = 0;
    int valleys = 0;
    
    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            level++;
            if (level == 0) {
                valleys++;
            }
        }
        else if (path[i] == 'D') {
            level--;
        }
    }
    
    return valleys;
}