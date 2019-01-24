#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct dirent *de;
    char path[] = "/sys/class/backlight/";
    DIR *dr = opendir(path);
    int i = 0;

    if (!dr) return 1;

    while ((de = readdir(dr)) != NULL) {
        char full_path[256] = "";
        int perc;

        // Construct the file path.
        strncat(full_path, path, strlen(path));
        strncat(full_path, de->d_name, strlen(de->d_name));
        strncat(full_path, "/brightness", 12);

        FILE *f = fopen(full_path, "r");
        if (!f) continue;

        fscanf(f, "%d", &perc);
        fclose(f);

        printf("%s%d: %d%%\n", "BRI", i++, perc/10+1);
    }

    closedir(dr);
    return 0;
}
