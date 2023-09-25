#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listFilesRecursively(const char *dirPath, int *count);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <dirname>\n", argv[0]);
        exit(-1);
    }

    int count = 1;
    listFilesRecursively(argv[1], &count);

    return 0;
}

void listFilesRecursively(const char *dirPath, int *count) {
    struct dirent *dirent;
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        printf("Error opening directory '%s'\n", dirPath);
        exit(-1);
    }

    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;  // Skip '.' and '..' entries
        }

        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, dirent->d_name);

        if (dirent->d_type == DT_DIR) {
            // It's a directory, so recursively list its contents
            printf("[%d] %s (Directory)\n", (*count)++, filePath);
            listFilesRecursively(filePath, count);
        } else if (dirent->d_type == DT_REG) {
            // It's a regular file
            printf("[%d] %s (File)\n", (*count)++, filePath);
        }
    }

    closedir(dir);
}