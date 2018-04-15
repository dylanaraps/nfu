#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

int main() {
    Display *dpy = XOpenDisplay(NULL);
    Window root = RootWindow(dpy, 0);
    XRRScreenConfiguration *conf = XRRGetScreenInfo(dpy, root);

    printf("%dhz\n", XRRConfigCurrentRate(conf));
    return 0;
}
