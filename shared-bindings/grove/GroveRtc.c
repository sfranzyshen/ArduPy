/**
 * The MIT License (MIT)
 *
 * Author: PowerfulCat (x4495@outlook.com)
 *
 * Copyright (C) 2019  Seeed Technology Co.,Ltd.
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

#include "shared-bindings/util.h"
#include "shared-bindings/microcontroller/Pin.h"
#include "common-hal/grove/GroveRtc.h"

extern const mp_obj_type_t grove_rtc_type;

m_generic_make(rtc){
    abstract_module_t * self = new_abstruct_module(type);
    assert_scl_sda(n_args);
    common_hal_rtc_construct(self);
    return self;
}

mp_obj_t rtc_start(mp_obj_t self_in){
    common_hal_rtc_start((abstract_module_t *)self_in);
    return mp_const_none;
}

mp_obj_t rtc_stop(mp_obj_t self_in){
    common_hal_rtc_stop((abstract_module_t *)self_in);
    return mp_const_none;
}

void rtc_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest){
    extern const mp_obj_type_t grove_datetime_type;
    abstract_module_t * self = (abstract_module_t *)self_in;
    datetime_obj_t    * time;

    if (attr != MP_QSTR_datetime){
        generic_method_lookup(self_in, attr, dest);
    }
    else if (dest[0] != MP_OBJ_NULL){
        dest[0] = MP_OBJ_NULL;
        time = (datetime_obj_t *)dest[1];
        common_hal_rtc_set_datetime(self, &time->data);
    }
    else{
        dest[0] = time = m_new_obj(datetime_obj_t);
        time->base.type = &grove_datetime_type;
        common_hal_rtc_get_datetime(self, &time->data);
    }
}

MP_DEFINE_CONST_FUN_OBJ_1(rtc_start_obj, rtc_start);
MP_DEFINE_CONST_FUN_OBJ_1(rtc_stop_obj, rtc_stop);

const mp_rom_map_elem_t rtc_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&rtc_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&rtc_obj___exit___obj) },
    { MP_ROM_QSTR(MP_QSTR_start),     MP_ROM_PTR(&rtc_start_obj) },
    { MP_ROM_QSTR(MP_QSTR_stop),      MP_ROM_PTR(&rtc_stop_obj) },
};

MP_DEFINE_CONST_DICT(rtc_locals_dict, rtc_locals_dict_table);

const mp_obj_type_t grove_rtc_type = {
    {&mp_type_type},
    .name = MP_QSTR_grove_rtc,
    .make_new = rtc_make_new,
    .locals_dict = (mp_obj_t)&rtc_locals_dict,
    .attr = &rtc_obj_attr,
};