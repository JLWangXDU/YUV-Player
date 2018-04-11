/**
 * @file   yuv2rgb.h
 * @author Late Lee
 * @date   2012.01.20
 * 
 * @brief  
 *         YUV422P/YUV420P/YUV422SPתRGB24ʵ�ִ���
 *
 * @note
 *         1����Windows�������
 *         2��������ʹ�õ�YUV420P��YUV422P��ƽ��(planar)��ʽ�����Ǵ��(packed)��ʽ
 *
 *         3��qcif: 176*144
              cif: 352*288
 * @todo  ȷ����RGB���򵽵���ʲô
 *
 * @log   2013-10-26 �ο�422p������ʵ��422spת��422p��ʽ����������ʼ���ӿ����أ������⹫��
 *        2014-02-10 ��װͳһһ��������
 *        2014-08-03 ����YUVתRGB���������UYVY��ʽ�ӿڡ�
 *        2014-08-04 ���422�����ʽ�Ľӿڡ�4�ָ�ʽ����ͨ���� ���YUV444��ʽ�� SP��P��ת�ӿڡ�
 *        2014-08-05 ���422SP��420SP��ʽ��ת���������ʽʹ�ò����
 *        2014-08-06 Yת��RGB
 *
 * �ʼǣ�
            ÿ��Y��U��V��R��G��B��ռ��1���ֽ�
            YUV422Pƽ���ʽ
            Y��U��V�ֿ��洢��Yռw*h��U��V�ֱ�ռw*h/2��ÿ��Y��w����U��V��w/2����
            ����Y����һ��U��V������������Y����2����U��V������һ������4�ֽڣ����һ������ռ2�ֽڡ�

            �ڴ�ֲ����£�
                    w
            +--------------------+
            |Y0Y1Y2Y3...         |
            |...                 |   h
            |...                 |
            |                    |
            +--------------------+
            |U0U1      |
            |...       |   h
            |...       |
            |          |
            +----------+
            |V0V1      |
            |...       |  h
            |...       |
            |          |
            +----------+
                w/2

            ��һ�����أ�Y0 U0 V0
            �ڶ������أ�Y1 U0 V0
            ���������أ�Y2 U1 V1
            ���ĸ����أ�Y3 U1 V1

			ÿ�ָ�ʽ�ֲ���ת��������
 */

#ifndef _YUV2RGB_H_
#define _YUV2RGB_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    FMT_Y = 0,
    FMT_YUV420 = 1,
    FMT_YV12 = 2,
    FMT_YUV422 = 3,
    FMT_YV16 = 4,
    FMT_YUV444 = 5,
    FMT_YUYV = 6,
    FMT_YVYU = 7,
    FMT_UYVY = 8,
    FMT_VYUY = 9,
    FMT_NV12 = 10,
    FMT_NV21 = 11,
    FMT_NV16 = 12,
    FMT_NV61 = 13,
    FMT_RGB24 = 14,
    FMT_BGR24 = 15,
}YUV_TYPE;

/** 
 * @brief YUVתRGB24(���)
 * 
 * @param type       YUV��ʽ���� ֧�ָ�ʽ��YUV_TYPE����
 * @param yuvbuffer  YUV��ʽ������
 * @param rgbbuffer  RGB24��ʽ������
 * @param width      ͼ���
 * @param height     ͼ���
 *
 * @return 0: OK -1: failed
 *
 * @note
 *        1��YUV422 buffer: w * h * 2 YUV420 buffer: w * h * 3 / 2
 *        2��rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 *        3����ת����ں���
 */
int yuv_to_rgb24(YUV_TYPE type, unsigned char* yuvbuffer,unsigned char* rgbbuffer, int width, int height);

/**
 * @brief  YUV422Pת��ΪRGB24(���)
 * 
 * @param  type[IN]          YUV��ʽ����
 * @param  yuvbuffer[IN]    YUV422Pƽ���ʽ������
 * @param  rgbbuffer[OUT]   RGB������
 * @param  width[IN]        ͼ���
 * @param  height[IN]       ͼ���
 * 
 * @return no
 *
 * @note
 *         1.YUV422P��ʽYUV��������СΪw * h * 2
 *         2.rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 */
void yuv422p_to_rgb24(YUV_TYPE type, unsigned char* yuvbuffer, unsigned char* rgbbuffer, int width, int height);

