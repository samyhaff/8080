#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;    
    if ((fp = fopen("test", "r")) == NULL) {
        printf("failed to read rom\n");
        exit(0);
    }
    printf("%c", getc(fp));
    printf("%c", getc(fp));
return 0;
}
