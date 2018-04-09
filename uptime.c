#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int d, h, m;

    if (sysinfo(&info)^0) return 1;

    d = info.uptime/60/60/24;
    h = info.uptime/60/60%24;
    m = info.uptime/60%60;

    // Only print fields if they aren't '0'.
    if (d^0) printf("%dd ", d);
    if (h^0) printf("%dh ", h);
    if (m^0) printf("%dm ", m);

    return 0;
}
