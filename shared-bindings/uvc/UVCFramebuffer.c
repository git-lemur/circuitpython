/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2024 Jeff Epler for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/obj.h"
#include "py/objproperty.h"

#include "shared-bindings/uvc/__init__.h"
#include "shared-bindings/uvc/UVCFramebuffer.h"
#include "shared-module/displayio/__init__.h"
#include "shared-module/framebufferio/FramebufferDisplay.h"
#include "shared-module/framebufferio/__init__.h"
#include "shared-module/uvc/__init__.h"
#include "shared-module/uvc/UVCFramebuffer.h"
#include "shared-bindings/util.h"

static void check_for_deinit(uvc_uvcframebuffer_obj_t *self) {
    if (!shared_module_uvc_uvcframebuffer_get_width(self)) {
        raise_deinited_error();
    }
}

//| class UVCFramebuffer:
//|     """Displays to a USB connected computer using the UVC protocol"""
//|
//|     def __new__(self):
//|         """Returns the singleton UVC framebuffer object, if UVC is enabled"""
//
//|     def refresh(self) -> None:
//|         """Transmits the color data in the buffer to the pixels so that
//|         they are shown."""
//|         ...
STATIC mp_obj_t uvc_uvcframebuffer_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    static const mp_arg_t allowed_args[] = {};
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);
    uvc_uvcframebuffer_obj_t *self = &uvc_uvcframebuffer_singleton_obj;
    return self;
}

STATIC mp_obj_t uvc_uvcframebuffer_refresh(mp_obj_t self_in) {
    uvc_uvcframebuffer_obj_t *self = (uvc_uvcframebuffer_obj_t *)self_in;
    check_for_deinit(self);
    shared_module_uvc_uvcframebuffer_refresh(self);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(uvc_uvcframebuffer_refresh_obj, uvc_uvcframebuffer_refresh);

//|     width: int
//|     """The width of the display, in pixels"""
STATIC mp_obj_t uvc_uvcframebuffer_get_width(mp_obj_t self_in) {
    uvc_uvcframebuffer_obj_t *self = (uvc_uvcframebuffer_obj_t *)self_in;
    check_for_deinit(self);
    return MP_OBJ_NEW_SMALL_INT(shared_module_uvc_uvcframebuffer_get_width(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(uvc_uvcframebuffer_get_width_obj, uvc_uvcframebuffer_get_width);
MP_PROPERTY_GETTER(uvc_uvcframebuffer_width_obj,
    (mp_obj_t)&uvc_uvcframebuffer_get_width_obj);

//|     height: int
//|     """The height of the display, in pixels"""
//|
STATIC mp_obj_t uvc_uvcframebuffer_get_height(mp_obj_t self_in) {
    uvc_uvcframebuffer_obj_t *self = (uvc_uvcframebuffer_obj_t *)self_in;
    check_for_deinit(self);
    return MP_OBJ_NEW_SMALL_INT(shared_module_uvc_uvcframebuffer_get_height(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(uvc_uvcframebuffer_get_height_obj, uvc_uvcframebuffer_get_height);

MP_PROPERTY_GETTER(uvc_uvcframebuffer_height_obj,
    (mp_obj_t)&uvc_uvcframebuffer_get_height_obj);

STATIC const mp_rom_map_elem_t uvc_uvcframebuffer_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_refresh), MP_ROM_PTR(&uvc_uvcframebuffer_refresh_obj) },
    { MP_ROM_QSTR(MP_QSTR_width), MP_ROM_PTR(&uvc_uvcframebuffer_width_obj) },
    { MP_ROM_QSTR(MP_QSTR_height), MP_ROM_PTR(&uvc_uvcframebuffer_height_obj) },
};
STATIC MP_DEFINE_CONST_DICT(uvc_uvcframebuffer_locals_dict, uvc_uvcframebuffer_locals_dict_table);

STATIC void uvc_uvcframebuffer_get_bufinfo(mp_obj_t self_in, mp_buffer_info_t *bufinfo) {
    shared_module_uvc_uvcframebuffer_get_bufinfo(self_in, bufinfo);
}

// These version exists so that the prototype matches the protocol,
// avoiding a type cast that can hide errors
STATIC void uvc_uvcframebuffer_swapbuffers(mp_obj_t self_in, uint8_t *dirty_row_bitmap) {
    (void)dirty_row_bitmap;
    shared_module_uvc_uvcframebuffer_refresh(self_in);
}

STATIC void uvc_uvcframebuffer_deinit_proto(mp_obj_t self_in) {
    /* NOTHING */
}

STATIC int uvc_uvcframebuffer_get_width_proto(mp_obj_t self_in) {
    return shared_module_uvc_uvcframebuffer_get_width(self_in);
}

STATIC int uvc_uvcframebuffer_get_height_proto(mp_obj_t self_in) {
    return shared_module_uvc_uvcframebuffer_get_height(self_in);
}

STATIC int uvc_uvcframebuffer_get_native_frames_per_second_proto(mp_obj_t self_in) {
    return 10;
}

STATIC bool uvc_uvcframebuffer_get_reverse_pixels_in_word_proto(mp_obj_t self_in) {
    return true;
}


STATIC const framebuffer_p_t uvc_uvcframebuffer_proto = {
    MP_PROTO_IMPLEMENT(MP_QSTR_protocol_framebuffer)
    .get_bufinfo = uvc_uvcframebuffer_get_bufinfo,
    .get_width = uvc_uvcframebuffer_get_width_proto,
    .get_height = uvc_uvcframebuffer_get_height_proto,
    .get_native_frames_per_second = uvc_uvcframebuffer_get_native_frames_per_second_proto,
    .swapbuffers = uvc_uvcframebuffer_swapbuffers,
    .deinit = uvc_uvcframebuffer_deinit_proto,
    .get_reverse_pixels_in_word = uvc_uvcframebuffer_get_reverse_pixels_in_word_proto,
};

STATIC mp_int_t uvc_uvcframebuffer_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags) {
    shared_module_uvc_uvcframebuffer_get_bufinfo(self_in, bufinfo);
    bufinfo->typecode = 'H';
    return 0;
}

MP_DEFINE_CONST_OBJ_TYPE(
    uvc_UVCFramebuffer_type,
    MP_QSTR_UVCFramebuffer,
    MP_TYPE_FLAG_HAS_SPECIAL_ACCESSORS,
    locals_dict, &uvc_uvcframebuffer_locals_dict,
    make_new, uvc_uvcframebuffer_make_new,
    buffer, uvc_uvcframebuffer_get_buffer,
    protocol, &uvc_uvcframebuffer_proto
    );
