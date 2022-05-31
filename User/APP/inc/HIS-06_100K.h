#ifndef _HIS_06_100K_H
#define _HIS_06_100K_H

#include "GCE_Data_Type.h"
#include "GCE_MCU_Init.h"
/*
北陆湿度传感器HIS-06
下拉100K电阻，并串接1K电阻
10位表
湿度范围20~90  数组下标0代表湿度20%  数组下标70代表湿度90%
*/
// 5摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T5c[] = {
    1,
    1,
    2,
    2,
    3,
    5,
    7,
    9,
    12,
    15,
    19,
    24,
    30,
    36,
    43,
    51,
    61,
    71,
    82,
    95,
    110,
    126,
    143,
    161,
    180,
    201,
    222,
    245,
    269,
    293,
    320,
    346,
    374,
    401,
    429,
    457,
    478,
    511,
    538,
    564,
    590,
    615,
    638,
    661,
    683,
    703,
    723,
    742,
    759,
    776,
    792,
    807,
    821,
    834,
    846,
    857,
    868,
    878,
    887,
    896,
    904,
    912,
    919,
    926,
    932,
    938,
    944,
    949,
    953,
    958,
    962,
};

// 6摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T6c[] = {
    1,
    1,
    2,
    3,
    4,
    6,
    8,
    10,
    13,
    17,
    22,
    27,
    33,
    40,
    47,
    56,
    66,
    77,
    89,
    103,
    118,
    135,
    153,
    173,
    193,
    215,
    237,
    261,
    286,
    311,
    338,
    366,
    394,
    422,
    451,
    479,
    501,
    533,
    560,
    586,
    611,
    635,
    658,
    680,
    701,
    721,
    740,
    758,
    775,
    791,
    806,
    821,
    834,
    846,
    858,
    868,
    879,
    888,
    897,
    905,
    913,
    920,
    927,
    933,
    939,
    944,
    949,
    954,
    958,
    962,
    966,
};

// 7摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T7c[] = {
    1,
    2,
    2,
    3,
    5,
    7,
    9,
    12,
    15,
    19,
    24,
    29,
    36,
    43,
    51,
    61,
    71,
    83,
    96,
    111,
    127,
    145,
    164,
    184,
    205,
    228,
    252,
    276,
    302,
    328,
    356,
    384,
    413,
    442,
    470,
    499,
    523,
    553,
    579,
    605,
    629,
    653,
    676,
    697,
    718,
    737,
    755,
    773,
    789,
    805,
    819,
    833,
    845,
    857,
    868,
    878,
    888,
    896,
    905,
    913,
    920,
    927,
    933,
    939,
    944,
    949,
    954,
    958,
    962,
    966,
    969,
};

// 8摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T8c[] = {
    1,
    2,
    3,
    4,
    6,
    7,
    10,
    13,
    17,
    21,
    26,
    32,
    39,
    47,
    55,
    65,
    77,
    89,
    103,
    118,
    135,
    154,
    174,
    195,
    217,
    241,
    266,
    291,
    317,
    344,
    373,
    402,
    431,
    460,
    489,
    518,
    543,
    572,
    598,
    622,
    647,
    670,
    692,
    713,
    733,
    751,
    769,
    786,
    802,
    817,
    831,
    843,
    855,
    867,
    877,
    887,
    896,
    904,
    912,
    919,
    926,
    932,
    938,
    944,
    949,
    954,
    958,
    962,
    965,
    969,
    972,
};

// 9摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T9c[] = {
    1,
    2,
    3,
    5,
    6,
    9,
    11,
    14,
    18,
    23,
    29,
    35,
    42,
    50,
    60,
    70,
    82,
    95,
    110,
    126,
    144,
    163,
    184,
    206,
    229,
    254,
    279,
    305,
    332,
    360,
    389,
    418,
    448,
    478,
    507,
    535,
    562,
    589,
    615,
    639,
    662,
    685,
    707,
    727,
    746,
    764,
    782,
    798,
    813,
    827,
    841,
    853,
    865,
    875,
    885,
    894,
    903,
    911,
    918,
    925,
    932,
    938,
    943,
    948,
    953,
    957,
    961,
    965,
    969,
    972,
    975,
};

