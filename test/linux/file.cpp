#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
    int  fd1 = open("./src_file.txt",  O_RDONLY);
    if(fd1 < 0 ){
        return fd1;
    }
    printf("fd1 = [%d]", fd1);

    int  fd2 = open("./dest_file",O_WRONLY | O_CREAT | O_EXCL, S_IRWXU | S_IRGRP | S_IROTH);
    if(fd2< 0 ){
        return fd1;
    }
    printf("fd1 = [%d]", fd2);
    char buffer[1024]; 
    int off_t  = lseek(fd1,500, SEEK_SET);
    lseek(fd2, 500, SEEK_SET);
    int rea = read(fd1,buffer,500);
    if (rea < 0){
        return -1;
    }
    printf("buffer = %s/n",buffer);
    int writ = write(fd2,buffer,500);
    if(writ < 0){
        return -1;
    }
    close(fd1);
    close(fd2);
    return  0;
}


// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// int main(void)
// {
// char buffer[1024];
// int fd1, fd2;
// int ret;
// /* �� src_file �ļ� */
// fd1 = open("./src_file.txt", O_RDONLY);
// if (-1 == fd1) {
// printf("Error: open src_file failed!\n");
// return -1;
// }
// /* �½� dest_file �ļ����� */
// fd2 = open("./dest_file", O_WRONLY | O_CREAT | O_EXCL,
// S_IRWXU | S_IRGRP | S_IROTH);
// if (-1 == fd2) {
// printf("Error: open dest_file failed!\n");
// ret = -1;
// goto err1;
// }
// /* �� src_file �ļ���дλ���ƶ���ƫ���ļ�ͷ 500 ���ֽڴ� */
// ret = lseek(fd1, 500, SEEK_SET);
// if (-1 == ret)
// goto err2;
// /* ��ȡ src_file �ļ����ݣ���С 1KByte */
// ret = read(fd1, buffer, sizeof(buffer));
// if (-1 == ret) {
// printf("Error: read src_file filed!\n");
// goto err2;
// }
// /* �� dest_file �ļ���дλ���ƶ����ļ�ͷ */
// ret = lseek(fd2, 0, SEEK_SET);
// if (-1 == ret)
// goto err2;
// /* �� buffer �е�����д�� dest_file �ļ�����С 1KByte */
// ret = write(fd2, buffer, sizeof(buffer));
// if (-1 == ret) {
// printf("Error: write dest_file failed!\n");
// goto err2;
// }
// printf("OK: test successful\n");
// ret = 0;
// err2:
// close(fd2);
// err1:
// close(fd1);
// return ret;
// }

