#ifndef _GIF_FFMPEG_
#define _GIF_FFMPEG_

#include <stdio.h>  

#define __STDC_CONSTANT_MACROS  


#ifndef INT64_C
#define INT64_C
#define UINT64_C
#endif

#ifdef _WIN32  
//Windows  
extern "C"
{
#include "libavcodec/avcodec.h"  
#include "libavformat/avformat.h"  
#include "libswscale/swscale.h"  
};
#else  
//Linux...  
#ifdef __cplusplus  
extern "C"
{
#endif  
#include <libavcodec/avcodec.h>  
#include <libavformat/avformat.h>  
#include <libswscale/swscale.h>  

#ifdef _STDINT_H
#undef _STDINT_H
#endif
#include <stdint.h>

#ifdef __cplusplus  
};
#endif  
#endif  

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


//int gif2Mats(const string &filePath, vector<Mat> &frames);


#endif
