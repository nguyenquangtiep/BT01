#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9000); 

    // if (connect(client, (struct sockaddr *)&addr, sizeof(addr))) {
    //     perror("connect() failed");
    //     return 1;
    // }

    char computer[64];
    char disk[2];
    short int disk_len, num_disk;
    char disk_list[1024];

    char buf[1024];

    while(1) {
        printf("Nhap thong tin may tinh.\n");
        printf("Nhap ten may: ");
        scanf("%s", computer);

        if (strncmp(computer, "0000", 4) == 0)
            break;

        getchar();

        printf("Nhap so o dia: ");
        scanf("%hd", &num_disk);

        int i;
        for (i = 1; i <= num_disk; i++) {
            printf("Nhap ten o: ");
            fgets(disk, sizeof(disk), stdin);

            disk[strlen(disk) - 1] = 0;

            strcat(disk_list, disk);
            strcat(disk_list, " ");

            printf("Nhap kich thuoc o dia: ");
            scanf("%hd", &disk_len);
            getchar();

            strcat(disk_list, itof(disk_len));
            strcat(disk_list, " ");
        }

        // sprintf(buf, "%s %s %s %.2f", computer, num_disk, , dtb);
        printf("%s\n", disk_list);

        // send(client, buf, strlen(buf), 0);   
    }
    
    return 0;
}