#include <stdio.h>

#include "get_next_line.h"

int main() {
    char *a = malloc(1000);

    ft_memset(a, 0, 1000);

    int b = open("/Users/avarys/CLionProjects/gnl/test.txt", O_RDONLY);

    while (get_next_line(b, &a) > 0) {
        write(1, a, ft_strlen(a));
    }
    write(1, a, ft_strlen(a));
    free(a);
    return 0;


}