// 10摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T10c[] = {
    2,
    3,
    4,
    5,
    7,
    10,
    13,
    16,
    20,
    25,
    31,
    38,
    46,
    54,
    64,
    75,
    87,
    101,
    117,
    134,
    152,
    172,
    194,
    217,
    241,
    266,
    293,
    320,
    347,
    376,
    405,
    434,
    465,
    495,
    524,
    553,
    580,
    606,
    631,
    654,
    677,
    699,
    720,
    740,
    759,
    777,
    793,
    809,
    824,
    837,
    850,
    862,
    873,
    883,
    892,
    901,
    909,
    917,
    924,
    931,
    937,
    942,
    948,
    952,
    957,
    961,
    965,
    968,
    971,
    974,
    977,
};

// 11摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T11c[] = {
    2,
    3,
    4,
    6,
    8,
    11,
    14,
    18,
    23,
    28,
    34,
    42,
    50,
    59,
    70,
    81,
    95,
    110,
    126,
    144,
    164,
    185,
    207,
    231,
    257,
    283,
    311,
    339,
    367,
    396,
    425,
    455,
    485,
    515,
    545,
    573,
    600,
    625,
    650,
    673,
    695,
    717,
    737,
    756,
    773,
    790,
    806,
    821,
    835,
    848,
    860,
    872,
    882,
    892,
    900,
    909,
    916,
    923,
    930,
    936,
    942,
    947,
    952,
    956,
    960,
    964,
    968,
    971,
    974,
    977,
    979,
};

// 12摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T12c[] = {
    3,
    4,
    5,
    7,
    9,
    12,
    16,
    20,
    25,
    31,
    38,
    45,
    54,
    64,
    76,
    89,
    103,
    119,
    136,
    155,
    175,
    197,
    221,
    247,
    273,
    301,
    329,
    358,
    387,
    417,
    446,
    477,
    506,
    536,
    565,
    593,
    619,
    644,
    668,
    691,
    712,
    733,
    752,
    770,
    787,
    803,
    819,
    832,
    846,
    858,
    870,
    881,
    890,
    900,
    907,
    915,
    923,
    929,
    935,
    941,
    946,
    951,
    956,
    960,
    964,
    967,
    971,
    974,
    976,
    979,
    981,
};

// 13摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T13c[] = {
    3,
    4,
    6,
    8,
    11,
    14,
    18,
    22,
    28,
    34,
    41,
    50,
    59,
    70,
    83,
    96,
    111,
    128,
    146,
    166,
    187,
    211,
    236,
    263,
    290,
    319,
    348,
    378,
    407,
    438,
    467,
    498,
    527,
    557,
    585,
    613,
    639,
    663,
    686,
    708,
    729,
    749,
    767,
    785,
    800,
    815,
    830,
    843,
    856,
    867,
    878,
    889,
    898,
    907,
    914,
    922,
    929,
    935,
    941,
    946,
    951,
    955,
    959,
    963,
    967,
    970,
    973,
    976,
    979,
    981,
    983,
};

// 14摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T14c[] = {
    4,
    5,
    7,
    9,
    12,
    16,
    20,
    25,
    31,
    38,
    45,
    54,
    65,
    77,
    90,
    105,
    121,
    138,
    157,
    178,
    200,
    225,
    252,
    279,
    308,
    338,
    368,
    398,
    428,
    460,
    489,
    519,
    548,
    577,
    605,
    632,
    658,
    681,
    703,
    725,
    745,
    764,
    781,
    798,
    813,
    827,
    842,
    853,
    865,
    876,
    887,
    897,
    905,
    915,
    921,
    928,
    934,
    940,
    945,
    950,
    955,
    959,
    963,
    966,
    970,
    973,
    976,
    978,
    981,
    983,
    985,
};

