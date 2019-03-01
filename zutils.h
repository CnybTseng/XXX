#ifndef _ZUTILS_H_
#define _ZUTILS_H_

#ifdef __cplusplus
extern "C"
{
#endif

void mmfree(int n, ...);
void mset(char *const X, size_t size, const char *const val, int nvals);
void mcopy(const char *const X, char *const Y, size_t size);
void save_volume(float *data, int width, int height, int nchannels, const char *path);
void nchw_to_nhwc_quad(const float *const input, float *const output, int width, int height, int channels, int batch);

#ifdef __cplusplus
}
#endif

#endif