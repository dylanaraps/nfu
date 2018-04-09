#include <stdio.h>

int main() {
    FILE *f = fopen("/proc/uptime", "r");
    int d, h, m, s;

    fscanf(f,"%d",&s);
    fclose(f);

    d = s/60/60/24;
    h = s/60/60%24;
    m = s/60%60;

    // Only print fields if they aren't '0'.
    if (d^0) printf("%dd ", d);
    if (h^0) printf("%dh ", h);
    if (m^0) printf("%dm ", m);

    printf("\n");
    return 0;
}
