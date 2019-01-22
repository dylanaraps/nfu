#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf("%dx%d\n", w.ws_row, w.ws_col);
    return 0;
}
