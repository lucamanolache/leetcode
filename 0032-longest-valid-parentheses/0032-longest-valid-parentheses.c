int longestValidParentheses(char* s) {
    if (!*s) return 0;
    int _stack[strlen(s)], *stack = _stack;
    *stack++ = *s++ & 1; // copy first value manually
    if (!*s) return 0;

    int max = 0;
    do {
        *stack = *s++ & 1;
        if (*stack == 1) {
            if (stack[-1] == 0) stack[-1] = 2;
            else if (stack - 2 >= _stack && stack[-1] >= 2 && stack[-2] == 0) stack[-1] = *--stack + 2;
            else stack++;
            if (stack - 2 >= _stack && stack[-1] >= 2 && stack[-2] >= 2) stack[-1] += *--stack;
            max = max >= stack[-1] ? max : stack[-1];
        } else stack++;
    } while (*s);
    return max & 2147483646;
}
