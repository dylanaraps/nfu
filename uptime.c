#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    int d, h, m;

    if (sysinfo(&info) != 0)
        return 1;

    d = info.uptime / 60 / 60 / 24;
    h = info.uptime / 60 / 60 % 24;
    m = info.uptime / 60 % 60;

    // Only print fields if they aren't '0'.
    if (d != 0)
        printf("%d%s ", d, "d");

    if (h != 0)
        printf("%d%s ", h, "h");

    if (m != 0)
        printf("%d%s", m, "m");

    return 0;
}
