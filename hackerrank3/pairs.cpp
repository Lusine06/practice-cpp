// total amount of pairs

int sockMerchant(int n, vector<int> ar)
{
    int total = 0;
    int array[101] = {0};

    for (int i = 0; i < n; i++)
    {
        array[ar[i]]++;
    }

    for (int i = 1; i <= 100; i++)
    {
        total += array[i] / 2;
    }

    return total;
}