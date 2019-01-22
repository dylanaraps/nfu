#include <stdio.h>
#include <X11/Xlib.h>

int main() {
    Display* d = XOpenDisplay(NULL);
    Screen*  s = DefaultScreenOfDisplay(d);

    printf("%dx%d\n", s->width, s->height);
    return 0;
}
