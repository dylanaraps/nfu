#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct dirent *de;
    char path[256] = "/sys/class/backlight/";
    DIR *dr = opendir(path);
    int i = 0;

    if (!dr) return 1;

    while ((de = readdir(dr)) != NULL) {
        char full_path[256] = "";
        int perc;

        // Construct the file path.
        strcat(full_path, path);
        strcat(full_path, de->d_name);
        strcat(full_path, "/brightness");

        FILE *f = fopen(full_path, "r");
        if (!f) continue;

        fscanf(f, "%d", &perc);
        fclose(f);

        printf("%s%d: %d%%\n", "BRI", i++, perc/10+1);
    }

    closedir(dr);
    return 0;
}
