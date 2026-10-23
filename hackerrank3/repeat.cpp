// number of repetitions

long repeatedString(string s, long n) {
    long total = 0;
    long s_total = 0;
    
    //the amount of "a" in just one s string
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            s_total += 1;
        }
    }
    
    // the amount of s in total n
    long amount = n / s.length();
    total += amount * s_total;
    
    // left part
    long left = n % s.length();
    for (size_t i = 0; i < left; i++) {
        if (s[i] == 'a') {
            total += 1;
        }
    }
    
    return total;
}