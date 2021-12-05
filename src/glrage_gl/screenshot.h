#pragma once

#include "glrage_gl/gl_core_3_3.h"

#ifdef __cplusplus
extern "C" {
    #include <cstdbool>
#else
    #include <stdbool.h>
#endif

bool GLRage_Screenshot_CaptureToFile(const char *path);

void GLRage_Screenshot_CaptureToBuffer(
    uint8_t *out_buffer, GLint *out_width, GLint *out_height, GLint depth,
    GLenum format, GLenum type, bool vflip, bool front_buffer);

#ifdef __cplusplus
}
#endif