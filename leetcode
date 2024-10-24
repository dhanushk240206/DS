int firstUniqChar(char* s) {
    int k = strlen(s);
    for (int i = 0; i < k; i++) {
        int flag = 1;
        if (s[i] != '#') {
            for (int j = i + 1; j < k; j++) {
                if (s[i] == s[j]) {
                    s[j] = '#';
                    flag = 0;
                }
            }
            if (flag == 1) {
                return i;
            }
        }
    }
    return -1;
}
