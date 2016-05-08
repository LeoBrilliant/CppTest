/*
 * MmapTest.h
 *
 *  Created on: 2016��5��8��
 *      Author: LeoBrilliant
 */

#ifndef MMAPTEST_H_
#define MMAPTEST_H_

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void mmap_test()
{
	int fdin, fdout;
	void *src, *dst;
	struct stat statbuf;

	char filesrc[] = "infile";
	char filedst[] = "outfile";
	char errmsg[1024];
	if((fdin = open(filesrc, O_RDONLY)) < 0)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "can't open %s for reading\n", filesrc);
		perror(errmsg);
	}

	if((fdout = open(filedst, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "can't open %s for writing\n", filedst);
		perror(errmsg);
	}

	if(fstat(fdin, &statbuf) < 0)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "fstat error");
		perror(errmsg);
	}

	if(lseek(fdout, statbuf.st_size - 1, SEEK_SET) == -1)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "lseek error");
		perror(errmsg);
	}

	if(write(fdout, "", 1) != 1)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "write error");
		perror(errmsg);
	}

	if((src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0)) == MAP_FAILED)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "mmap error for input");
		perror(errmsg);
	}

	if((dst = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == MAP_FAILED)
	{
		memset(errmsg, 0,1024);
		sprintf(errmsg, "mmap error for output");
		perror(errmsg);
	}

	memcpy(dst, src, statbuf.st_size);

	return;
}



#endif /* MMAPTEST_H_ */
