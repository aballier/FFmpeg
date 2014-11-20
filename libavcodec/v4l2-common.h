/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_V4L2_COMMON_H
#define AVCODEC_V4L2_COMMON_H

#undef __STRICT_ANSI__ //workaround due to broken kernel headers
#include "config.h"
#if HAVE_SYS_VIDEOIO_H
#include <sys/videoio.h>
#else
#if HAVE_ASM_TYPES_H
#include <asm/types.h>
#endif
#include <linux/videodev2.h>
#endif
#include "libavutil/pixfmt.h"
#include "libavcodec/avcodec.h"

/* for v4l_fmt_map.pack_flags */
#define FF_V4L_PACK_AVPACKET (1 << 0)
#define FF_V4L_PACK_AVFRAME  (1 << 1)

struct v4l_fmt_map {
    enum AVPixelFormat ff_fmt;
    enum AVCodecID codec_id;
    uint32_t v4l2_fmt;
    int pack_flags;
};

extern const struct v4l_fmt_map avpriv_v4l_fmt_conversion_table[];

uint32_t avpriv_v4l_fmt_ff2v4l(enum AVPixelFormat pix_fmt, enum AVCodecID codec_id, int pack_flags);
enum AVPixelFormat avpriv_v4l_fmt_v4l2ff(uint32_t v4l2_fmt, enum AVCodecID codec_id);
enum AVCodecID avpriv_v4l_fmt_v4l2codec(uint32_t v4l2_fmt);

#endif /* AVCODEC_V4L2_COMMON_H */