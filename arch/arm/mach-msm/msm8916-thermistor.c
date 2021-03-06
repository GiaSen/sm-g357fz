/*
 * msm8916-thermistor.c - thermistor for MSM8916 projects
 *
 * Copyright (C) 2014 Samsung Electronics
 * SangYoung Son <hello.son@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <mach/msm8916-thermistor.h>
#include <mach/sec_thermistor.h>

#if defined(CONFIG_SEC_THERMISTOR)
#if defined(CONFIG_SEC_FORTUNA_PROJECT)
static struct sec_therm_adc_table temper_table_ap[] = {
	{25954, 900},
	{25973, 890},
	{25992, 880},
	{26011, 870},
	{26030, 860},
	{26048, 850},
	{26101, 840},
	{26154, 830},
	{26207, 820},
	{26260, 810},
	{26315, 800},
	{26371, 790},
	{26427, 780},
	{26483, 770},
	{26540, 760},
	{26598, 750},
	{26650, 740},
	{26702, 730},
	{26754, 720},
	{26807, 710},
	{26861, 700},
	{26950, 690},
	{27039, 680},
	{27128, 670},
	{27217, 660},
	{27306, 650},
	{27433, 640},
	{27560, 630},
	{27687, 620},
	{27814, 610},
	{27943, 600},
	{28043, 590},
	{28143, 580},
	{28243, 570},
	{28343, 560},
	{28446, 550},
	{28579, 540},
	{28712, 530},
	{28845, 520},
	{28978, 510},
	{29112, 500},
	{29261, 490},
	{29410, 480},
	{29559, 470},
	{29708, 460},
	{29859, 450},
	{30005, 440},
	{30151, 430},
	{30297, 420},
	{30443, 410},
	{30590, 400},
	{30779, 390},
	{30968, 380},
	{31157, 370},
	{31347, 360},
	{31538, 350},
	{31742, 340},
	{31946, 330},
	{32150, 320},
	{32354, 310},
	{32557, 300},
	{32743, 290},
	{32929, 280},
	{33115, 270},
	{33301, 260},
	{33487, 250},
	{33681, 240},
	{33875, 230},
	{34069, 220},
	{34264, 210},
	{34460, 200},
	{34689, 190},
	{34918, 180},
	{35147, 170},
	{35376, 160},
	{35605, 150},
	{35819, 140},
	{36033, 130},
	{36247, 120},
	{36462, 110},
	{36677, 100},
	{36888, 90},
	{37099, 80},
	{37310, 70},
	{37521, 60},
	{37732, 50},
	{37924, 40},
	{38116, 30},
	{38308, 20},
	{38500, 10},
	{38693, 0},
	{38880, -10},
	{39067, -20},
	{39254, -30},
	{39441, -40},
	{39629, -50},
	{39744, -60},
	{39859, -70},
	{39974, -80},
	{40089, -90},
	{40205, -100},
	{40317, -110},
	{40429, -120},
	{40541, -130},
	{40653, -140},
	{40765, -150},
	{40878, -160},
	{40991, -170},
	{41104, -180},
	{41218, -190},
	{41333, -200},
};
#else
#if defined(CONFIG_SEC_ROSSA_PROJECT) || defined(CONFIG_SEC_ROSSA_AUS_PROJECT)
static struct sec_therm_adc_table temper_table_ap[] = {
	{25950,	900},
	{25995,	890},
	{26039,	880},
	{26084,	870},
	{26128,	860},
	{26173,	850},
	{26201,	840},
	{26230,	830},
	{26258,	820},
	{26287,	810},
	{26315,	800},
	{26401,	790},
	{26488,	780},
	{26574,	770},
	{26661,	760},
	{26747,	750},
	{26821,	740},
	{26895,	730},
	{26969,	720},
	{27043,	710},
	{27117,	700},
	{27200,	690},
	{27284,	680},
	{27367,	670},
	{27450,	660},
	{27534,	650},
	{27641,	640},
	{27749,	630},
	{27857,	620},
	{27965,	610},
	{28073,	600},
	{28171,	590},
	{28270,	580},
	{28369,	570},
	{28468,	560},
	{28567,	550},
	{28698,	540},
	{28830,	530},
	{28962,	520},
	{29094,	510},
	{29225,	500},
	{29380,	490},
	{29535,	480},
	{29690,	470},
	{29884,	460},
	{29999,	450},
	{30184,	440},
	{30369,	430},
	{30553,	420},
	{30738,	410},
	{30923,	400},
	{31104,	390},
	{31284,	380},
	{31465,	370},
	{31646,	360},
	{31827,	350},
	{32024,	340},
	{32221,	330},
	{32418,	320},
	{32616,	310},
	{32813,	300},
	{33017,	290},
	{33221,	280},
	{33424,	270},
	{33628,	260},
	{33832,	250},
	{34001,	240},
	{34252,	230},
	{34502,	220},
	{34753,	210},
	{34949,	200},
	{35168,	190},
	{35387,	180},
	{35607,	170},
	{35826,	160},
	{36045,	150},
	{36294,	140},
	{36543,	130},
	{36793,	120},
	{37042,	110},
	{37291,	100},
	{37451,	90},
	{37612,	80},
	{37772,	70},
	{37933,	60},
	{38093,	50},
	{38262,	40},
	{38431,	30},
	{38599,	20},
	{38768,	10},
	{38937,	0},
	{39100,	-10},
	{39263,	-20},
	{39426,	-30},
	{39590,	-40},
	{39753,	-50},
	{39888,	-60},
	{40022,	-70},
	{40157,	-80},
	{40291,	-90},
	{40426,	-100},
	{40549,	-110},
	{40673,	-120},
	{40796,	-130},
	{40920,	-140},
	{41043,	-150},
	{41141,	-160},
	{41240,	-170},
	{41338,	-180},
	{41436,	-190},
	{41535,	-200},
};

#else
/* default table from KLTE(MSM8974Pro) project */
static struct sec_therm_adc_table temper_table_ap[] = {
	{25954,	900},
	{26005,	890},
	{26052,	880},
	{26105,	870},
	{26151,	860},
	{26207,	850},
	{26253,	840},
	{26302,	830},
	{26354,	820},
	{26405,	810},
	{26454,	800},
	{26503,	790},
	{26554,	780},
	{26602,	770},
	{26657,	760},
	{26691,	750},
	{26757,	740},
	{26823,	730},
	{26889,	720},
	{26955,	710},
	{27020,	700},
	{27081,	690},
	{27142,	680},
	{27203,	670},
	{27264,	660},
	{27327,	650},
	{27442,	640},
	{27557,	630},
	{27672,	620},
	{27787,	610},
	{27902,	600},
	{28004,	590},
	{28106,	580},
	{28208,	570},
	{28310,	560},
	{28415,	550},
	{28608,	540},
	{28801,	530},
	{28995,	520},
	{28944,	510},
	{28893,	500},
	{29148,	490},
	{29347,	480},
	{29546,	470},
	{29746,	460},
	{29911,	450},
	{30076,	440},
	{30242,	430},
	{30490,	420},
	{30738,	410},
	{30986,	400},
	{31101,	390},
	{31216,	380},
	{31331,	370},
	{31446,	360},
	{31561,	350},
	{31768,	340},
	{31975,	330},
	{32182,	320},
	{32389,	310},
	{32596,	300},
	{32962,	290},
	{32974,	280},
	{32986,	270},
	{33744,	260},
	{33971,	250},
	{34187,	240},
	{34403,	230},
	{34620,	220},
	{34836,	210},
	{35052,	200},
	{35261,	190},
	{35470,	180},
	{35679,	170},
	{35888,	160},
	{36098,	150},
	{36317,	140},
	{36537,	130},
	{36756,	120},
	{36976,	110},
	{37195,	100},
	{37413,	90},
	{37630,	80},
	{37848,	70},
	{38065,	60},
	{38282,	50},
	{38458,	40},
	{38635,	30},
	{38811,	20},
	{38987,	10},
	{39163,	0},
	{39317,	-10},
	{39470,	-20},
	{39624,	-30},
	{39777,	-40},
	{39931,	-50},
	{40065,	-60},
	{40199,	-70},
	{40333,	-80},
	{40467,	-90},
	{40601,	-100},
	{40728,	-110},
	{40856,	-120},
	{40983,	-130},
	{41110,	-140},
	{41237,	-150},
	{41307,	-160},
	{41378,	-170},
	{41448,	-180},
	{41518,	-190},
	{41588,	-200},
};
#endif
#endif

static struct sec_therm_platform_data sec_therm_pdata = {
	.adc_arr_size	= ARRAY_SIZE(temper_table_ap),
	.adc_table	= temper_table_ap,
	.polling_interval = 30 * 1000, /* msecs */
	.get_siop_level = NULL,
	.no_polling	= 1,
};


struct platform_device sec_device_thermistor = {
	.name = "sec-thermistor",
	.id = -1,
	.dev.platform_data = &sec_therm_pdata,
};

struct sec_therm_platform_data * fill_therm_pdata(struct platform_device *pdev)
{
	pdev->dev.platform_data = &sec_therm_pdata;
	pdev->id = -1;

	return &sec_therm_pdata;
}
#endif
