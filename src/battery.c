#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct dirent *de;
    char path[256] = "/sys/class/power_supply/";
    DIR *dr = opendir(path);

    if (!dr) return 1;

    while ((de = readdir(dr)) != NULL) {
        char full_path[256] = "";
        int perc;

        // Construct the file path.
        strcat(full_path, path);
        strcat(full_path, de->d_name);
        strcat(full_path, "/capacity");

        FILE *f = fopen(full_path, "r");
        if (!f) continue;

        fscanf(f, "%d", &perc);
        fclose(f);

        printf("%s: %d%%\n", de->d_name, perc);
    }

    closedir(dr);
    return 0;
}
