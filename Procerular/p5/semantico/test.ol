main {
    int i;
    array int [8] x;

    i = 0;
    while ((i < 8)) {
        x[i] = i * (i-1);
        i = i + 1;
    }

    i = 0;
    while ((x[i] < 40)) {
        printf x[i];
        i = i + 1;
    }

}