// 15摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T15c[] = {
    4,
    6,
    8,
    11,
    14,
    18,
    22,
    28,
    34,
    42,
    50,
    60,
    71,
    84,
    98,
    114,
    131,
    149,
    169,
    191,
    214,
    240,
    268,
    297,
    326,
    357,
    388,
    419,
    450,
    482,
    511,
    541,
    569,
    598,
    624,
    651,
    676,
    699,
    720,
    741,
    761,
    779,
    795,
    811,
    825,
    838,
    852,
    863,
    874,
    885,
    894,
    904,
    912,
    921,
    927,
    933,
    939,
    945,
    950,
    954,
    959,
    962,
    966,
    969,
    972,
    975,
    978,
    980,
    982,
    984,
    986,
};

// 16摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T16c[] = {
    5,
    7,
    9,
    12,
    15,
    20,
    25,
    31,
    38,
    46,
    55,
    65,
    78,
    91,
    107,
    123,
    141,
    161,
    182,
    205,
    229,
    255,
    284,
    313,
    344,
    375,
    406,
    438,
    468,
    500,
    529,
    559,
    587,
    616,
    642,
    669,
    693,
    715,
    736,
    756,
    774,
    792,
    807,
    822,
    835,
    848,
    861,
    872,
    882,
    892,
    901,
    910,
    918,
    926,
    931,
    938,
    943,
    948,
    953,
    957,
    961,
    965,
    968,
    972,
    975,
    977,
    980,
    982,
    984,
    986,
    988,
};

// 17摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T17c[] = {
    6,
    7,
    10,
    13,
    17,
    22,
    27,
    34,
    42,
    50,
    60,
    72,
    85,
    99,
    116,
    134,
    153,
    174,
    196,
    220,
    244,
    272,
    301,
    331,
    362,
    393,
    425,
    456,
    487,
    519,
    548,
    578,
    606,
    634,
    660,
    686,
    710,
    731,
    751,
    770,
    788,
    804,
    819,
    833,
    846,
    858,
    870,
    880,
    890,
    899,
    907,
    916,
    923,
    931,
    936,
    942,
    947,
    952,
    956,
    960,
    964,
    967,
    971,
    974,
    977,
    979,
    981,
    984,
    985,
    987,
    989,
};

// 18摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T18c[] = {
    6,
    8,
    11,
    15,
    19,
    24,
    31,
    38,
    46,
    56,
    67,
    79,
    93,
    109,
    127,
    146,
    166,
    188,
    211,
    235,
    261,
    289,
    319,
    350,
    380,
    412,
    444,
    475,
    506,
    537,
    567,
    596,
    624,
    652,
    678,
    703,
    726,
    747,
    766,
    784,
    801,
    817,
    831,
    844,
    855,
    867,
    878,
    887,
    897,
    905,
    913,
    921,
    928,
    935,
    940,
    946,
    951,
    955,
    959,
    963,
    967,
    970,
    973,
    976,
    978,
    981,
    983,
    985,
    987,
    989,
    990,
};

// 19摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T19c[] = {
    7,
    10,
    13,
    17,
    22,
    27,
    34,
    42,
    51,
    62,
    74,
    87,
    103,
    120,
    138,
    159,
    180,
    203,
    227,
    253,
    279,
    308,
    338,
    369,
    400,
    432,
    464,
    495,
    526,
    556,
    586,
    615,
    643,
    670,
    696,
    720,
    742,
    762,
    781,
    798,
    814,
    829,
    842,
    854,
    865,
    876,
    886,
    895,
    904,
    912,
    919,
    927,
    933,
    939,
    945,
    950,
    954,
    958,
    962,
    966,
    969,
    972,
    975,
    978,
    980,
    982,
    985,
    986,
    988,
    990,
    991,
};

