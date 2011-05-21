
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "common.h"

#define DEBUG 0
#if DEBUG
#endif

int display_jpeg(char *filename, fb_info fb_inf)
{

	fb_info original_jpeg;	  /* original size */
	fb_info new_jpeg;

	new_jpeg = fb_inf; 		  /* screen size */
	
	u8_t *buf24 = decode_jpeg(filename, &original_jpeg);
	u8_t * scale_buf = scale24(buf24, new_jpeg, original_jpeg);
	u32_t *buf32 = rgb24to32(scale_buf, new_jpeg);

	int i = 0, j = 0, k = 0,m = 0, n = 0;
    #if 1
	for(i = 0; i < new_jpeg.h; ++i){
		for (j = 0; j < new_jpeg.w; ++j){
			fb_pixel(fb_inf, j, i, buf32[j + i * new_jpeg.w]);
		}
	}
    #endif
    #if 0
	for(i = 0; i < new_jpeg.w; ++i){
		for (j = new_jpeg.h - 1; j >= 0; --j){
			fb_pixel(fb_inf, i, j, buf32[i + j * new_jpeg.w]);
		}
        usleep(1000);
	}
    #endif
    #if 0 
	for(i = 0 , k = new_jpeg.w; i <= new_jpeg.w/2; ++i ,--k){
		for (j = new_jpeg.h - 1; j >= 0; --j){
			fb_pixel(fb_inf, i, j, buf32[i + j * new_jpeg.w]);

			fb_pixel(fb_inf, k, j, buf32[k + j * new_jpeg.w]);
		}
        usleep(1000);
	}

    #endif
    #if 0
    m = new_jpeg.h;
    while(m >0){
    for(i = 0, j = m - 1; j < new_jpeg.h; i++, j++)
    {
        fb_pixel(fb_inf, i, j, buf32[i + j * new_jpeg.w]);
    }
        usleep(1000);
        m--;
    }
    m = new_jpeg.h;
    while(m >= 0){
	for(i = n, j = 0; j < m; ++i, ++j){
		fb_pixel(fb_inf, i, j, buf32[i + j * new_jpeg.w]);
        
	}
    usleep(1000);
  //  if(j == 0)
        n++;
    if(i == new_jpeg.w)
        m--;
    }
    //for(i = 0, j = 0; j < new_jpeg.h; ++i, ++j)
    //{
      //  fb_pixel(fb_inf, i, j, buf32[i + j * new_jpeg.w]);
   // }
    #endif
	free(buf24);
	free(scale_buf);
	free(buf32);
	
	return 0;
}
