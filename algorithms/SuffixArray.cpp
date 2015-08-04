// Structure to store information of a suffix
struct suffix
{
    int index;
    string suff;
};

int cmp(struct suffix a, struct suffix b)
{
    return a.suff < b.suff;
}

vector<int> buildSuffixArray(string txt, int n)
{
    vector<suffix> suffixes (n);

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt + (char) i);
    }

    sort(suffixes.begin(), suffixes.end(), cmp);

    vector<int> suffixArr (n);
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    return suffixArr;
}