// 20摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T20c[] = {
    8,
    11,
    15,
    19,
    25,
    31,
    39,
    47,
    57,
    69,
    82,
    97,
    114,
    132,
    152,
    173,
    196,
    220,
    245,
    271,
    299,
    329,
    359,
    390,
    421,
    452,
    484,
    515,
    545,
    576,
    605,
    634,
    662,
    689,
    714,
    737,
    758,
    777,
    795,
    812,
    827,
    840,
    853,
    864,
    874,
    884,
    893,
    902,
    910,
    918,
    925,
    931,
    938,
    943,
    949,
    953,
    958,
    961,
    965,
    968,
    971,
    974,
    977,
    980,
    982,
    984,
    986,
    988,
    989,
    991,
    992,
};

// 21摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T21c[] = {
    9,
    12,
    16,
    21,
    27,
    34,
    42,
    52,
    63,
    75,
    89,
    105,
    123,
    142,
    164,
    186,
    210,
    235,
    262,
    289,
    318,
    348,
    379,
    410,
    442,
    473,
    504,
    535,
    565,
    595,
    623,
    651,
    678,
    704,
    728,
    750,
    770,
    789,
    806,
    822,
    837,
    850,
    861,
    872,
    882,
    891,
    900,
    908,
    916,
    923,
    930,
    936,
    942,
    947,
    952,
    956,
    960,
    964,
    967,
    970,
    973,
    976,
    979,
    981,
    983,
    985,
    987,
    989,
    990,
    992,
    993,
};

// 22摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T22c[] = {
    11,
    14,
    18,
    24,
    30,
    38,
    47,
    57,
    69,
    82,
    97,
    114,
    133,
    154,
    176,
    200,
    226,
    252,
    279,
    308,
    337,
    369,
    400,
    432,
    464,
    494,
    526,
    555,
    585,
    614,
    641,
    668,
    694,
    719,
    742,
    763,
    783,
    801,
    818,
    833,
    846,
    859,
    870,
    880,
    889,
    898,
    907,
    914,
    921,
    928,
    934,
    940,
    946,
    951,
    955,
    959,
    963,
    967,
    970,
    973,
    975,
    978,
    980,
    983,
    985,
    987,
    988,
    990,
    991,
    993,
    994,
};

// 23摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T23c[] = {
    12,
    16,
    20,
    26,
    34,
    42,
    52,
    63,
    76,
    90,
    106,
    124,
    145,
    167,
    191,
    216,
    243,
    270,
    299,
    329,
    359,
    391,
    423,
    455,
    487,
    517,
    548,
    576,
    606,
    634,
    659,
    685,
    710,
    733,
    756,
    776,
    795,
    812,
    828,
    843,
    856,
    868,
    879,
    888,
    897,
    905,
    913,
    920,
    927,
    933,
    939,
    944,
    949,
    954,
    958,
    962,
    966,
    969,
    972,
    975,
    977,
    980,
    982,
    984,
    986,
    988,
    990,
    991,
    992,
    994,
    995,
};

// 24摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T24c[] = {
    14,
    18,
    23,
    30,
    38,
    48,
    59,
    70,
    84,
    99,
    116,
    136,
    157,
    181,
    207,
    234,
    262,
    291,
    320,
    352,
    382,
    415,
    447,
    480,
    512,
    540,
    571,
    597,
    627,
    654,
    678,
    703,
    726,
    748,
    769,
    789,
    806,
    823,
    839,
    853,
    865,
    876,
    887,
    895,
    904,
    912,
    919,
    926,
    932,
    937,
    943,
    948,
    953,
    957,
    961,
    965,
    968,
    971,
    974,
    977,
    979,
    981,
    984,
    986,
    987,
    989,
    991,
    992,
    993,
    995,
    996,
};

// 25摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T25c[] = {
    16,
    21,
    27,
    34,
    44,
    54,
    66,
    78,
    94,
    110,
    128,
    149,
    172,
    197,
    225,
    253,
    283,
    313,
    344,
    377,
    407,
    440,
    473,
    506,
    538,
    565,
    594,
    620,
    648,
    674,
    697,
    720,
    742,
    763,
    783,
    802,
    818,
    834,
    849,
    862,
    874,
    885,
    895,
    903,
    911,
    918,
    925,
    931,
    937,
    942,
    947,
    952,
    957,
    961,
    964,
    968,
    971,
    974,
    976,
    979,
    981,
    983,
    985,
    987,
    989,
    990,
    992,
    993,
    994,
    995,
    996,
};