/**
 * @brief  YUV422P�����ʽת��ΪRGB24(���)
 * 
 * @param  type[IN]         YUV��ʽ����
 * @param  yuvbuffer[IN]    YUV422P�����ʽ������
 * @param  rgbbuffer[OUT]   RGB������
 * @param  width[IN]        ͼ���
 * @param  height[IN]       ͼ���
 * 
 * @return no
 *
 * @note
 *         1.YUV422P��ʽYUV��������СΪw * h * 2��֧��YUYV��YVYU��UYVY��VYUY
 *         2.rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 */
void yuv422packed_to_rgb24(YUV_TYPE type, unsigned char *yuv, unsigned char *rgb, int width, int height);

/** 
 * @brief YUV422SPתRGB24(���)
 *
 * @param type[IN]   YUV��ʽ����
 * @param yuvbuffer  YUV422SP��ʽ������
 * @param rgbbuffer  RGB24��ʽ������
 * @param width      ͼ���
 * @param height     ͼ���
 *
 *
 * @note
 *        1��YUV422SP��ʽYUV��������СΪw * h * 2��֧��NV16��NV61
 *        2��rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 */
void yuv422sp_to_rgb24(YUV_TYPE type, unsigned char* yuvbuffer, unsigned char* rgbbuffer, int width, int height);

/** 
 * @brief YUV420PתRGB24(���)
 * 
 * @param type[IN]   YUV��ʽ����
 * @param yuvbuffer  YUV420P��ʽ������
 * @param rgbbuffer  RGB24��ʽ������
 * @param width      ͼ���
 * @param height     ͼ���
 *
 *
 * @note
 *        1��YUV420P��ʽYUV��������СΪw * h * 3 / 2
 *        2��rgbbuffer��������ΪRGB���籣��BMP����Ҫ����ΪBGR
 */
void yuv420p_to_rgb24(YUV_TYPE type, unsigned char* yuvbuffer,unsigned char* rgbbuffer, int width, int height);

void yuv420sp_to_rgb24(YUV_TYPE type, unsigned char* yuvbuffer,unsigned char* rgbbuffer, int width,int height) ;
//void yuv420sp_to_rgb24(YUV_TYPE type, unsigned char* yuv420sp, unsigned char* yuv420p, int width, int height);

////////////////////////////////////////////////////////////////////////////////////////////////////
void yuv422p_to_yuv422sp(YUV_TYPE type, unsigned char* yuv422p, unsigned char* yuv422sp, int width, int height);
void yuv422sp_to_yuv422p(YUV_TYPE type, unsigned char* yuv422sp, unsigned char* yuv422p, int width, int height);
void yuv420p_to_yuv420sp(YUV_TYPE type, unsigned char* yuv420p, unsigned char* yuv420sp, int width, int height);
void yuv420sp_to_yuv420p(YUV_TYPE type, unsigned char* yuv420sp, unsigned char* yuv420p, int width, int height);
void yuv422p_to_yuv422packed(YUV_TYPE type1, YUV_TYPE type2, unsigned char* yuv422p, unsigned char* yuv, int width, int height);
void yuv422packed_to_yuv422p(YUV_TYPE type1, YUV_TYPE type2, unsigned char* yuv422p, unsigned char* yuv, int width, int height);

void yu_to_yv(YUV_TYPE type, unsigned char* yu, unsigned char* yv, int width, int height);
void yv_to_yu(YUV_TYPE type, unsigned char* yuv420sp, unsigned char* yuv420p, int width, int height);

////////////////////////////////////////////////////////////////////////////////////////////////////
void swaprgb(unsigned char* rgb, int len);

////////////////////////////////////////////////////////////////////////////////////////////////////
void yuv420_to_rgb24_1(unsigned char* yuv420, unsigned char* rgb, int width, int height);

void yuv420_to_rgb24_2(unsigned char *yuv420, unsigned char *rgb24, int width, int height) ;

void yuv420_to_rgb24_3(unsigned char* yuv, unsigned char* rgb, int width, int height);

void yuv4444_to_rgb24(unsigned char *yuv, unsigned char *rgb, int width, int height);

// �������10��������
void save_yuv_file(const char* filename, int width, int height, int type);

void change_yuv_file(const char* filename, const char* file_out, int width, int height, int type);

#ifdef __cplusplus
}
#endif

#endif /* _YUV2RGB_H_ */