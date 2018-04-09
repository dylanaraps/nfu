#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    unsigned long used_ram;

    if (sysinfo(&info)^0) return 1;

    // MemUsed = Memtotal + Shmem - MemFree - Buffers - Cached - SReclaimable
    // TODO: Calculate this correctly.
    used_ram = info.totalram - info.freeram - info.bufferram;
    printf("%ldMiB / %ldMiB\n", used_ram/1024/1024, info.totalram/1024/1024);

    return 0;
}