// 26摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T26c[] = {
    18,
    23,
    29,
    38,
    48,
    59,
    72,
    85,
    102,
    119,
    138,
    161,
    185,
    212,
    241,
    270,
    301,
    332,
    363,
    397,
    427,
    461,
    493,
    526,
    557,
    584,
    613,
    638,
    665,
    690,
    712,
    735,
    756,
    776,
    795,
    813,
    829,
    844,
    858,
    871,
    882,
    892,
    901,
    909,
    916,
    923,
    930,
    936,
    941,
    946,
    951,
    955,
    959,
    963,
    967,
    970,
    973,
    975,
    978,
    980,
    982,
    984,
    986,
    988,
    990,
    991,
    992,
    994,
    995,
    996,
    997,
};

// 27摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T27c[] = {
    20,
    25,
    32,
    41,
    52,
    65,
    79,
    93,
    111,
    129,
    150,
    174,
    200,
    228,
    258,
    289,
    320,
    352,
    384,
    418,
    449,
    482,
    514,
    546,
    576,
    603,
    631,
    656,
    682,
    706,
    728,
    749,
    770,
    789,
    807,
    824,
    839,
    854,
    867,
    879,
    889,
    899,
    908,
    915,
    922,
    928,
    934,
    940,
    945,
    949,
    954,
    958,
    962,
    966,
    969,
    972,
    975,
    977,
    979,
    982,
    984,
    986,
    987,
    989,
    990,
    992,
    993,
    994,
    995,
    996,
    997,
};

// 28摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T28c[] = {
    22,
    28,
    36,
    46,
    58,
    72,
    87,
    102,
    121,
    141,
    163,
    189,
    216,
    246,
    277,
    309,
    342,
    374,
    407,
    440,
    472,
    505,
    536,
    567,
    597,
    623,
    650,
    674,
    699,
    722,
    743,
    764,
    783,
    802,
    819,
    835,
    850,
    863,
    876,
    887,
    897,
    905,
    914,
    921,
    927,
    933,
    939,
    944,
    949,
    953,
    957,
    961,
    965,
    968,
    971,
    974,
    976,
    979,
    981,
    983,
    985,
    987,
    988,
    990,
    991,
    993,
    994,
    995,
    996,
    997,
    998,
};

// 29摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T29c[] = {
    25,
    31,
    40,
    51,
    64,
    79,
    96,
    113,
    133,
    154,
    178,
    205,
    234,
    266,
    298,
    332,
    365,
    398,
    431,
    465,
    496,
    528,
    559,
    589,
    618,
    644,
    670,
    693,
    717,
    739,
    759,
    779,
    797,
    815,
    831,
    846,
    860,
    873,
    884,
    895,
    904,
    912,
    920,
    926,
    932,
    938,
    943,
    948,
    952,
    956,
    960,
    964,
    967,
    970,
    973,
    976,
    978,
    980,
    982,
    984,
    986,
    988,
    989,
    991,
    992,
    994,
    995,
    996,
    997,
    997,
    998,
};

// 30摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T30c[] = {
    28,
    36,
    45,
    58,
    72,
    89,
    107,
    126,
    147,
    170,
    196,
    224,
    255,
    288,
    322,
    357,
    391,
    425,
    458,
    491,
    523,
    554,
    583,
    612,
    639,
    665,
    690,
    713,
    735,
    755,
    775,
    793,
    811,
    828,
    843,
    857,
    870,
    882,
    893,
    902,
    911,
    919,
    925,
    932,
    937,
    943,
    947,
    952,
    956,
    960,
    963,
    967,
    970,
    972,
    975,
    978,
    980,
    982,
    984,
    986,
    987,
    989,
    990,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    999,
};

