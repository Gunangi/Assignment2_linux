#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    openlog(NULL, 0, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
        return 1;
    }

    const char *file_path = argv[1];
    const char *write_str = argv[2];

    FILE *fp = fopen(file_path, "w");
    if (!fp) {
        syslog(LOG_ERR, "Error opening file: %s", file_path);
        return 1;
    }

    fprintf(fp, "%s", write_str);
    fclose(fp);

    syslog(LOG_DEBUG, "Writing %s to %s", write_str, file_path);
    closelog();
    return 0;
}
