#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define FB_DEV "/dev/fb0"

typedef struct fb_info
{
	int fd;
	struct fb_var_screeninfo fb_var;
	int w;
	int h;
	int bpp;
	void * fb_mem;
	int fb_len;
}fb_info_t, *pfb_info_t;

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned int u32_t;

int fb32_draw_font(pfb_info_t pfb, int x, int y, int ch, u32_t color)
{
    
	//step 1. get ascii code with toascii()
	

	//step 2. get the index of charactor 'E' in font_8X16[]


	//step 3. according to every bit of the 'E' draw the pixel in fb
	

}

int main()
{
	int fd;
	fb_info_t fbi;
	fd = open(FB_DEV, O_RDWR);
	if(fd < 0)
	{
		perror("open /dev/fb0 error:");
		exit(1);
	}
	
	/* get framebuffer info*/	
	if(-1L == ioctl(fd, FBIOGET_VSCREENINFO, &(fbi.fb_var)))
	{
		perror("ioctl error:");
		exit(1);
	}
	fbi.w = fbi.fb_var.w;
	fbi.h = fbi.fb_var.h;
	fbi.bpp = fbi.fb_var.bits_per_pixel;
	fbi.fb_len = fbi.w * fbi.h * fbi.bpp / 8;
	fbi.fd = fd;

	fbi.fb_mem = mmap(NULL, fbi.fb_len, PROT_READ | PROT_WRITE, 
				MAP_SHARED, fbi.fd, 0);
	if(fbi.fb_mem == MAP_FAILED)
	{
		perror("mmap file error:");
		exit(1);
	}
	close(fbi.fd);

	//在屏幕正中心打印字符'E'的字模
	fb32_draw_font(&fbi, 512, 384, 'E', 0xFF00);

	munmap(fbi.fb_mem, fbi.fb_len);
	
	return 0;
}
	
