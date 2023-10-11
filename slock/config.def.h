/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1C1B19",     /* after initialization */
	[INPUT] =  "#FBB829",   /* during input */
	[FAILED] = "#EF2F27",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
