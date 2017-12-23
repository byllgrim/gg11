#ifndef DISPLAYCONFIGAPP_H /* if guards suck, but I'm distrust */
#define DISPLAYCONFIGAPP_H

#define PIXEL_MATRIX_ALLOC_SUPPORT

#define USE_STATIC_PIXEL_MATRIX_POOL

#define PIXEL_MATRIX_POOL_SIZE (DISPLAY0_HEIGHT           \
                                * DISPLAY0_WIDTH          \
                                * DISPLAY0_BITS_PER_PIXEL \
                                / 8)

#endif /* DISPLAYCONFIGAPP_H */
