#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo i;
    int d, h, m;

    if (sysinfo(&i)^0) return 1;

    d = i.uptime/60/60/24;
    h = i.uptime/60/60%24;
    m = i.uptime/60%60;

    // Only print fields if they aren't '0'.
    if (d^0) printf("%dd ", d);
    if (h^0) printf("%dh ", h);
    if (m^0) printf("%dm ", m);

    printf("\n");
    return 0;
}
