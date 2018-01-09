#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/uio.h>
#include <string.h>
#include <errno.h>
#include <sys/un.h>

int main_c(int argc, char * argv[])
{
    char name[] = "/var/tmp/client";
    char servername[] = "/home/user/opend";
    int fd, cfd;
    int len;
    int ret;

    struct sockaddr_un un, uc;

    fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if(fd < 0)
    {
        printf("socket failed: %d, %s\n", errno, strerror(errno));
        return errno;
    }

    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    sprintf(un.sun_path, "%s", name);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    unlink(un.sun_path);

    ret = bind(fd, (struct sockaddr *)&un, len);
    if(ret < 0)
    {
        printf("bind failed: %d, %s, (%s)\n", errno, strerror(errno), un.sun_path);
        return errno;
    }

    while(1)
    {
        memset(&uc, 0, sizeof(uc));
        len = sizeof(uc);
        uc.sun_family = AF_UNIX;
        //sprintf(un.sun_path, "%s", "/home/user/opend");
        strcpy(uc.sun_path, servername);
        //len = offsetof(struct sockaddr_un, sun_path) + strlen(servername);

        cfd = connect(fd, (struct sockaddr *)&uc, len);

        if(cfd < 0)
        {
            printf("connect failed: %d, %s\n", errno, strerror(errno));
            return errno;
        }
    }
	printf("Hello Server\n");

	return 0;
}