// 31摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T31c[] = {
    30,
    39,
    50,
    63,
    78,
    96,
    115,
    135,
    158,
    182,
    209,
    238,
    271,
    305,
    340,
    376,
    410,
    444,
    478,
    511,
    543,
    573,
    602,
    630,
    656,
    682,
    705,
    727,
    749,
    768,
    787,
    805,
    822,
    838,
    853,
    866,
    878,
    889,
    899,
    908,
    916,
    924,
    930,
    936,
    941,
    946,
    951,
    955,
    959,
    963,
    966,
    969,
    972,
    975,
    977,
    979,
    981,
    983,
    985,
    987,
    988,
    990,
    991,
    993,
    994,
    995,
    996,
    997,
    998,
    998,
    999,
};

// 32摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T32c[] = {
    34,
    43,
    54,
    69,
    85,
    104,
    124,
    146,
    169,
    195,
    223,
    254,
    288,
    323,
    359,
    395,
    431,
    465,
    499,
    532,
    564,
    594,
    622,
    649,
    674,
    698,
    721,
    742,
    763,
    782,
    800,
    817,
    833,
    848,
    862,
    874,
    886,
    896,
    906,
    914,
    922,
    929,
    935,
    941,
    946,
    950,
    954,
    958,
    962,
    965,
    968,
    971,
    974,
    977,
    979,
    981,
    983,
    985,
    986,
    988,
    989,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    999,
    1000,
};

// 33摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T33c[] = {
    37,
    47,
    60,
    75,
    93,
    114,
    135,
    158,
    183,
    210,
    239,
    271,
    306,
    343,
    379,
    417,
    453,
    488,
    522,
    554,
    586,
    615,
    642,
    668,
    692,
    715,
    737,
    757,
    777,
    795,
    812,
    828,
    844,
    858,
    871,
    883,
    893,
    903,
    912,
    920,
    927,
    934,
    940,
    945,
    949,
    954,
    958,
    962,
    965,
    968,
    971,
    974,
    976,
    979,
    981,
    983,
    984,
    986,
    988,
    989,
    990,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    999,
    999,
    1000,
};

// 34摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T34c[] = {
    41,
    53,
    66,
    83,
    103,
    124,
    147,
    172,
    198,
    226,
    257,
    290,
    327,
    365,
    402,
    440,
    476,
    511,
    546,
    578,
    609,
    637,
    664,
    687,
    711,
    732,
    753,
    772,
    791,
    809,
    825,
    840,
    855,
    868,
    880,
    891,
    901,
    910,
    919,
    926,
    933,
    939,
    944,
    949,
    953,
    957,
    961,
    965,
    968,
    971,
    973,
    976,
    978,
    980,
    982,
    984,
    986,
    987,
    989,
    990,
    991,
    993,
    994,
    995,
    996,
    997,
    998,
    998,
    999,
    1000,
    1001,
};

// 35摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T35c[] = {
    47,
    59,
    74,
    93,
    114,
    137,
    162,
    188,
    215,
    245,
    277,
    311,
    350,
    388,
    426,
    464,
    501,
    537,
    571,
    603,
    633,
    660,
    685,
    707,
    729,
    750,
    769,
    787,
    805,
    822,
    837,
    852,
    865,
    877,
    889,
    899,
    908,
    917,
    925,
    932,
    938,
    944,
    949,
    953,
    957,
    961,
    964,
    968,
    971,
    973,
    976,
    978,
    980,
    982,
    984,
    986,
    987,
    989,
    990,
    991,
    992,
    993,
    995,
    995,
    996,
    997,
    998,
    999,
    1000,
    1000,
    1001,
};

// 36摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T36c[] = {
    51,
    64,
    79,
    99,
    121,
    147,
    174,
    202,
    230,
    260,
    293,
    329,
    368,
    407,
    444,
    484,
    520,
    556,
    589,
    619,
    649,
    675,
    700,
    721,
    743,
    762,
    781,
    799,
    816,
    832,
    846,
    860,
    873,
    884,
    895,
    905,
    914,
    922,
    929,
    936,
    942,
    947,
    952,
    956,
    960,
    963,
    967,
    970,
    972,
    975,
    977,
    980,
    982,
    984,
    985,
    987,
    988,
    990,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    998,
    999,
    1000,
    1001,
    1001,
};

