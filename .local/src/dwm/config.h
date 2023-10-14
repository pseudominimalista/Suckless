/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono:pixelsize=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrainsMono:pixelsize=10:antialias=true:autohint=true";
static const char col_1[]       = "#2e3440";
static const char col_2[]       = "#d8dee9";
static const char col_3[]       = "#3b4252";
static const char col_4[]        = "#5e81ac";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_2, col_1, col_3 },
	[SchemeSel]  = { col_2, col_3,  col_4  },
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "st-256color",      "st-256color",     NULL,           0,         0,          1,           0,        -1 },
	{ "sent",    "sent",     NULL,           0,         0,          0,           0,      -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	 { "[]=",      tile },    /* first entry is default */
	 { "><>",      NULL },    /* no layout function means floating behavior */
	 { "[M]",      monocle },
};

/* key definitions */
// #define MODKEY Mod1Mask // Alt //
#define MODKEY Mod4Mask // Super //
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|Mod1Mask,  KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *dfm[] = { "dfm", NULL };
static const char *todo[] = { "todo", NULL };
static const char *wifi[] = { "wifi", NULL };
static const char *web[] = { "librewolf", NULL };
static const char *scr[] = { "scr", NULL };
static const char *alsa[] = { "st", "alsamixer", NULL };
static const char *cmus[] = { "st", "cmus", NULL };
static const char *pfm[] = { "pfm", NULL };
static const char *mutevol[] = { "amixer", "set", "Master", "toggle", NULL };
static const char *decvol[] = { "amixer", "set", "Master", "5%-", NULL };
static const char *incvol[] = { "amixer", "set", "Master", "5%+",  NULL };
static const char *inc[] = { "brightnessctl", "set", "3%+", NULL };
static const char *dec[] = { "brightnessctl", "set", "3%-", NULL };
static const char *cmu[] = { "cmus-remote", "-u", NULL };
static const char *cms[] = { "cmus-remote", "-s", NULL };
static const char *cmr[] = { "cmus-remote", "-r", NULL };
static const char *cmn[] = { "cmus-remote", "-n", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_e,       spawn,          {.v = dfm } },
	{ MODKEY,                       XK_d,       spawn,          {.v = todo } },
	{ MODKEY,                       XK_y,       spawn,          {.v = wifi } },
	{ MODKEY,                       XK_w,       spawn,          {.v = web } },
	{ MODKEY,                       XK_a,       spawn,          {.v = alsa } },
	{ MODKEY,                       XK_c,       spawn,          {.v = cmus } },
	{ MODKEY,                       XK_Delete,  spawn,          {.v = pfm } },
	{ MODKEY,                       XK_F1, 	    spawn,          {.v = mutevol } },
	{ MODKEY,           	        XK_F2,      spawn,          {.v = decvol } },
	{ MODKEY,           	        XK_F3,      spawn,          {.v = incvol } },
	{ MODKEY,           	        XK_F11,     spawn,          {.v = dec } },
	{ MODKEY,           	        XK_F12,     spawn,          {.v = inc } },
	{ 0,                            XK_Print,   spawn,          {.v = scr } },
	{ 0,                            0x1008ff12, spawn,          {.v = mutevol } },
	{ 0,           	                0x1008ff11, spawn,          {.v = decvol } },
	{ 0,           	                0x1008ff13, spawn,          {.v = incvol } },
	{ 0,           	                0x1008ff03, spawn,          {.v = dec } },
	{ 0,           	                0x1008ff02, spawn,          {.v = inc } },
	{ 0,           	                0x1008ff14, spawn,          {.v = cmu } },
	{ 0,           	                0x1008ff15, spawn,          {.v = cms } },
	{ 0,           	                0x1008ff16, spawn,          {.v = cmr } },
	{ 0,           	                0x1008ff17, spawn,          {.v = cmn } },
	
	{ MODKEY,                       XK_x,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_z,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } }, // Abrir dmenu //
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod1Mask,              XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,             			XK_q,      killclient,     {0} }, // Fechar janelas //
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // Tilling //
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, // Floating //
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, // Monocle //
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|Mod1Mask,              XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|Mod1Mask,              XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ ControlMask|Mod1Mask,         XK_q,      quit,           {0} },
};
/* button definitions */
	/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
	static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

