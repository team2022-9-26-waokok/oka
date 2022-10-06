

int uniform_int(int n) {
    int adjusted_max = (RAND_MAX + 1) - (RAND_MAX + 1) % n;
    int r;
    do {
        r = rand();
    } while (r >= adjusted_max);
    return (int)(((double)r / adjusted_max) * n);
}