// 37摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T37c[] = {
    55,
    69,
    85,
    105,
    130,
    158,
    187,
    217,
    246,
    277,
    310,
    348,
    388,
    427,
    463,
    504,
    541,
    575,
    607,
    637,
    665,
    691,
    715,
    736,
    756,
    775,
    793,
    810,
    826,
    841,
    855,
    868,
    880,
    891,
    901,
    910,
    919,
    926,
    933,
    939,
    945,
    950,
    955,
    959,
    962,
    966,
    969,
    972,
    974,
    977,
    979,
    981,
    983,
    985,
    986,
    988,
    989,
    990,
    992,
    993,
    994,
    995,
    996,
    997,
    997,
    998,
    999,
    1000,
    1000,
    1001,
    1002,
};

// 38摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T38c[] = {
    61,
    75,
    92,
    113,
    139,
    171,
    203,
    234,
    264,
    295,
    329,
    370,
    409,
    448,
    483,
    525,
    562,
    595,
    626,
    654,
    682,
    707,
    730,
    750,
    769,
    787,
    805,
    821,
    837,
    851,
    864,
    877,
    888,
    898,
    907,
    916,
    924,
    931,
    937,
    943,
    948,
    953,
    957,
    961,
    965,
    968,
    971,
    974,
    976,
    978,
    981,
    982,
    984,
    986,
    987,
    989,
    990,
    991,
    993,
    994,
    995,
    996,
    996,
    997,
    998,
    999,
    999,
    1000,
    1001,
    1001,
    1002,
};

// 39摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T39c[] = {
    68,
    82,
    99,
    121,
    150,
    185,
    221,
    254,
    284,
    315,
    351,
    393,
    433,
    471,
    504,
    547,
    584,
    617,
    646,
    672,
    699,
    724,
    746,
    765,
    783,
    800,
    817,
    833,
    848,
    860,
    873,
    885,
    895,
    905,
    913,
    921,
    929,
    935,
    941,
    947,
    952,
    956,
    960,
    964,
    967,
    970,
    973,
    976,
    978,
    980,
    982,
    984,
    986,
    987,
    989,
    990,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    999,
    999,
    1000,
    1000,
    1001,
    1002,
    1002,
};

// 40摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T40c[] = {
    76,
    91,
    108,
    130,
    162,
    202,
    241,
    277,
    307,
    337,
    374,
    419,
    458,
    496,
    527,
    571,
    608,
    639,
    666,
    691,
    716,
    740,
    761,
    779,
    797,
    813,
    829,
    844,
    858,
    870,
    882,
    893,
    903,
    911,
    919,
    927,
    934,
    940,
    945,
    950,
    955,
    959,
    963,
    966,
    969,
    972,
    975,
    977,
    980,
    982,
    984,
    985,
    987,
    988,
    990,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    998,
    999,
    1000,
    1000,
    1001,
    1001,
    1002,
    1002,
};

// 41摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T41c[] = {
    82,
    98,
    117,
    141,
    173,
    214,
    253,
    290,
    322,
    353,
    391,
    435,
    475,
    513,
    544,
    587,
    623,
    653,
    680,
    704,
    729,
    752,
    772,
    790,
    807,
    823,
    838,
    852,
    866,
    877,
    888,
    899,
    908,
    916,
    924,
    931,
    937,
    943,
    948,
    953,
    958,
    962,
    965,
    968,
    971,
    974,
    977,
    979,
    981,
    983,
    985,
    986,
    988,
    989,
    990,
    992,
    993,
    994,
    995,
    996,
    996,
    997,
    998,
    999,
    999,
    1000,
    1001,
    1001,
    1002,
    1002,
    1003,
};

