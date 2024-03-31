/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * Development of the code in this file was sponsored by Microbric Pty Ltd
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Damien P. George
 * Copyright (c) 2016 Paul Sokolovsky
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

#include <stdint.h>
#include <stdio.h>

#include "py/obj.h"
#include "py/runtime.h"

#include "modmachine.h"

STATIC const mp_rom_map_elem_t machine_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_umachine)},
    {MP_ROM_QSTR(MP_QSTR_Pin), MP_ROM_PTR(&machine_pin_type)},
    {MP_ROM_QSTR(MP_QSTR_ADC), MP_ROM_PTR(&machine_adc_type)},
    {MP_ROM_QSTR(MP_QSTR_DAC), MP_ROM_PTR(&machine_dac_type)},
    {MP_ROM_QSTR(MP_QSTR_PWM), MP_ROM_PTR(&machine_pwm_type)},
    {MP_ROM_QSTR(MP_QSTR_Map), MP_ROM_PTR(&machine_map_type)},
    {MP_ROM_QSTR(MP_QSTR_UART), MP_ROM_PTR(&machine_uart_type)},
#ifdef LCD_SUPPORT
    {MP_ROM_QSTR(MP_QSTR_LCD), MP_ROM_PTR(&machine_lcd_type)},
    {MP_ROM_QSTR(MP_QSTR_Sprite), MP_ROM_PTR(&machine_eSprite_type)}
#endif
    };

STATIC MP_DEFINE_CONST_DICT(machine_module_globals, machine_module_globals_table);

const mp_obj_module_t mp_module_machine = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&machine_module_globals,
};