// 42摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T42c[] = {
    90,
    107,
    128,
    153,
    186,
    227,
    266,
    304,
    338,
    371,
    410,
    453,
    493,
    531,
    563,
    603,
    638,
    667,
    693,
    717,
    741,
    764,
    783,
    801,
    817,
    832,
    847,
    860,
    873,
    884,
    895,
    904,
    913,
    921,
    928,
    935,
    941,
    946,
    951,
    956,
    960,
    964,
    967,
    970,
    973,
    976,
    978,
    980,
    982,
    984,
    986,
    987,
    989,
    990,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    998,
    999,
    1000,
    1000,
    1001,
    1001,
    1002,
    1002,
    1003,
};

// 43摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T43c[] = {
    98,
    118,
    140,
    167,
    201,
    241,
    281,
    319,
    355,
    390,
    429,
    472,
    511,
    549,
    582,
    620,
    653,
    682,
    707,
    731,
    754,
    775,
    794,
    811,
    827,
    842,
    856,
    869,
    880,
    891,
    901,
    910,
    918,
    926,
    932,
    939,
    944,
    950,
    954,
    959,
    963,
    966,
    969,
    972,
    975,
    978,
    980,
    982,
    984,
    985,
    987,
    988,
    990,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    997,
    998,
    999,
    1000,
    1000,
    1001,
    1001,
    1002,
    1002,
    1003,
    1003,
};

// 44摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T44c[] = {
    108,
    130,
    155,
    184,
    218,
    257,
    296,
    335,
    373,
    411,
    450,
    492,
    531,
    568,
    602,
    637,
    669,
    697,
    722,
    745,
    767,
    787,
    805,
    822,
    837,
    851,
    865,
    877,
    888,
    898,
    907,
    916,
    923,
    930,
    937,
    943,
    948,
    953,
    957,
    961,
    965,
    968,
    971,
    974,
    977,
    979,
    981,
    983,
    985,
    987,
    988,
    989,
    991,
    992,
    993,
    994,
    995,
    996,
    996,
    997,
    998,
    999,
    999,
    1000,
    1000,
    1001,
    1002,
    1002,
    1003,
    1003,
    1003,
};

// 45摄氏度下，湿度表
GCE_CONST UI16 Hum_list_T45c[] = {
    121,
    144,
    172,
    204,
    238,
    275,
    313,
    352,
    393,
    433,
    473,
    513,
    552,
    588,
    623,
    655,
    685,
    712,
    736,
    759,
    780,
    799,
    817,
    833,
    847,
    861,
    873,
    885,
    895,
    905,
    913,
    921,
    928,
    935,
    941,
    946,
    951,
    956,
    960,
    964,
    967,
    970,
    973,
    976,
    979,
    981,
    983,
    985,
    986,
    988,
    989,
    990,
    991,
    992,
    993,
    994,
    995,
    996,
    997,
    998,
    998,
    999,
    1000,
    1000,
    1001,
    1001,
    1002,
    1002,
    1003,
    1003,
    1004,
};

GCE_CONST UI16 *hum_tab[] = {
    Hum_list_T5c,
    Hum_list_T6c,
    Hum_list_T7c,
    Hum_list_T8c,
    Hum_list_T9c,
    Hum_list_T10c,
    Hum_list_T11c,
    Hum_list_T12c,
    Hum_list_T13c,
    Hum_list_T14c,
    Hum_list_T15c,
    Hum_list_T16c,
    Hum_list_T17c,
    Hum_list_T18c,
    Hum_list_T19c,
    Hum_list_T20c,
    Hum_list_T21c,
    Hum_list_T22c,
    Hum_list_T23c,
    Hum_list_T24c,
    Hum_list_T25c,
    Hum_list_T26c,
    Hum_list_T27c,
    Hum_list_T28c,
    Hum_list_T29c,
    Hum_list_T30c,
    Hum_list_T31c,
    Hum_list_T32c,
    Hum_list_T33c,
    Hum_list_T34c,
    Hum_list_T35c,
    Hum_list_T36c,
    Hum_list_T37c,
    Hum_list_T38c,
    Hum_list_T39c,
    Hum_list_T40c,
    Hum_list_T41c,
    Hum_list_T42c,
    Hum_list_T43c,
    Hum_list_T44c,
    Hum_list_T45c,
};

#endif
